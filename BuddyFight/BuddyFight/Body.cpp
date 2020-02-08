#include "Body.h"


Body::Body(Texture* texture, float x, float y)
	: PhysicsEntity(texture, x, y)
{
	SetMask(BODY);
	SetShape(CIRCLE);
	grounded = true;
}