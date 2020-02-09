#include "AnimatedTexture.h" 
#include "InputManager.h"
#include "EntityPool.h"
#include "AudioManager.h"
#include "Scene.h"
#include "Timer.h"
#include "SceneManager.h"
#include "StartScreen.h"






class WinScreen : public Scene
{
private:
	Timer* mTimer;
	InputManager* mInputManager;
	AudioManager* mAudioManager;
	SceneManager* mSceneManager;
	// Logo Entities 

	Entity* winLogo;

	// Play Mode Entities    
	Entity* restart;


public:

	WinScreen();
	~WinScreen();

	void InitializeScene() override;
	void WinScreenAudio();
	void UpdateScene() override;


};