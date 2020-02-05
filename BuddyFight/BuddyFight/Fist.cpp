#include "Fist.h"





Fist::Fist(Texture* texture, float x, float y) :
	PhysicsEntity(texture, x, y)
{
	mask = FIST;
	shape = CIRCLE;
}

void Fist::SetPunching(bool isPunching)
{
	punching = isPunching;
}

bool Fist::GetPunching()
{
	return punching;
}