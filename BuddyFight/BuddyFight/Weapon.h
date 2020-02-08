#pragma once
#include "Types.h"
#include "PhysicsEntity.h"
#include "MathHelper.h"


class Weapon : public PhysicsEntity
{
private:

	bool isCollected;

public:

	Weapon();
	Weapon(Texture* sprite, float x, float y);
	~Weapon();

protected:

	Timer* mTimer;
	float currentTime;
	WeaponType mWeaponType;
	int mDamage;
	bool mFiring;
	virtual void Fire() = 0;
	virtual void Drop();
	bool GetIsCollected();
	void Collect();

};

