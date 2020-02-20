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
		if (GetOverlap().y != 0)
		{
			if (GetOverlap().y < 0)
			{
				parent->SetGrounded(true);
			}
			parent->ResetYAcceleration();
			parent->SetPosition(parent->GetPosition() + GetOverlap());
		}
		else
		{
			parent->ResetXAcceleration();
			parent->SetPosition(parent->GetPosition() + GetOverlap());
		}
	}
	if (other->GetMask() == WEAPON || other->GetMask() == FIST)
	{
		parent->HandleCollision(other);
	}
}