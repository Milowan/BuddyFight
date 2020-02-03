#include "Texture.h"





Texture::Texture(std::string filename, bool managed)
{
	graphics = Graphics::GetInstance();
	texture = AssetManager::GetInstance()->GetTexture(filename, managed);

	SDL_QueryTexture(texture, NULL, NULL, &width, &height);

	clipped = false;
	destinationRect.w = width;
	destinationRect.h = height;
}

Texture::Texture(std::string filename, int x, int y, int w, int h, bool managed)
{
	graphics = Graphics::GetInstance();
	texture = AssetManager::GetInstance()->GetTexture(filename, managed);

	width = w;
	height = h;

	clipped = true;
	destinationRect.w = width;
	destinationRect.h = height;

	sourceRect.x = x;
	sourceRect.y = y;
	sourceRect.w = width;
	sourceRect.h = height;
}

Texture::Texture(std::string text, std::string fontPath, int size, SDL_Color colour, bool managed)
{
	graphics = Graphics::GetInstance();
	texture = AssetManager::GetInstance()->GetText(text, fontPath, size, colour, managed);

	clipped = false;

	SDL_QueryTexture(texture, NULL, NULL, &width, &height);

	destinationRect.w = width;
	destinationRect.h = height;
}

Texture::~Texture()
{
	AssetManager::GetInstance()->DestroyTexture(texture);
	texture = NULL;
	graphics = NULL;
}

Vector2 Texture::ScaledDimensions(Vector2 scale)
{
	scale.x *= width;
	scale.y *= height;

	return scale;
}

void Texture::Render(Vector2 position, Vector2 scale, float rotation)
{
	destinationRect.x = (int)(position.x - width * 0.5f);
	destinationRect.y = (int)(position.y - height * 0.5f);
	destinationRect.w = (int)(width * scale.x);
	destinationRect.h = (int)(height * scale.y);

	graphics->DrawTexture(texture, clipped ? &sourceRect : NULL, &destinationRect, rotation);
}

int Texture::GetWidth()
{
	return width;
}

int Texture::GetHeight()
{
	return height;
}

void Texture::SetWidth(int w)
{
	width = w;
}

void Texture::SetHeight(int h)
{
	height = h;
}