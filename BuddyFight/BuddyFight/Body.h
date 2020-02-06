#pragma once
#include "PhysicsEntity.h"



class Body :
    public PhysicsEntity
{
public:
    Body(Texture* texture, float x = 0.0f, float y = 0.0f);
};