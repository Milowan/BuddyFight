#pragma once
#include "Entity.h"
#include "Timer.h"


#define GRAVITY -V2UP * 0.98f





class PhysicsEntity :
	public Entity
{
protected:

	Vector2 acceleration;
	bool grounded;

public:

	PhysicsEntity(Texture* nTexture, float x = 0.0f, float y = 0.0f);

	void AddForce(Vector2 force);
	void Accelerate();

	void UpdatePhysics();
};

