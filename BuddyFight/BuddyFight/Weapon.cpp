#include "Weapon.h"


Weapon::Weapon(Texture* texture, float x, float y)
	: PhysicsEntity(texture, x, y)
{
	mTimer = Timer::GetInstance();
	mask = WEAPON;
	maxSpeed = 9;
}

Weapon::~Weapon()
{
}

bool Weapon::GetIsCollected()
{
	return isCollected;
}

void Weapon::Collect()
{
	isCollected = true;
}

void Weapon::Update()
{
	UpdatePhysics();
	CheckMoved();
	if (!isCollected)
	{
		currentWidth = GetTexture()->GetWidth();
		if (!forward)
		{
			if (currentWidth >= minSpin)
			{
				currentWidth -= spinSpeed;
				GetTexture()->SetWidth(currentWidth);
			}
			else
			{
				forward = true;
				return;
			}
		}
		else
		{
			if (currentWidth <= maxSpin)
			{
				currentWidth += spinSpeed;
				GetTexture()->SetWidth(currentWidth);
			}
			else
			{
				forward = false;
				return;
			}
		}
	}
}

int Weapon::GetDamage()
{
	return mDamage;
}

void Weapon::HandleCollision(Entity* other)
{
	if (other->GetMask() == CollisionMask::GROUND)
	{
		if (overlapVector.y < 0)
		{
			SetPosition(GetPosition() + overlapVector);
			ResetYAcceleration();
			grounded = true;
		}
		if (overlapVector.y > 0)
		{
			SetPosition(GetPosition() + overlapVector);
			ResetYAcceleration();
		}
	}
}

void Weapon::Drop()
{
	isCollected = false;
}