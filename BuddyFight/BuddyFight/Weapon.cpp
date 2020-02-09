#include "Weapon.h"


Weapon::Weapon(Texture* texture, float x, float y)
	: PhysicsEntity(texture, x, y)
{
	mTimer = Timer::GetInstance();
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

void Weapon::Drop()
{
	isCollected = false;
}