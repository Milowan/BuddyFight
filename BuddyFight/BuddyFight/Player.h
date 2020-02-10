#include "PhysicsEntity.h"
#include "AudioManager.h"
#include "InputManager.h"
#include "MathHelper.h"
#include "Weapon.h"
#include "Timer.h"
#include "Fist.h"
#include "Body.h"
#include "Head.h"
#include "Platform.h"
#include "Sword.h"
#include "Spear.h"
#include "Bullet.h"



class Player :
public PhysicsEntity {

private:
	int currentHealth;
	int strength;

	float jumpTimer;

	InputManager* inputP1;
	InputManager* inputP2;
	AudioManager* audio;
	EntityPool* pool;
	Timer* timer;

	Texture* skin;

	bool alive = true;

	Head* head;
	Body* body;
	Fist* lFist;
	Fist* rFist;

	Weapon* weapon;

	Texture* SetSkin(std::string filename, float x, float y, float w, float h);

protected:

	bool isP1;
	bool isJumping;
	bool hasWeapon;

	static const int MAX_HEALTH = 100;
	static const int MAX_STRENGTH = 10;
	static const int MAX_PUNCH_DISTANCE = 50;
	static const int MAX_JUMP_HEIGHT = 1000;
	static const int WALK_SPEED = 60;

	void Attack();
	void Duck();
	void PickUp();
	void Jump();
	void GetInput();
	void Die();

public:
	Player(bool p1);
	~Player();

	int GetHealth();
	void SetHealth(int value);

	int SkinX(int x);

	int GetStrength();
	void SetStrength(int value);

	bool GetAlive();
	bool SetAlive(bool isAlive);

	void TakeDamage(int value);

	InputManager* GetP1P2Controls();

	void PlayJumpSFX();

	void PlayHurtSFX();

	void HandleCollision(Entity* other) override;

	void Update() override;
};