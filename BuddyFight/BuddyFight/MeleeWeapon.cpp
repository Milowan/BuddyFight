#include "MeleeWeapon.h"

MeleeWeapon::MeleeWeapon(Texture* texture, float x, float y)
	: Weapon(texture, x, y)
{
	currentTime = 0;
}

MeleeWeapon::~MeleeWeapon()
{
}

float MeleeWeapon::GetActiveDuration()
{
	return activeDuration;
}

void MeleeWeapon::Fire()
{
	if (!activeCollider)
	{
		activeCollider = true;
	}
}

void MeleeWeapon::Update()
{
	if (activeCollider)
	{
		if (mask == CollisionMask::NONE)
		{
			mask = CollisionMask::WEAPON;
		}

		currentTime += mTimer->GetDeltaTime();

		if (currentTime >= activeDuration)
		{
			mask = CollisionMask::NONE;
			currentTime = 0;
			activeCollider = false;
		}
	}
}
