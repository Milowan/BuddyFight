#include "AnimatedTexture.h" 
#include "InputManager.h"
#include "EntityPool.h"
#include "AudioManager.h"
#include "Scene.h"
#include "Timer.h"
#include "SceneManager.h"
#include "Player.h"
#include "ChainPlatform.h"
#include "HingePlatform.h"
#include "BasePlatform.h"

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

		//HingePlatform* hingePlatform1;
		//HingePlatform* hingePlatform2;
		//HingePlatform* hingePlatform3;

	protected:

	public:

		void InitializeScene() override;
		void TestLevelAudio();
		void UpdateScene() override;

		TestLevel();
		~TestLevel();
};

