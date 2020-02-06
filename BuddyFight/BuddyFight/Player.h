#include "PhysicsEntity.h"
#include "AudioManager.h"
#include "InputManager.h"
#include "Fist.h"
//include other body parts and weapon as they come in



class Player : public PhysicsEntity {

private:
	const int MAX_HEALTH = 100;
	const int MAX_STRENGTH = 10;
	int currentHealth;
	int strength;

	InputManager* input;
	AudioManager* audio;

	//Head* head;
	//Body* body;
	Fist* lFist;
	Fist* rFist;

	//Weapon* weapon

	void Attack();
	void Duck();
	void PickUp();

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

	void Update() override;

};