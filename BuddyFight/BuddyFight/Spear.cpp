#include "Spear.h"

Spear::Spear()
	: MeleeWeapon(new Texture("weaponSpritesheet.png", 64, 0, 12, 192), (Graphics::SCREEN_WIDTH / 3) - (Graphics::BLOCK_WIDTH * 2), (Graphics::SCREEN_HEIGHT / 5) + Graphics::BLOCK_HEIGHT)
{
	mDamage = 3;

	// spin animation stats
	currentWidth = GetTexture()->GetWidth();
	maxSpin = currentWidth;
	minSpin = -currentWidth;
	spinSpeed = 1.0f;
}

Spear::~Spear()
{
}
