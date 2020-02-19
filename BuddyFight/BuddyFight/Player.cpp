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

void Player::Jump()
{
	SetForwardVector(Vector2(forwardVector.x * 0.5f, -1));
	grounded = false;
	AddForce(Vector2(0, -15));
	PlayJumpSFX();
}


Player::Player(bool p1) :
	PhysicsEntity(NULL)
{
	audio = AudioManager::GetInstance();
	inputP1 = InputManager::GetInstance();
	inputP2 = InputManager::GetInstance();
	pool = EntityPool::GetInstance();
	timer = Timer::GetInstance();

	if (p1)
	{
		isP1 = true;

		//skins
		Texture* bodyS = SetSkin("PlayerSpriteSheet.png", 0, 0, 256, 256);
		Texture* headS = SetSkin("PlayerSpriteSheet.png", 0, 0, 256, 256);
		Texture* lFistS = SetSkin("PlayerSpriteSheet.png", 0, 0, 256, 256);
		Texture* rFistS = SetSkin("PlayerSpriteSheet.png", 0, 0, 256, 256);

		SetPosition(Graphics::BLOCK_WIDTH * 5, Graphics::BLOCK_HEIGHT * 3);

		body = new Body(bodyS, this->GetPosition().x, this->GetPosition().y);
		body->SetParent(this);
		body->GetTexture()->SetWidth(Graphics::BLOCK_WIDTH);
		body->GetTexture()->SetHeight(Graphics::BLOCK_HEIGHT);

		head = new Head(headS, body->GetPosition().x, body->GetPosition().y - neckMag);
		head->SetParent(this);
		head->GetTexture()->SetWidth(Graphics::BLOCK_WIDTH * 0.75);
		head->GetTexture()->SetHeight(Graphics::BLOCK_WIDTH * 0.75);

		lFist = new Fist(lFistS, body->GetPosition().x - body->GetPosition().x * 0.7f, body->GetPosition().y - armMag);
		lFist->SetParent(this);
		lFist->GetTexture()->SetWidth(Graphics::BLOCK_WIDTH * 0.5);
		lFist->GetTexture()->SetHeight(Graphics::BLOCK_WIDTH * 0.5);

		rFist = new Fist(rFistS, body->GetPosition().x + body->GetPosition().x * 0.7f, body->GetPosition().y - armMag);
		rFist->SetParent(this);
		rFist->GetTexture()->SetWidth(Graphics::BLOCK_WIDTH * 0.5);
		rFist->GetTexture()->SetHeight(Graphics::BLOCK_WIDTH * 0.5);
	}
	else
	{
		isP1 = false;

		//skins
		Texture* bodyS = SetSkin("PlayerSpriteSheet.png", 258, 0, 256, 256);
		Texture* headS = SetSkin("PlayerSpriteSheet.png", 258, 0, 256, 256);
		Texture* lFistS = SetSkin("PlayerSpriteSheet.png", 258, 0, 256, 256);
		Texture* rFistS = SetSkin("PlayerSpriteSheet.png", 258, 0, 256, 256);

		SetPosition(Graphics::BLOCK_WIDTH * 35, Graphics::BLOCK_HEIGHT * 3);

		body = new Body(bodyS, this->GetPosition().x, this->GetPosition().y);
		body->SetParent(this);
		body->GetTexture()->SetWidth(Graphics::BLOCK_WIDTH);
		body->GetTexture()->SetHeight(Graphics::BLOCK_HEIGHT);

		head = new Head(headS, body->GetPosition().x, body->GetPosition().y - 120);
		head->SetParent(this);
		head->GetTexture()->SetWidth(Graphics::BLOCK_WIDTH * 0.75);
		head->GetTexture()->SetHeight(Graphics::BLOCK_WIDTH * 0.75);

		lFist = new Fist(lFistS, body->GetPosition().x - body->GetPosition().x * 0.1f, body->GetPosition().y - 50);
		lFist->SetParent(this);
		lFist->GetTexture()->SetWidth(Graphics::BLOCK_WIDTH * 0.5);
		lFist->GetTexture()->SetHeight(Graphics::BLOCK_WIDTH * 0.5);

		rFist = new Fist(rFistS, body->GetPosition().x + body->GetPosition().x * 0.1f, body->GetPosition().y - 50);
		rFist->SetParent(this);
		rFist->GetTexture()->SetWidth(Graphics::BLOCK_WIDTH * 0.5);
		rFist->GetTexture()->SetHeight(Graphics::BLOCK_WIDTH * 0.5);
	}

	SetHealth(MAX_HEALTH);
	SetStrength(MAX_STRENGTH);

	alive = true;
	hasWeapon = false;
	isJumping = false;
	maxSpeed = WALK_SPEED;
}

