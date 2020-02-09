#include "WinScreen.h"


WinScreen::WinScreen() :
	Scene(new Texture("Background.png"))
{}

void WinScreen::InitializeScene()
{
	mTimer = Timer::GetInstance();
	mInputManager = InputManager::GetInstance();
	mAudioManager = AudioManager::GetInstance();
	mSceneManager = SceneManager::GetInstance();
	EntityPool* pool = EntityPool::GetInstance();

	// logo entities 	 
	winLogo = new Entity(new Texture("WinLogo.png", 0, 0, 178, 54), Graphics::SCREEN_WIDTH * 0.42f, Graphics::SCREEN_HEIGHT * 0.22f);
	winLogo->SetScale(V2ONE * 2);
	pool->AddEntity(winLogo);

	// play mode entities 
	restart = new Entity(new Texture("PRESS ENTER TO RESTART OR ESCAPE FOR STARTSCREEN", "emulogic.TTF", 32, { 230, 230, 230 }), Graphics::SCREEN_WIDTH * 0.5f, Graphics::SCREEN_HEIGHT * 0.7f);
	pool->AddEntity(restart);

	WinScreenAudio();
}

void WinScreen::WinScreenAudio()
{
	mAudioManager->PlayMusic("Audio/Intro.wav", 1);
}

void WinScreen::UpdateScene()
{
	if (mInputManager->KeyDown(SDL_SCANCODE_RETURN))
	{
		mSceneManager->ChangeScene(new TestLevel());
	}
	else if (mInputManager->KeyDown(SDL_SCANCODE_ESCAPE))
	{
		mSceneManager->ChangeScene(new StartScreen());
	}
}

WinScreen::~WinScreen()
{
	delete restart;
	restart = nullptr;

	delete winLogo;
	winLogo = nullptr;

}

