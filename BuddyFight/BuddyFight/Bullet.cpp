#include "Bullet.h"


Bullet::Bullet()
	: PhysicsEntity(new Texture("bullet.png"), 0, 0)
{
	mTimer = Timer::GetInstance();
	SetActive(false);
}

Bullet::~Bullet()
{
}

void Bullet::BulletStats(int speed, int damage, Vector2 forward)
{
	mSpeed = speed;
	mDamage = damage;
	mForward = forward.Normalized();
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
		CheckMoved();
	}
}
