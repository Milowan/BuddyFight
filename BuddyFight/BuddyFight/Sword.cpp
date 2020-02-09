#include "Sword.h"


Sword::Sword()
	: MeleeWeapon(new Texture("weaponSpritesheet.png", 64, 0, 128, 64), (Graphics::SCREEN_WIDTH / 2) + (Graphics::BLOCK_WIDTH * 2), (Graphics::SCREEN_HEIGHT / 2) + Graphics::BLOCK_HEIGHT)
{
	mDamage = 2;
	SetRotation(-90.0f);
}

Sword::~Sword()
{

}