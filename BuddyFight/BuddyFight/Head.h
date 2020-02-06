#pragma once
#include "PhysicsEntity.h"



class Head :
	public PhysicsEntity
{
public:
	Head(Texture* texture, float x = 0.0f, float y = 0.0f);
};