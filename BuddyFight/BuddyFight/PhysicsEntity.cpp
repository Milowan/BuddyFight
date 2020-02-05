#include "PhysicsEntity.h"





PhysicsEntity::PhysicsEntity(Texture* texture, float x, float y) :
	Entity(texture, x, y),
	grounded(false)
{}

void PhysicsEntity::AddForce(Vector2 force)
{
	acceleration += force;
}

void PhysicsEntity::Accelerate()
{
	movSpeed += acceleration.GetMagnitude();
	if (movSpeed > maxSpeed)
	{
		movSpeed = maxSpeed;
	}
}

void PhysicsEntity::UpdatePhysics()
{

	if (grounded)
	{
		if (forwardVector.y > 0)
		{
			forwardVector.y = 0;
		}

	}
	else
	{
		if (forwardVector.y < 0)
		{
			forwardVector.y = 0;
		}
		else
		{
			AddForce(GRAVITY);
		}
	}

	AddForce(forwardVector);

	Accelerate();

	Translate(acceleration * Timer::GetInstance()->GetDeltaTime());
}