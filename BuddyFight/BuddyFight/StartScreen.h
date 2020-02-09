#include "AnimatedTexture.h" 
#include "InputManager.h"
#include "EntityPool.h"
#include "AudioManager.h"
#include "Scene.h"
#include "Timer.h"
#include "SceneManager.h"
#include "TestLevel.h"






class StartScreen : public Scene
{
private:
	Timer* mTimer;
	InputManager* mInputManager;
	AudioManager* mAudioManager;
	SceneManager* mSceneManager;
	// Logo Entities 

	Entity* logo;

	// Play Mode Entities    
	Entity* start;


public:
	StartScreen();
	~StartScreen();

	void InitializeScene() override;
	void StartScreenAudio();
	void UpdateScene() override;


};


