#pragma once
#include <SDL.h>
#include "SceneManager.h"
#include "InputManager.h"
#include "Timer.h"
#include "StartScreen.h"




class GameManager
{
private:

	static GameManager* instance;
	bool quit;
	Graphics* graphics;

	const int FRAME_RATE = 60;
	Timer* timer;
	EntityPool* pool;
	InputManager* inputManager;
	AssetManager* assetManager;
	SceneManager* sceneManager;
	SDL_Event mEvent;

public:

	static GameManager* GetInstance();
	static void Release();

	void Initialize();

	void Run();
	void Update();
	void LateUpdate();
	void Render();

private:

	GameManager();
	~GameManager();
};

