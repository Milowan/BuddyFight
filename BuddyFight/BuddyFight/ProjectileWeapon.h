#pragma once
#include "Weapon.h"

class ProjectileWeapon : public Weapon
{

protected:

	int ammo = 1;
	float mFireRate = 1; // Smaller the number the faster you fire

public:
	ProjectileWeapon(Texture* texture, float x, float y);
	~ProjectileWeapon();

	void Fire() override;
	void Update() override;


};

