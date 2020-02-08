#include "Head.h"



Head::Head(Texture* texture, float x, float y)
	: PhysicsEntity(texture, x, y)
{
	SetMask(HEAD);
	SetShape(CIRCLE);
	grounded = true;
}