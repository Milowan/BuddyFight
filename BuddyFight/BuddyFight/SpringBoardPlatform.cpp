#include "SpringBoardPlatform.h"



SpringBoardPlatform::SpringBoardPlatform(float x, float y) :
	Platform(new Texture("TestLevelSpriteSheet.png", 64, 0, 64, 64), x, y)
{
	mSpringBoardBase = new Platform(new Texture("TestLevelSpriteSheet.png", 128, 0, 48, 128), x + 64, y);
}

//void SpringBoardPlatform::Spring()
//{
//	//if player collides, rotate mEntity1 Pos downward for x amount of spaces, then reset position after x amount of time to fling player upward if they are still on the platform
//}
SpringBoardPlatform::~SpringBoardPlatform()
{}
