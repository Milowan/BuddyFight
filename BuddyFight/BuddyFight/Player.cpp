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
		//if (rFist->GetColliding() && )
	}
	if (hasWeapon)
	{
		return;
	}
}

void Player::Jump()
{
	SetForwardVector(Vector2(forwardVector.x * 0.5f, -1));
	grounded = false;
	AddForce(Vector2(0, -15));
	PlaySFX();
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

	//skins
	Texture* bodyS = SetSkin("PlayerSpriteSheet.png", 0, 0, 256, 256);
	Texture* headS = SetSkin("PlayerSpriteSheet.png", 0, 0, 256, 256);
	Texture* lFistS = SetSkin("PlayerSpriteSheet.png", 0, 0, 256, 256);
	Texture* rFistS = SetSkin("PlayerSpriteSheet.png", 0, 0, 256, 256);

	alive = true;
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
	head->GetTexture()->SetWidth(Graphics::BLOCK_WIDTH * 0.75);
	head->GetTexture()->SetHeight(Graphics::BLOCK_WIDTH * 0.75);

	lFist = new Fist(lFistS, body->GetPosition().x - body->GetPosition().x * 0.7f, body->GetPosition().y - 50);
	lFist->SetParent(this);
	lFist->GetTexture()->SetWidth(Graphics::BLOCK_WIDTH * 0.5);
	lFist->GetTexture()->SetHeight(Graphics::BLOCK_WIDTH * 0.5);

	rFist = new Fist(rFistS, body->GetPosition().x + body->GetPosition().x * 0.7f, body->GetPosition().y - 50);
	rFist->SetParent(this);
	rFist->GetTexture()->SetWidth(Graphics::BLOCK_WIDTH * 0.5);
	rFist->GetTexture()->SetHeight(Graphics::BLOCK_WIDTH * 0.5);
}

Player::~Player()
{
	input = nullptr;

	audio = nullptr;

	pool = nullptr;

	timer = nullptr;

	delete head;
	head = nullptr;

	delete body;
	body = nullptr;

	delete weapon;
	weapon = nullptr;

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

Texture* Player::SetSkin(std::string filename, float x, float y, float w, float h)
{
	skin = new Texture(filename, SkinX(x), y, w, h);
	return skin;
}

int Player::SkinX(int x)
{
	return x;
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
		AddForce(Vector2(WALK_SPEED, 0));
		ResetAcceleration();
	}
	if (input->KeyPressed(SDL_SCANCODE_D))
	{
		SetForwardVector(V2RIGHT * 2);
		AddForce(Vector2(WALK_SPEED, 0));
		ResetAcceleration();
	}
	if (input->KeyPressed(SDL_SCANCODE_C))
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
		acceleration = acceleration - timer->GetDeltaTime();
	}
}

void Player::Die()
{
	if (this->GetPosition().x < 0 || this->GetPosition().x > Graphics::SCREEN_WIDTH)
	{
		alive = false;
		Entity* dead = new Entity(new Texture("PLAYER 2 WINS", "emulogic.TTF", 32, { 230, 230, 230 }), Graphics::SCREEN_WIDTH * 0.5f, Graphics::SCREEN_HEIGHT * 0.7f);
		pool->AddEntity(dead);
		Entity* restart = new Entity(new Texture("PRESS (some key here) TO RESTART", "emulogic.TTF", 32, { 230, 230, 230 }), Graphics::SCREEN_WIDTH * 0.5f, Graphics::SCREEN_HEIGHT * 0.8f);
		pool->AddEntity(restart);
	}
	if (this->GetPosition().y > Graphics::SCREEN_HEIGHT)
	{
		alive = false;
	}
}

void Player::PlaySFX()
{
	audio->PlaySFX("Audio/jump.wav", 0);
}

void Player::Update()
{
	GetInput();

	if (!body->GetColliding())
	{
		grounded = false;
	}

	UpdatePhysics();

	UpdateChildren();

	Die();
}