#include "BasePlatform.h"

BasePlatform::BasePlatform(float x, float y) :
	Platform(new Texture("TestLevelSpriteSheet.png", 0, 0, 64, 64), x, y)
{	
	GetTexture()->SetWidth(GetTexture()->GetWidth() * 10);
	peg1 = new Platform(new Texture("TestLevelSpriteSheet.png", 0, 0, 64, 64), (GetPosition().x - GetTexture()->GetWidth() / 2) + Graphics::BLOCK_WIDTH, GetPosition().y + (GetTexture()->GetHeight()));
	peg2 = new Platform(new Texture("TestLevelSpriteSheet.png", 0, 0, 64, 64), (GetPosition().x + GetTexture()->GetWidth() / 2) - Graphics::BLOCK_WIDTH, peg1->GetPosition().y);

	peg1->SetParent(this);
	peg2->SetParent(this);
}

BasePlatform::~BasePlatform()
{
	delete peg1;
	peg1 = nullptr;

	delete peg2;
	peg2 = nullptr;
}
