#pragma once
#include "PhysicsEntity.h"





class Fist :
	public PhysicsEntity
{
private:

	bool punching;

public:

	Fist(Texture* texture, float x = 0.0f, float y = 0.0f);

	void SetPunching(bool isPunching);
	bool GetPunching();

};

