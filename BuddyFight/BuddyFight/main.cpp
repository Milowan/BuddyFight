#include <iostream>
#include <SDL.h>
// MacOS using XCode
// #include <SDL2/SDL.h>

int main(int argc, char * args[]) 
{    
	// Initialize SDL subsystems    
	if (SDL_InitSubSystem(SDL_INIT_VIDEO) < 0) 
	{        
		std::cerr << "SDL could not initialize! SDL_Error: " << SDL_GetError() << std::endl;        
		return -1;    
	}    
	// Terminate SDL subsystems    
	SDL_Quit();    
	return 0;
}