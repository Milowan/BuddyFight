#pragma once
#include <iostream>
#include <SDL_ttf.h>
#include <SDL_image.h>


using namespace std;


class Graphics
{
private:

	static Graphics* instance;
	static bool initialized;
	SDL_Window* window;
	SDL_Renderer* renderer;

public:

	static const short SCREEN_WIDTH = 1152;
	static const short SCREEN_HEIGHT = 576;

private:

	Graphics();
	~Graphics();

	bool Init();

public:

	static Graphics* GetInstance();
	static void Release();
	static bool IsInitialized();

	SDL_Texture* LoadTexture(string path);
	SDL_Texture* CreateTextTexture(TTF_Font* font, string text, SDL_Color colour);

	void ClearBackBuffer();
	void Render();
	void DrawTexture(SDL_Texture* texture, SDL_Rect* srcRect = NULL, SDL_Rect* dstRect = NULL, float angle = 0.0f, SDL_RendererFlip = SDL_FLIP_NONE);
};

