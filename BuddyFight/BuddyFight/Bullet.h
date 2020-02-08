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

	Bullet(float x, float y, int speed, int damage, Vector2 forward);
	~Bullet();

	int GetDamage();

	void Update() override;
};

