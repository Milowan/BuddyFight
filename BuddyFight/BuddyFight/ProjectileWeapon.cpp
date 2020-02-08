#include "ProjectileWeapon.h"

ProjectileWeapon::ProjectileWeapon(Texture* texture, float x, float y)
	: Weapon(texture, x, y)
{

}

ProjectileWeapon::~ProjectileWeapon()
{

}

void ProjectileWeapon::Fire()
{
	if (ammo > 0)
	{
		mFiring = true;
	}
	else
	{
		Drop();
	}
}

void ProjectileWeapon::Update()
{
	if (mFiring)
	{
		// Once I figure out bullets and their object pooling I can call one from here 


		ammo--;
		
	}
}
