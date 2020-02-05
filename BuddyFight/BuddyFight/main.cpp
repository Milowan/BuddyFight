#include <iostream>
#include <SDL.h>
#include "GameManager.h"
// MacOS using XCode
// #include <SDL2/SDL.h>

int main(int argc, char * args[]) 
{    
	GameManager* game = GameManager::GetInstance();
	game->Initialize();
	game->Run();

	GameManager::Release();
	game = nullptr;
	return 0;
}