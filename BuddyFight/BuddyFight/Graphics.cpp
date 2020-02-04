#include "Graphics.h"





Graphics* Graphics::instance = NULL;
bool Graphics::initialized = false;

Graphics::Graphics() :
	renderer(NULL)
{
	initialized = Init();
}

Graphics::~Graphics()
{
	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);
}

bool Graphics::Init()
{
	if (SDL_InitSubSystem(SDL_INIT_VIDEO) < 0)
	{
		cerr << "Unable to initialize SDL! SDL Error: " << SDL_GetError() << endl;
		return false;
	}

	window = SDL_CreateWindow(
		"BuddyFight",
		SDL_WINDOWPOS_UNDEFINED,
		SDL_WINDOWPOS_UNDEFINED,
		SCREEN_WIDTH,
		SCREEN_HEIGHT,
		SDL_WINDOW_SHOWN);
	if (window == NULL)
	{
		cerr << "Unable to create window! SDL Error: " << SDL_GetError() << endl;
		return false;
	}

	renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
	if (renderer == NULL)
	{
		cerr << "Unable to create renderer! SDL Error: " << SDL_GetError() << endl;
		return false;
	}

	if (TTF_Init() == -1)
	{
		std::cerr << "Unable to initialize SDL_TTF! TTF Error: " << TTF_GetError() << std::endl;
	}

	return true;
}

void Graphics::Release()
{
	delete instance;
	instance = NULL;
}

Graphics* Graphics::GetInstance()
{
	if (instance == NULL)
		instance = new Graphics();

	return instance;
}

bool Graphics::IsInitialized()
{
	return initialized;
}

SDL_Texture* Graphics::LoadTexture(string path)
{
	SDL_Texture* texture = NULL;

	SDL_Surface* surface = IMG_Load(path.c_str());

	if (surface == NULL)
	{
		cerr << "Unable to load " << path << ", IMG Error: " << IMG_GetError() << endl;
		return NULL;
	}

	texture = SDL_CreateTextureFromSurface(renderer, surface);
	if (texture == NULL)
	{
		cerr << "Unable to create texture from surface! IMG Error: " << IMG_GetError() << endl;
		return NULL;
	}

	SDL_FreeSurface(surface);
	return texture;
}

SDL_Texture* Graphics::CreateTextTexture(TTF_Font* font, string text, SDL_Color colour)
{
	SDL_Surface* surface = TTF_RenderText_Solid(font, text.c_str(), colour);
	if (surface == NULL)
	{
		cerr << "CreateTextTexture:: TTF_RenderText_Solid Error: " << TTF_GetError() << endl;
		return NULL;
	}

	SDL_Texture* texture = SDL_CreateTextureFromSurface(renderer, surface);
	if (texture == NULL)
	{
		cerr << "CreateTextTexture:: SDL_CreateTextureFromSurface Error: " << SDL_GetError() << endl;
		return NULL;
	}

	SDL_FreeSurface(surface);
	return texture;
}

void Graphics::ClearBackBuffer()
{
	SDL_RenderClear(renderer);
}

void Graphics::Render()
{
	SDL_RenderPresent(renderer);
}

void Graphics::DrawTexture(SDL_Texture* texture, SDL_Rect* srcRect, SDL_Rect* dstRect, float angle, SDL_RendererFlip flip)
{
	SDL_RenderCopyEx(renderer, texture, srcRect, dstRect, angle, NULL, flip);
}