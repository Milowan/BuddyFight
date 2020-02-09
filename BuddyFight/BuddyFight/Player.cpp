#include "Player.h"
#include "MathHelper.h"

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
		lFist->SetPunching(true);
		lFist->SetForwardVector(Vector2(-1, 0));
		lFist->AddForce(Vector2(strength, strength));
		lFist->ResetAcceleration();
		lFist->SetPunching(false);
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

void Player::Jump()
{
	SetForwardVector(Vector2(forwardVector.x,-1));
	grounded = false;
	AddForce(Vector2(forwardVector.x, -15));
}


Player::Player() :
	PhysicsEntity(NULL)
{
	audio = AudioManager::GetInstance();
	input = InputManager::GetInstance();
	pool = EntityPool::GetInstance();
	timer = Timer::GetInstance();

	SetHealth(MAX_HEALTH);
	SetStrength(MAX_STRENGTH);

	Texture* bodyS = new Texture("PlayerSpriteSheet.png", 0, 0, 256, 256);
	Texture* headS = new Texture("PlayerSpriteSheet.png", 0, 0, 256, 256);
	Texture* lFistS = new Texture("PlayerSpriteSheet.png", 0, 0, 256, 256);
	Texture* rFistS = new Texture("PlayerSpriteSheet.png", 0, 0, 256, 256);

	hasWeapon = false;
	isJumping = false;
	maxSpeed = 60.0f;

	SetPosition(Graphics::BLOCK_WIDTH * 5, Graphics::BLOCK_HEIGHT * 3);

	body = new Body(bodyS, this->GetPosition().x, this->GetPosition().y);
	body->SetParent(this);
	body->GetTexture()->SetWidth(Graphics::BLOCK_WIDTH);
	body->GetTexture()->SetHeight(Graphics::BLOCK_HEIGHT);

	head = new Head(headS, body->GetPosition().x, body->GetPosition().y - 120);
	head->SetParent(this);
	head->GetTexture()->SetWidth(20);
	head->GetTexture()->SetHeight(20);

	lFist = new Fist(lFistS, body->GetPosition().x - 95, body->GetPosition().y - 50);
	lFist->SetParent(this);
	lFist->GetTexture()->SetWidth(15);
	lFist->GetTexture()->SetHeight(15);

	rFist = new Fist(rFistS, body->GetPosition().x + 95, body->GetPosition().y - 50);
	rFist->SetParent(this);
	rFist->GetTexture()->SetWidth(15);
	rFist->GetTexture()->SetHeight(15);
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

void Player::HandleCollision(Entity* other)
{
	if (body->GetColliding() && other->GetMask() == GROUND)
	{
		SetPosition(GetPosition() + body->GetOverlap());
		ResetAcceleration();
		if (body->GetOverlap().y < 0)
			grounded = true;
	}
	else
	{
		grounded = false;
	}

		acceleration = Vector2(0, 1);
}

void Player::GetInput()
{
	if (input->KeyDown(SDL_SCANCODE_W) && grounded)
	{
		Jump();
	}
	if (input->KeyPressed(SDL_SCANCODE_S))
	{
		Duck();
		ResetAcceleration();
	}
	if (input->KeyPressed(SDL_SCANCODE_A))
	{
		SetForwardVector(-V2RIGHT * 2);
		AddForce(Vector2(-20, 0));
		ResetAcceleration();
	}
	if (input->KeyDown(SDL_SCANCODE_W )&& input->KeyDown( SDL_SCANCODE_A) && grounded)
	{
		Jump();
	}
	if (input->KeyDown(SDL_SCANCODE_W) && input->KeyDown(SDL_SCANCODE_A) && grounded)
	{
		Jump();
	}
	if (input->KeyPressed(SDL_SCANCODE_D))
	{
		SetForwardVector(V2RIGHT * 2);
		AddForce(Vector2(20, 0));
		ResetAcceleration();
	}
	if (input->KeyPressed(SDL_SCANCODE_N))
	{
		Attack();
	}
	if (input->KeyReleased(SDL_SCANCODE_A))
	{
		SetForwardVector(V2ZERO);
	}
	if (input->KeyReleased(SDL_SCANCODE_D))
	{
		SetForwardVector(V2ZERO);
	}
	if (input->KeyReleased(SDL_SCANCODE_S))
	{
		SetForwardVector(V2ZERO);
	}
	if (input->KeyReleased(SDL_SCANCODE_W))
	{
		SetForwardVector(V2ZERO);
	}
}

void Player::Update()
{
	GetInput();

	UpdatePhysics();

	UpdateChildren();
}