Player::~Player()
{
	inputP1 = nullptr;
	inputP2 = nullptr;

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

bool Player::GetAlive()
{
	return alive;
}

bool Player::SetAlive(bool isAlive)
{
	alive = isAlive;
	return isAlive;
}

void Player::TakeDamage(int value)
{
	currentHealth -= value;
	PlayHurtSFX();
}

InputManager* Player::GetP1P2Controls()
{
	if (isP1)
	{
		return inputP1;
	}

	else
	{
		return inputP2;
	}
}

void Player::PlayJumpSFX()
{
	audio->PlaySFX("Audio/jump.wav", 0);
}

void Player::PlayHurtSFX()
{
	audio->PlaySFX("Audio/playerhit.wav", 0);
}

void Player::HandleCollision(Entity* other)
{
	if (other->GetMask() == FIST)
	{
		TakeDamage(((Fist*)other)->GetDamage());
	}

	//if player has no weapon and one touches them,
	if (hasWeapon == false&&other->GetMask() == WEAPON && weapon == nullptr)
	{
		//pick it up
		hasWeapon = true;
		other->SetParent(rFist);
		other->SetPosition(rFist->GetPosition());

	}
	//otherwise take damage for getting touched by a weapon
	if (other->GetMask() == WEAPON && hasWeapon == true)
	{
		//O(n)
		TakeDamage(dynamic_cast<Weapon*>(other)->GetDamage()); //only works if get damage is public
	}

}

void Player::GetInput()
{
	if (isP1)
	{
		if (inputP1->KeyDown(SDL_SCANCODE_W) && grounded)
		{
			Jump();
		}
		if (inputP1->KeyPressed(SDL_SCANCODE_S))
		{
			Duck();
			ResetAcceleration();
		}
		if (inputP1->KeyPressed(SDL_SCANCODE_A))
		{
			SetForwardVector(-V2RIGHT * 2);
			AddForce(Vector2(WALK_SPEED, 0));
			ResetAcceleration();
		}
		if (inputP1->KeyPressed(SDL_SCANCODE_D))
		{
			SetForwardVector(V2RIGHT * 2);
			AddForce(Vector2(WALK_SPEED, 0));
			ResetAcceleration();
		}
		if (inputP1->KeyPressed(SDL_SCANCODE_C))
		{
			Attack();
		}
		if (inputP1->KeyReleased(SDL_SCANCODE_A))
		{
			SetForwardVector(V2ZERO);
		}
		if (inputP1->KeyReleased(SDL_SCANCODE_D))
		{
			SetForwardVector(V2ZERO);
		}
		if (inputP1->KeyReleased(SDL_SCANCODE_S))
		{
			SetForwardVector(V2ZERO);
		}
		if (inputP1->KeyReleased(SDL_SCANCODE_W))
		{
			SetForwardVector(V2ZERO);
			acceleration = acceleration - timer->GetDeltaTime();
		}
	}

	else
	{
		if (inputP2->KeyDown(SDL_SCANCODE_I) && grounded)
		{
			Jump();
		}
		if (inputP2->KeyPressed(SDL_SCANCODE_K))
		{
			Duck();
			ResetAcceleration();
		}
		if (inputP2->KeyPressed(SDL_SCANCODE_J))
		{
			SetForwardVector(-V2RIGHT * 2);
			AddForce(Vector2(WALK_SPEED, 0));
			ResetAcceleration();
		}
		if (inputP2->KeyPressed(SDL_SCANCODE_L))
		{
			SetForwardVector(V2RIGHT * 2);
			AddForce(Vector2(WALK_SPEED, 0));
			ResetAcceleration();
		}
		if (inputP2->KeyPressed(SDL_SCANCODE_N))
		{
			Attack();
		}
		if (inputP2->KeyReleased(SDL_SCANCODE_J))
		{
			SetForwardVector(V2ZERO);
		}
		if (inputP2->KeyReleased(SDL_SCANCODE_L))
		{
			SetForwardVector(V2ZERO);
		}
		if (inputP2->KeyReleased(SDL_SCANCODE_K))
		{
			SetForwardVector(V2ZERO);
		}
		if (inputP2->KeyReleased(SDL_SCANCODE_I))
		{
			SetForwardVector(V2ZERO);
			acceleration = acceleration - timer->GetDeltaTime();
		}
	}
}

void Player::Die()
{
	if (this->GetPosition().x < 0 || this->GetPosition().x > Graphics::SCREEN_WIDTH && isP1 == true)
	{
		alive = false;
		Entity* dead = new Entity(new Texture("PLAYER 2 WINS", "emulogic.TTF", 32, { 230, 230, 230 }), Graphics::SCREEN_WIDTH * 0.5f, Graphics::SCREEN_HEIGHT * 0.7f);
		pool->AddEntity(dead);
		Entity* restart = new Entity(new Texture("PRESS ENTER TO RESTART", "emulogic.TTF", 32, { 230, 230, 230 }), Graphics::SCREEN_WIDTH * 0.5f, Graphics::SCREEN_HEIGHT * 0.8f);
		pool->AddEntity(restart);
	}
	else if (this->GetPosition().x < 0 || this->GetPosition().x > Graphics::SCREEN_WIDTH && isP1 == false)
	{
		Entity* dead = new Entity(new Texture("PLAYER 1 WINS", "emulogic.TTF", 32, { 230, 230, 230 }), Graphics::SCREEN_WIDTH * 0.5f, Graphics::SCREEN_HEIGHT * 0.7f);
		pool->AddEntity(dead);
		Entity* restart = new Entity(new Texture("PRESS ENTER TO RESTART", "emulogic.TTF", 32, { 230, 230, 230 }), Graphics::SCREEN_WIDTH * 0.5f, Graphics::SCREEN_HEIGHT * 0.8f);
		pool->AddEntity(restart);
	}

	if (this->GetPosition().y > Graphics::SCREEN_HEIGHT)
	{
		alive = false;
	}

	if (currentHealth <= 0)
	{
		pool->RemoveEntity(this);
		if (isP1)
		{
			Entity* dead = new Entity(new Texture("PLAYER 2 WINS", "emulogic.TTF", 32, { 230, 230, 230 }), Graphics::SCREEN_WIDTH * 0.5f, Graphics::SCREEN_HEIGHT * 0.7f);
			pool->AddEntity(dead);
			Entity* restart = new Entity(new Texture("PRESS ENTER TO RESTART", "emulogic.TTF", 32, { 230, 230, 230 }), Graphics::SCREEN_WIDTH * 0.5f, Graphics::SCREEN_HEIGHT * 0.8f);
			pool->AddEntity(restart);
		}

		else
		{
			Entity* dead = new Entity(new Texture("PLAYER 1 WINS", "emulogic.TTF", 32, { 230, 230, 230 }), Graphics::SCREEN_WIDTH * 0.5f, Graphics::SCREEN_HEIGHT * 0.7f);
			pool->AddEntity(dead);
			Entity* restart = new Entity(new Texture("PRESS ENTER TO RESTART", "emulogic.TTF", 32, { 230, 230, 230 }), Graphics::SCREEN_WIDTH * 0.5f, Graphics::SCREEN_HEIGHT * 0.8f);
			pool->AddEntity(restart);
		}
	}
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