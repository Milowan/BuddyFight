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

Player::Player() :
	PhysicsEntity(texture)
{
	audio = AudioManager::GetInstance();
	input = InputManager::GetInstance();
	pool = EntityPool::GetInstance();

	SetHealth(MAX_HEALTH);
	SetStrength(MAX_STRENGTH);

	Texture* bodyS = new Texture("PlayerSpriteSheet.png", 0, 0, 256, 256);
	Texture* headS = new Texture("PlayerSpriteSheet.png", 0, 0, 256, 256);
	Texture* lFistS = new Texture("PlayerSpriteSheet.png", 0, 0, 256, 256);
	Texture* rFistS = new Texture("PlayerSpriteSheet.png", 0, 0, 256, 256);

	hasWeapon = false;
	isJumping = false;
	maxSpeed = 60.0f;

	SetPosition(Graphics::SCREEN_WIDTH * 0.5f, Graphics::SCREEN_HEIGHT * 0.5f);

	body = new Body(bodyS, this->GetPosition().x, this->GetPosition().y);
	body->SetParent(this);
	body->GetTexture()->SetWidth(120);
	body->GetTexture()->SetHeight(120);

	head = new Head(headS, body->GetPosition().x, body->GetPosition().y - 400);
	head->SetParent(this);
	head->GetTexture()->SetWidth(80);
	head->GetTexture()->SetHeight(80);

	lFist = new Fist(lFistS, body->GetPosition().x - 350, body->GetPosition().y - 200);
	lFist->SetParent(this);
	lFist->GetTexture()->SetWidth(60);
	lFist->GetTexture()->SetHeight(60);

	rFist = new Fist(rFistS, body->GetPosition().x + 350, body->GetPosition().y - 200);
	rFist->SetParent(this);
	rFist->GetTexture()->SetWidth(60);
	rFist->GetTexture()->SetHeight(60);
}

Player::~Player()
{
	input = nullptr;

	audio = nullptr;

	pool = nullptr;

	//delete head;
	//head = nullptr;

	//delete body;
	//body = nullptr;

	//delete weapon;
	//weapon = nullptr;

	//delete lFist;
	//lFist = nullptr;

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

	UpdatePhysics();
}