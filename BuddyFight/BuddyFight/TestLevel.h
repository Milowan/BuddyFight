#include "AnimatedTexture.h" 
#include "InputManager.h"
#include "EntityPool.h"
#include "AudioManager.h"
#include "Scene.h"
#include "Timer.h"
#include "SceneManager.h"
#include "ChainPlatform.h"
#include "HingePlatformEast.h"
#include "HingePlatformWest.h"
#include "BasePlatform.h"
#include "Crate.h"
#include "Spikes.h"
//Weapon includes
#include "Pistol.h"
#include "Sword.h"
#include "Spear.h"
#include <string>;
#include <sstream>;


class TestLevel : public Scene
{
	private:
		Timer* mTimer;
		InputManager* mInputManager;
		AudioManager* mAudioManager;
		SceneManager* mSceneManager;

		//Entities
		Player* player1;
		Player* player2;

		Entity* clock;

		BasePlatform* basePlatform;
		ChainPlatform* chainPlatform1;
		ChainPlatform* chainPlatform2;
		HingePlatformEast* hingePlatform1;
		HingePlatformWest* hingePlatform2;

		Crate* crate1;
		Crate* crate2;
		Crate* crate3;
		Crate* crate4;
		Crate* crate5;
		Crate* crate6;
		Crate* crate7;
		Crate* crate8;
		Crate* crate9;
		Crate* crate10;
		Crate* crate11;
		Crate* crate12;


		//Spikes* spike1;
		//Spikes* spike2;
		//Spikes* spike3;
		//Spikes* spike4;
		//Spikes* spike5;
		//Spikes* spike6;
		//Spikes* spike7;
		//Spikes* spike8;
		//Spikes* spike9;
		//Spikes* spike10;
		//Spikes* spike11;
		//Spikes* spike12;
		//Spikes* spike13;
		//Spikes* spike14;
		//Spikes* spike15;
		//Spikes* spike16;
		//Spikes* spike17;

		// Weapons
		EntityPool* pool;
		BulletPool* bPool;
		Pistol* mPistol;
		Sword* mSword;
		Spear* mSpear;

		//variables
		int timeOut = 0;
		int currentTime = 2000;
		int maxTime = 2000;
	protected:

	public:

		void InitializeScene() override;
		void TestLevelAudio();
		void UpdateScene() override;
		int CountdownTimer();

		TestLevel();
		~TestLevel();
};

