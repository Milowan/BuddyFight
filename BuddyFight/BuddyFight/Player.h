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



class Player :
public PhysicsEntity {

private:
	static const int MAX_HEALTH = 100;
	static const int MAX_STRENGTH = 10;
	static const int MAX_PUNCH_DISTANCE = 50;
	static const int MAX_JUMP_HEIGHT = 1000;
	static const int WALK_SPEED = 15;
	
	int currentHealth;
	int strength;

	float jumpTimer;

	InputManager* input;
	AudioManager* audio;
	EntityPool* pool;
	Timer* timer;

	bool alive = true;

	Head* head;
	Body* body;
	Fist* lFist;
	Fist* rFist;

	Weapon* weapon;

	void Attack();
	void Duck();
	void PickUp();
	void Jump();
	void GetInput();
	void Die();


protected:

	bool isJumping;
	bool hasWeapon;

public:
	Player();
	~Player();

	int GetHealth();
	void SetHealth(int value);

	int GetStrength();
	void SetStrength(int value);

	void TakeDamage(int value);

	void PlaySFX();

	void Update() override;

};