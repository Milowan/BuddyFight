#include "Platform.h"




Platform::Platform(Texture* texture, float x, float y) : 
	Entity(texture,x,y)
{
	EntityPool* pool = EntityPool::GetInstance();
}

Platform::~Platform()
{
}
