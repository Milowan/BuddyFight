#include "ChainPlatform.h"






ChainPlatform::ChainPlatform(float x, float y) :
	Platform(new Texture("TestLevelSpriteSheet.png", 64, 64, 64, 64), x, y)
{
	mChainLink1 = new Entity(new Texture("TestLevelSpriteSheet.png", 0, 64, 64, 64), GetPosition().x, GetPosition().y + (GetTexture()->GetHeight()));
	mChainLink2 = new Entity(new Texture("TestLevelSpriteSheet.png", 0, 64, 64, 64), mChainLink1->GetPosition().x, mChainLink1->GetPosition().y + (mChainLink1->GetTexture()->GetHeight()));
	mChainLink3 = new Entity(new Texture("TestLevelSpriteSheet.png", 0, 64, 64, 64), mChainLink2->GetPosition().x + (mChainLink2->GetTexture()->GetWidth() * 4), mChainLink2->GetPosition().y);
	mChainLink4 = new Entity(new Texture("TestLevelSpriteSheet.png", 0, 64, 64, 64), mChainLink3->GetPosition().x, (mChainLink3->GetPosition().y - (mChainLink3->GetTexture()->GetHeight())));
	mCrate = new Platform(new Texture("TestLevelSpriteSheet.png", 64, 64, 64, 64), mChainLink4->GetPosition().x, (mChainLink4->GetPosition().y - (mChainLink4->GetTexture()->GetHeight())));

	mChainPlatformBase = new Platform(new Texture("TestLevelSpriteSheet.png", 0, 0, 64, 64));
	mChainPlatformBase->GetTexture()->SetWidth(mChainPlatformBase->GetTexture()->GetWidth() * 5);
	mChainPlatformBase->SetPosition(mChainLink2->GetPosition().x - (Graphics::BLOCK_WIDTH) + (mChainPlatformBase->GetTexture()->GetWidth() / 2), mChainLink2->GetPosition().y + (GetTexture()->GetHeight()));

	mChainLink1->SetParent(this);
	mChainLink2->SetParent(this);
	mChainLink3->SetParent(this);
	mChainLink4->SetParent(this);
	mCrate->SetParent(this);
	mChainPlatformBase->SetParent(this);

}


ChainPlatform::~ChainPlatform()
{
	delete mChainLink1;
	mChainLink1 = nullptr;

	delete mChainLink2;
	mChainLink2 = nullptr;

	delete mChainLink3;
	mChainLink3 = nullptr;

	delete mChainLink4;
	mChainLink4 = nullptr;

	delete mCrate;
	mCrate = nullptr;

	delete 	mChainPlatformBase;
	mChainPlatformBase = nullptr;


}
