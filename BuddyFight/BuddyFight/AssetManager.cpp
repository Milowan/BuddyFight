#include "AssetManager.h"





AssetManager* AssetManager::instance = NULL;

AssetManager* AssetManager::GetInstance()
{
	if (instance == NULL)
		instance = new AssetManager();

	return instance;
}

void AssetManager::Release()
{
	delete instance;
	instance = NULL;
}

AssetManager::~AssetManager()
{
	for (auto tex : textures)
	{
		if (tex.second != NULL)
			SDL_DestroyTexture(tex.second);
	}

	textures.clear();
}

TTF_Font* AssetManager::GetFont(string filename, int size)
{
	string fullPath = SDL_GetBasePath();
	fullPath.append("Assets/" + filename);

	stringstream ss;
	ss << size;
	string key = fullPath + ss.str();

	if (fonts[key] == NULL)
	{
		fonts[key] = TTF_OpenFont(fullPath.c_str(), size);

		if (fonts[key] == NULL)
			cerr << "Unable to load font " << filename << "! TTF Error: " << TTF_GetError() << endl;
	}

	return fonts[key];
}

SDL_Texture* AssetManager::GetText(string text, string filename, int size, SDL_Color colour, bool managed)
{
	stringstream ss;
	ss << size << (int)colour.r << (int)colour.g << (int)colour.b;
	string key = text + filename + ss.str();

	if (this->text[key] == NULL)
	{
		TTF_Font* font = GetFont(filename, size);
		this->text[key] = Graphics::GetInstance()->CreateTextTexture(font, text, colour);
	}

	if (this->text[key] != NULL && managed)
	{
		textureRefCount[this->text[key]] += 1;
	}

	return this->text[key];
}

Mix_Music* AssetManager::GetMusic(string filename, bool managed)
{
	string fullPath = SDL_GetBasePath();
	fullPath.append("Assets/" + filename);

	if (music[fullPath] == NULL)
		music[fullPath] = Mix_LoadMUS(fullPath.c_str());

	if (music[fullPath] == NULL)
		cerr << "Unable to load music " << filename << "! Mix Error: " << Mix_GetError() << endl;
	else if (managed)
		musicRefCount[music[fullPath]] += 1;

	return music[fullPath];
}

Mix_Chunk* AssetManager::GetSFX(string filename, bool managed)
{
	string fullPath = SDL_GetBasePath();
	fullPath.append("Assets/" + filename);

	if (sFX[fullPath] == NULL)
		sFX[fullPath] = Mix_LoadWAV(fullPath.c_str());

	if (sFX[fullPath] == NULL)
		cerr << "Unasble to load SFX " << filename << "! Mix_Error: " << Mix_GetError() << endl;
	else if (managed)
		sFXRefCount[sFX[fullPath]] += 1;

	return sFX[fullPath];
}

SDL_Texture* AssetManager::GetTexture(std::string filename, bool managed)
{
	std::string fullPath = SDL_GetBasePath();
	fullPath.append("Assets/" + filename);

	if (textures[fullPath] == NULL)
		textures[fullPath] = Graphics::GetInstance()->LoadTexture(fullPath);
	if (textures[fullPath] != NULL && managed)
		textureRefCount[textures[fullPath]] += 1;

	return textures[fullPath];
}

void AssetManager::DestroyTexture(SDL_Texture* texture)
{
	if (textureRefCount.find(texture) != textureRefCount.end())
	{
		textureRefCount[texture] -= 1;
		if (textureRefCount[texture] == 0)
		{
			for (auto elem : textures)
			{
				if (elem.second == texture)
				{
					SDL_DestroyTexture(elem.second);
					textures.erase(elem.first);
					break;
				}
			}

			for (auto elem : text)
			{
				if (elem.second == texture)
				{
					SDL_DestroyTexture(elem.second);
					text.erase(elem.first);
					break;
				}
			}
		}
	}
}