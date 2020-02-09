#include "AnimatedTexture.h" 
#include "InputManager.h"
#include "EntityPool.h"
#include "AudioManager.h"
#include "Scene.h"
#include "Timer.h"
#include "SceneManager.h"
#include "TestLevel.h"






class DeathScreen : public Scene
{
private:
	Timer* mTimer;
	InputManager* mInputManager;
	AudioManager* mAudioManager;
	SceneManager* mSceneManager;
	// Logo Entities 

	Entity* deathLogo;

	// Play Mode Entities    
	Entity* restart;


public:
	DeathScreen();
	~DeathScreen();

	void InitializeScene() override;
	void UpdateScene() override;


};