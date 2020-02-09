#include "StartScreen.h"

StartScreen::StartScreen() :
	Scene(new Texture("Background.png"))
{}

void StartScreen::InitializeScene()
{
	mTimer = Timer::GetInstance();
	mInputManager = InputManager::GetInstance();
	mAudioManager = AudioManager::GetInstance();
	mSceneManager = SceneManager::GetInstance();
	EntityPool* pool = EntityPool::GetInstance();

	// logo entities    
	logo = new Entity(new Texture("BuddyFightLogo.png", 0, 0, 256, 128), Graphics::SCREEN_WIDTH * 0.42f, Graphics::SCREEN_HEIGHT * 0.22f);
	logo->SetScale(V2ONE * 2);
	pool->AddEntity(logo);

	// play mode entities 
	start = new Entity(new Texture("PRESS ENTER TO START", "emulogic.TTF", 32, { 230, 230, 230 }), Graphics::SCREEN_WIDTH * 0.5f, Graphics::SCREEN_HEIGHT * 0.7f);
	pool->AddEntity(start);

	Entity* entity = new Entity(new Texture("WASD to move", "emulogic.TTF", 14, { 255, 255, 255 }), Graphics::SCREEN_WIDTH * 0.5f, Graphics::SCREEN_HEIGHT * 0.78f);
	pool->AddEntity(entity);

	entity = new Entity(new Texture("Insert Other controls here...", "emulogic.TTF", 14, { 255, 255, 255 }), Graphics::SCREEN_WIDTH * 0.5f, Graphics::SCREEN_HEIGHT * 0.83f);
	pool->AddEntity(entity);

	StartScreenAudio();
}

void StartScreen::StartScreenAudio()
{
	mAudioManager->PlayMusic("Audio/Intro.wav", 1);
}

void StartScreen::UpdateScene()
{
	if (mInputManager->KeyDown(SDL_SCANCODE_RETURN))
	{
		mSceneManager->ChangeScene(new TestLevel());
	}
}

StartScreen::~StartScreen()
{
	delete start;
	start = nullptr;

	delete logo;
	logo = nullptr;
}


