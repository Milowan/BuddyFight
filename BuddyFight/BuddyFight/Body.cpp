#include "Body.h"


Body::Body(Texture* texture, float x, float y)
	: PhysicsEntity(texture, x, y)
{
	SetMask(BODY);
	SetShape(CIRCLE);
	grounded = true;
}

void Body::HandleCollision(Entity* other)
{
	PhysicsEntity* parent = (PhysicsEntity*)GetParent();
	if (other->GetMask() == GROUND)
	{
		parent->SetPosition(parent->GetPosition() + GetOverlap());
		parent->ResetAcceleration();
		if (GetOverlap().y < 0)
			parent->SetGrounded(true);
	}
	if (other->GetMask() == WEAPON || other->GetMask() == FIST)
	{
		parent->HandleCollision(other);
	}
}