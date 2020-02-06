#include "ChainPlatform.h"




ChainPlatform::ChainPlatform(float x, float y) :
	Platform(new Texture("TestLevelSpriteSheet.png",0,64,64,64), x, y)
{
	mChainLink1 = new Platform(new Texture("TestLevelSpriteSheet.png", 0, 64, 64, 64), x , y + 64);
	mChainLink2 = new Platform(new Texture("TestLevelSpriteSheet.png", 0, 64, 64, 64), x, y + 128);
	mChainPlatformBase = new Platform(new Texture("TestLevelSpriteSheet.png", 0, 0, 64, 64), x, y + 192);

	mChainLink1->SetParent(this);
	mChainLink2->SetParent(this);
	mChainPlatformBase->SetParent(this);

}

//void ChainPlatform::Swing()
//{
		//mChainLink1 moves left by x ammount, mChainLink2 moves left by x ammount * 1.5, mChainPlatformBase moves left by x ammount * 2
		//When mChainLink1, mChainLink2, mChainPlatformBase are at their furthest left position, return to original pos.
		//Repeat first process with this time going right.
		//When mChainLink1, mChainLink2, mChainPlatformBase are at their furthest right position, return to original pos.
//}

ChainPlatform::~ChainPlatform()
{}
