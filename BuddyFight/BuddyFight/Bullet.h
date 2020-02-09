#pragma once
#include "PhysicsEntity.h"



class Bullet : public PhysicsEntity
{
private:
	Timer* mTimer;
	int mDamage;
	int mSpeed;
	Vector2 mForward;


public:

	Bullet();
	~Bullet();

	void BulletStats(int speed, int damage, Vector2 forward);
	int GetDamage();

	void Update() override;
};

