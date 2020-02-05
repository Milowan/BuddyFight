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
	SetForwardVector(Vector2(0, 1));
}

void Player::PickUp()
{
	if (!hasWeapon)
	{
		//Weapon.position = rFist.position but with a slight offset
	}
	if (hasWeapon)
	{
		return;
	}
}

Player::Player() :
	PhysicsEntity(new Texture("Texture"), 0.0, 0.0)
{
	lFist = new Fist(new Texture("Texture"), 0.0, 0.0);
	rFist = new Fist(new Texture("Texture"), 0.0, 0.0);

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

	//delete weapon;
	//weapon = nullptr;

	delete lFist;
	lFist = nullptr;

	delete rFist;
	rFist = nullptr;
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
	if (input->KeyPressed(SDL_SCANCODE_W))
	{
		SetForwardVector(Vector2(0, -1));
	}
	if (input->KeyPressed(SDL_SCANCODE_S))
	{
		Duck();
	}
	if (input->KeyPressed(SDL_SCANCODE_A))
	{
		SetForwardVector(Vector2(-1, 0));
	}
	if (input->KeyPressed(SDL_SCANCODE_D))
	{
		SetForwardVector(Vector2(1, 0));
	}
	if (input->KeyPressed(SDL_SCANCODE_E))
	{
		Attack();
	}
}
