#include "Player.h"

void Player::Attack()
{
	if (hasWeapon)
	{
		//check if weapon pointer is null
			//if its not nullptr, run an attack that weapon would perform
		//attack sfx
	}
	if (!hasWeapon)
	{
		//check if forward vector is positiive or negative (right or left)
		//that way we know which fist to use
		//proper fist position moves in the direction of forward vector
		//attack sfx
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
		//run pick up sfx
	}
	if (hasWeapon)
	{
		return;
	}
}

Player::Player(Texture* texture) :
	PhysicsEntity(texture)
{
	audio = AudioManager::GetInstance();
	input = InputManager::GetInstance();
	pool = EntityPool::GetInstance();

	SetHealth(MAX_HEALTH);
	SetStrength(MAX_STRENGTH);

	hasWeapon = false;
	isJumping = false;

	body = new Body(texture);
	body->SetParent(this);

	head = new Head(texture);
	head->SetPosition(Vector2(body->GetPosition().x, body->GetPosition().y * -0.4f));
	head->SetParent(this);

	lFist = new Fist(texture, body->GetPosition().x * -0.2f, body->GetPosition().y * -0.3f);
	lFist->SetParent(this);

	rFist = new Fist(texture, body->GetPosition().x * 0.2f, body->GetPosition().y * -0.3f);
	rFist->SetParent(this);
}

Player::~Player()
{
	input = nullptr;

	audio = nullptr;

	pool = nullptr;

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

void Player::GetInput()
{
	if (input->KeyPressed(SDL_SCANCODE_W))
	{
		SetForwardVector(Vector2(0, -1));
		printf("moved up!");
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

void Player::Update()
{
	GetInput();
}