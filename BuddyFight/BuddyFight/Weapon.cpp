#include "Weapon.h"


Weapon::Weapon(Texture* texture, float x, float y)
	: PhysicsEntity(texture, x, y)
{
	mTimer = Timer::GetInstance();
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
	if (!isCollected)
	{
		if (horizontal)
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
		if (!horizontal)
		{
			currentHeight = GetTexture()->GetHeight();
			if (!forward)
			{
				if (currentHeight >= minSpin)
				{
					currentHeight -= spinSpeed;
					GetTexture()->SetHeight(currentHeight);
				}
				else
				{
					forward = true;
					return;
				}
			}
			else
			{
				if (currentHeight <= maxSpin)
				{
					currentHeight += spinSpeed;
					GetTexture()->SetHeight(currentHeight);
				}
				else
				{
					forward = false;
					return;
				}
			}
		}
	}
}

void Weapon::Drop()
{
	isCollected = false;
}