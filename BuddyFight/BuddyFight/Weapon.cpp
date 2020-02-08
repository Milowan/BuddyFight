#include "Weapon.h"

Weapon::Weapon(Texture* texture, float x, float y)
	: PhysicsEntity(texture, x, y)
{
	mTimer = Timer::GetInstance();
}

bool Weapon::GetIsCollected()
{
	return isCollected;
}

void Weapon::Collect()
{
	isCollected = true;
}

void Weapon::Drop()
{
	isCollected = false;
}