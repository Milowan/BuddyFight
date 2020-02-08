#include "Fist.h"





Fist::Fist(Texture* texture, float x, float y) :
	PhysicsEntity(texture, x, y)
{
	SetMask(FIST);
	SetShape(CIRCLE);
	grounded = true;
}

void Fist::SetPunching(bool isPunching)
{
	punching = isPunching;
}

bool Fist::GetPunching()
{
	return punching;
}