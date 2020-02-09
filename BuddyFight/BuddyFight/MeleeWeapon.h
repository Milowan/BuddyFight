#pragma once
#include "Weapon.h"

class MeleeWeapon : public Weapon
{

public:
	MeleeWeapon(Texture* texture, float x, float y);
	~MeleeWeapon();

	float GetActiveDuration(); // Use this to decide how fast to animate your punches/swings Jay

private:

protected:
	float activeDuration;
	virtual void Update() override; // As long as the weapon update runs the hitbox will handle itself and you wont be able to fire when already firing
	virtual void Fire() override; // The player can call this to activate their current weapon's hitbox

};

