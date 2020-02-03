#include "LevelPlatforms.h"

LevelPlatforms::LevelPlatforms() :
	Entity(new Texture("Platform.png", 0, 0, 300, 176), Graphics::SCREEN_WIDTH * 0.5f, Graphics::SCREEN_HEIGHT * 0.95f)
{
	EntityPool* pool = EntityPool::GetInstance();
}

LevelPlatforms::~LevelPlatforms()
{}
