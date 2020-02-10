#include "HingePlatformWest.h"




HingePlatformWest::HingePlatformWest(float x, float y, float speed) :
    Platform(new Texture("TestLevelSpriteSheet.png", 192, 0, 64, 64), x, y)
{
    mHingePlatformBase1 = new Platform(new Texture("TestLevelSpriteSheet.png", 192, 64, 64, 64), (GetPosition().x), GetPosition().y);
    mHingePlatformBase1->SetPosition(GetPosition().x + Graphics::BLOCK_WIDTH + (mHingePlatformBase1->GetTexture()->GetWidth() * -1.3), mHingePlatformBase1->GetPosition().y);
    mHingePlatformBase1->SetParent(this);
    mHingePlatformBase2 = new Platform(new Texture("TestLevelSpriteSheet.png", 192, 64, 64, 64), (GetPosition().x), GetPosition().y);
    mHingePlatformBase2->SetPosition(GetPosition().x + Graphics::BLOCK_WIDTH + (mHingePlatformBase2->GetTexture()->GetWidth() * -2.2), mHingePlatformBase2->GetPosition().y);
    mHingePlatformBase2->SetParent(this);
    mHingePlatformBase3 = new Platform(new Texture("TestLevelSpriteSheet.png", 192, 64, 64, 64), (GetPosition().x), GetPosition().y);
    mHingePlatformBase3->SetPosition(GetPosition().x + Graphics::BLOCK_WIDTH + (mHingePlatformBase3->GetTexture()->GetWidth() * -3.1), mHingePlatformBase3->GetPosition().y);
    mHingePlatformBase3->SetParent(this);
    rotSpeed = speed;

}
void HingePlatformWest::SetRot()
{
    SetRotation(currentRot);
}

void HingePlatformWest::Animate()
{
    if (!returning)
        if (currentRot <= endRot)
        {
            currentRot += rotSpeed;
            SetRot();
        }

        else
            returning = true;
    else
        if (currentRot >= startRot)
        {
            currentRot -= rotSpeed;
            SetRot();
        }

        else
            returning = false;
}

void HingePlatformWest::Update()
{
	Animate();
}

HingePlatformWest::~HingePlatformWest()
{
	delete mHingePlatformBase1;
	mHingePlatformBase1 = nullptr;

    delete mHingePlatformBase2;
    mHingePlatformBase2 = nullptr;

    delete mHingePlatformBase3;
    mHingePlatformBase3 = nullptr;
}
