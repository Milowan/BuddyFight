#pragma once
#include "Types.h"
#include "PhysicsEntity.h"
#include "MathHelper.h"


class Weapon : public PhysicsEntity
{
private:

	bool isCollected;

public:

	Weapon(Texture* sprite, float x, float y);
	~Weapon();

	int GetDamage();

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

	float minSpin;
	float maxSpin;
	float spinSpeed;
	float currentWidth;
	bool forward = false;
	void Update();


	void HandleCollision(Entity* other) override;

};

