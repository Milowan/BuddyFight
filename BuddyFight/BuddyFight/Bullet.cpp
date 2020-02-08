#include "Bullet.h"


Bullet::Bullet(float x, float y, int speed, int damage, Vector2 forward)
	: PhysicsEntity("bullet.png", x, y)
{
	mTimer = Timer::GetInstance();
	mSpeed = speed;
	mDamage = damage;
	mForward = forward;
}

Bullet::~Bullet()
{
}

int Bullet::GetDamage()
{
	return mDamage;
}

void Bullet::Update()
{
	if (GetActive())
	{
		SetPosition(GetPosition() + (mForward * mSpeed * mTimer->GetDeltaTime()));
	}
}
