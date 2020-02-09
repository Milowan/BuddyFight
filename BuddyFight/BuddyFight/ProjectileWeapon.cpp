#include "ProjectileWeapon.h"

ProjectileWeapon::ProjectileWeapon(Texture* texture, float x, float y)
	: Weapon(texture, x, y)
{
	bPool = BulletPool::GetInstance();
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
	Weapon::Update();
	if (mFiring)
	{
		currentTime += mTimer->GetDeltaTime();
		if (currentTime >= mFireRate)
		{
			Bullet* currentBullet = bPool->GetInActiveBullet();
			currentBullet->SetPosition(this->GetPosition());
			currentBullet->BulletStats(mDamage, mSpeed, mForward);
			ammo--;
			mFiring = false;
			currentTime = 0;
		}
	}
}
