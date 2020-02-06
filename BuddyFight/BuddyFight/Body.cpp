#include "Body.h"


Body::Body(Texture* texture, float x, float y)
	: PhysicsEntity(texture, x, y)
{
	mask = BODY;
	shape = CIRCLE;
	grounded = true;
}