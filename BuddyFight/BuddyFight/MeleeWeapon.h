#pragma once
#include "Weapon.h"

class MeleeWeapon : public Weapon
{

public:
	MeleeWeapon(Texture* texture, float x, float y);
	~MeleeWeapon();

	float GetActiveDuration();

private:
	bool activeCollider;
	float currentTime;

protected:
	float activeDuration;
	virtual void Update() override;
	virtual void Fire() override;

};

