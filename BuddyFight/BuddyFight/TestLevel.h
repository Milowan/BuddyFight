#include "AnimatedTexture.h" 
#include "InputManager.h"
#include "EntityPool.h"
#include "AudioManager.h"
#include "Scene.h"
#include "Timer.h"
#include "SceneManager.h"

class TestLevel : public Scene
{
	private:
		Timer* mTimer;
		InputManager* mInputManager;
		AudioManager* mAudioManager;
		SceneManager* mSceneManager;

	protected:

	public:
		void TestLevelAudio();
		void UpdateScene() override;

		TestLevel();
		~TestLevel();
};

