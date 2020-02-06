#include "Ice.h"



Ice::Ice(float x, float y) :
	Platform(new Texture("TestLevelSpriteSheet.png", 128, 64, 64, 64), x, y)
{}

//void Ice::Slip()
//{
//	//while player is colliding, translate position in the direction the player was moving slightly.
//}

Ice::~Ice()
{}
