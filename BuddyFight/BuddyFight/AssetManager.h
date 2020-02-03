#pragma once
#include "Graphics.h"
#include "SDL_mixer.h"
#include <sstream>
#include <map>





class AssetManager
{
private:

	static AssetManager* instance;

	std::map<std::string, SDL_Texture*> textures;
	std::map<SDL_Texture*, unsigned> textureRefCount;
	std::map<std::string, TTF_Font*> fonts;
	std::map<std::string, SDL_Texture*> text;
	std::map<std::string, Mix_Music*> music;
	std::map<std::string, Mix_Chunk*> sFX;
	std::map<Mix_Music*, unsigned> musicRefCount;
	std::map<Mix_Chunk*, unsigned> sFXRefCount;

public:

	static AssetManager* GetInstance();
	static void Release();

	SDL_Texture* GetText(string text, string filename, int size, SDL_Color colour, bool managed = false);

	Mix_Music* GetMusic(string filename, bool managed = false);
	Mix_Chunk* GetSFX(string filename, bool managed = false);

	SDL_Texture* GetTexture(string filename, bool managed = false);
	void DestroyTexture(SDL_Texture* texture);
	void DestroyMusic(Mix_Music* music);
	void DestroySFX(Mix_Chunk* sfx);

private:

	~AssetManager();

	TTF_Font* GetFont(string filename, int size);
};

