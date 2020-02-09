#include "Spear.h"

Spear::Spear()
	: MeleeWeapon(new Texture("weaponSpritesheet.png", 0, 64, 192, 12), (Graphics::SCREEN_WIDTH / 3) - (Graphics::BLOCK_WIDTH * 2), (Graphics::SCREEN_HEIGHT / 5) + Graphics::BLOCK_HEIGHT)
{
	mDamage = 3;
	SetRotation(-90.0f);

	// spin animation stats
	horizontal = false;
	currentHeight = GetTexture()->GetHeight();
	maxSpin = currentHeight;
	minSpin = -currentHeight;
	spinSpeed = 1.0f;
}

Spear::~Spear()
{
}
