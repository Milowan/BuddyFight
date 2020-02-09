#include "Spear.h"

Spear::Spear()
	: MeleeWeapon(new Texture("weaponSpritesheet.png", 0, 64, 192, 12), (Graphics::SCREEN_WIDTH / 2) - (Graphics::BLOCK_WIDTH * 2), (Graphics::SCREEN_HEIGHT / 2) + Graphics::BLOCK_HEIGHT)
{
	mDamage = 3;
	SetRotation(-90.0f);
}

Spear::~Spear()
{
}
