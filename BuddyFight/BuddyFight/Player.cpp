#include "Player.h"

void Player::Attack()
{
	if (hasWeapon)
	{
		//check if weapon pointer is null
			//if its not nullptr, run an attack that weapon would perform
	}
	if (!hasWeapon)
	{
		//check if forward vector is positiive or negative (right or left)
		//that way we know which fist to use
		//proper fist position moves in the direction of forward vector
	}
}

void Player::Duck()
{
	//forward vector Y = +1
}

void Player::PickUp()
{
	if (!hasWeapon)
	{
		//put weapon into one of the hands
	}
	if (hasWeapon)
	{
		//nothing happens, dont pick up the weapon on ground
	}
}

Player::Player() :
	PhysicsEntity(new Texture("Texture"), 0.0, 0.0)
{
	audio = AudioManager::GetInstance();
	input = InputManager::GetInstance();

	currentHealth = MAX_HEALTH;
	strength = MAX_STRENGTH;
	
	hasWeapon = false;
	isJumping = false;
}

Player::~Player()
{
	input = nullptr;

	audio = nullptr;

	//delete head;
	//head = nullptr;

	//delete body;
	//body = nullptr;

	//delete lFist;
	//lFist = nullptr;

	//delete rFist;
	//rFist = nullptr;
}

int Player::GetHealth()
{
	return currentHealth;
}

void Player::SetHealth(int value)
{
	currentHealth = value;
}

int Player::GetStrength()
{
	return strength;
}

void Player::SetStrength(int value)
{
	strength = value;
}

void Player::TakeDamage(int value)
{
	currentHealth -= value;
}

void Player::Update()
{
	//check for movement
}
