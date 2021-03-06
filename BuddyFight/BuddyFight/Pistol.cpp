#include "Pistol.h"

Pistol::Pistol() // Passing through the sprite, but the position will later be set in this constructor by a weapon spawner of some type
	: ProjectileWeapon(new Texture("weaponSpritesheet.png", 0, 128, 64, 64), Graphics::SCREEN_WIDTH / 2, Graphics::SCREEN_HEIGHT / 4)
{
	mSpeed = 2;
	mFireRate = 1;
	mDamage = 1;
	ammo = 6;

	// spin animation stats
	currentWidth = GetTexture()->GetWidth();
	maxSpin = currentWidth;
	minSpin = -currentWidth;
	spinSpeed = 1.0f;
}

Pistol::~Pistol()
{
}
