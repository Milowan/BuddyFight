#include "HingePlatform.h"



HingePlatform::HingePlatform(float x, float y) :
	Platform(new Texture("TestLevelSpriteSheet.png", 64, 0, 64, 64), x, y)
{
	mHingePlatformBase = new Platform(new Texture("TestLevelSpriteSheet.png", 128, 0, 48, 128), x + 64, y);

	mHingePlatformBase->SetParent(this);
}

//void HingePlatform::Hinge()
//{
//	//Rotate mOriginPos to mEndPos and back again to mOriginPos
//}

HingePlatform::~HingePlatform()
{}
