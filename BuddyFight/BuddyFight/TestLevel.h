#include "AnimatedTexture.h" 
#include "InputManager.h"
#include "EntityPool.h"
#include "AudioManager.h"
#include "Scene.h"
#include "Timer.h"
#include "SceneManager.h"
#include "Player.h"
#include "ChainPlatform.h"
#include "HingePlatformEast.h"
#include "HingePlatformWest.h"
#include "BasePlatform.h"
#include "Crate.h"
#include "Pistol.h"

class TestLevel : public Scene
{
	private:
		Timer* mTimer;
		InputManager* mInputManager;
		AudioManager* mAudioManager;
		SceneManager* mSceneManager;

		Player* player1;
		//Player* player2;

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

		EntityPool* pool;
		BulletPool* bPool;
		Pistol* mPistol;

	protected:

	public:

		void InitializeScene() override;
		void TestLevelAudio();
		void UpdateScene() override;

		TestLevel();
		~TestLevel();
};

