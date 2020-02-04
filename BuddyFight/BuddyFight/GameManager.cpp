#include "GameManager.h"





GameManager* GameManager::instance = NULL;

GameManager::GameManager() :
	quit(false),
	mEvent({})
{}

GameManager::~GameManager()
{
	AssetManager::Release();
	assetManager = NULL;

	EntityPool::Release();
	pool = NULL;

	Timer::Release();
	timer = NULL;

	SDL_Quit();
}

GameManager* GameManager::GetInstance()
{
	if (instance == NULL)
		instance = new GameManager();

	return instance;
}

void GameManager::Release()
{
	delete instance;
	instance = NULL;
}

void GameManager::Initialize()
{
	graphics = Graphics::GetInstance();
	if (!Graphics::IsInitialized())
		quit = true;

	pool = EntityPool::GetInstance();
	assetManager = AssetManager::GetInstance();
	inputManager = InputManager::GetInstance();
	sceneManager = SceneManager::GetInstance();
	timer = Timer::GetInstance();

}

void GameManager::Run()
{
	while (!quit)
	{
		timer->Update();
		while (SDL_PollEvent(&mEvent))
		{
			switch (mEvent.type)
			{
			case SDL_QUIT:
				quit = true;
				break;
			}
		}

		if (timer->GetDeltaTime() >= 1.0f / FRAME_RATE)
		{
			Update();
			LateUpdate();
			Render();
			timer->Reset();
		}
	}
}

void GameManager::Update()
{
	inputManager->Update();
	sceneManager->GetCurrentScene()->UpdateScene();
	pool->Update();
}

void GameManager::LateUpdate()
{
	inputManager->UpdatePrevInput();
}

void GameManager::Render()
{
	graphics->ClearBackBuffer();

	sceneManager->RenderScene();

	pool->Render();

	graphics->Render();
}