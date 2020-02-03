#pragma once
#include "MathHelper.h"
#include "AssetManager.h"




class Texture
{
protected:

	SDL_Texture* texture;
	Graphics* graphics;

	int width;
	int height;

	bool clipped;
	SDL_Rect sourceRect;
	SDL_Rect destinationRect;

public:

	Texture(string filename, bool managed = false);
	Texture(string filename, int x, int y, int w, int h, bool managed = false);
	Texture(string text, string fontPath, int size, SDL_Color colour, bool managed = false);
	~Texture();

	Vector2 ScaledDimensions(Vector2 scale);

	void Render(Vector2 position, Vector2 scale = V2ONE, float rotation = 0.0f);

	int GetWidth();
	int GetHeight();

	void SetWidth(int w);
	void SetHeight(int h);

	virtual void Update() {};
};

