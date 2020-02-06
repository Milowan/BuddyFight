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
		//get a pointer to the weapon on the ground in memory
		//check if its position is close to the players
		//groundWeapon.position = rFist.position but with a slight offset
	}
	if (hasWeapon)
	{
		return;
	}
}

Player::Player(Texture* texture, float xOffset, float yOffset) :
	PhysicsEntity(texture, xOffset, yOffset)
{
	audio = AudioManager::GetInstance();
	input = InputManager::GetInstance();

	body = new Body(texture, xOffset * Graphics::BLOCK_WIDTH, yOffset * Graphics::BLOCK_HEIGHT);

	head = new Head(texture, body->GetPosition().x, body->GetPosition().y * -0.4f);

	lFist = new Fist(texture, body->GetPosition().x * -0.024f, body->GetPosition().y * -0.3f);

	rFist = new Fist(texture, body->GetPosition().x * 0.024f, body->GetPosition().y * -0.3f);

	currentHealth = MAX_HEALTH;
	strength = MAX_STRENGTH;
	
	hasWeapon = false;
	isJumping = false;
}

Player::~Player()
{
	input = nullptr;

	audio = nullptr;

	delete head;
	head = nullptr;

	delete body;
	body = nullptr;

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
