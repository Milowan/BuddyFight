#include "PhysicsEntity.h"
#include "AudioManager.h"
#include "InputManager.h"
#include "MathHelper.h"
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

	int currentHealth;
	int strength;

	InputManager* input;
	AudioManager* audio;
	EntityPool* pool;

	Head* head;
	Body* body;
	Fist* lFist;
	Fist* rFist;

	//Weapon* weapon

	void Attack();
	void Duck();
	void PickUp();

	void GetInput();

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

	void HandleCollision(Entity* other) override;

	void Update() override;

};