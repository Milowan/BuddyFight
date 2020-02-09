#include "Sword.h"


Sword::Sword()
	: MeleeWeapon(new Texture("weaponSpritesheet.png", 0, 0, 64, 128), (Graphics::SCREEN_WIDTH / 2) + (Graphics::BLOCK_WIDTH * 2), 0)
{
	mDamage = 2;

	// spin animation stats
	currentWidth = GetTexture()->GetWidth();
	maxSpin = currentWidth;
	minSpin = -currentWidth;
	spinSpeed = 1.0f;
}

Sword::~Sword()
{

}