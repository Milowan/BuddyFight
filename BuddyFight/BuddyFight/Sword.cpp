#include "Sword.h"


Sword::Sword()
	: MeleeWeapon(new Texture("weaponSpritesheet.png", 64, 0, 128, 64), (Graphics::SCREEN_WIDTH / 2) + (Graphics::BLOCK_WIDTH * 2), 0)
{
	mDamage = 2;
	SetRotation(-90.0f);

	// spin animation stats
	horizontal = false;
	currentHeight = GetTexture()->GetHeight();
	maxSpin = currentHeight;
	minSpin = -currentHeight;
	spinSpeed = 2.0f;
}

Sword::~Sword()
{

}