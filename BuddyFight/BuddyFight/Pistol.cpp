#include "Pistol.h"

Pistol::Pistol()
	: ProjectileWeapon(new Texture("weaponSpritesheet", 0, 0, 64, 64), Graphics::SCREEN_WIDTH / 2, Graphics::SCREEN_HEIGHT / 2)
{
	mSpeed = 2;
	mFireRate = 1;
	mDamage = 1;
	ammo = 6;
}

Pistol::~Pistol()
{
}
