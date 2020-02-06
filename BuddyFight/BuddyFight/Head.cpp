#include "Head.h"



Head::Head(Texture* texture, float x, float y)
	: PhysicsEntity(texture, x, y)
{
	mask = HEAD;
	shape = CIRCLE;
	grounded = true;
}