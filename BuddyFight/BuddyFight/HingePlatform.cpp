#include "HingePlatform.h"





HingePlatform::HingePlatform(float x, float y, float speed) :
	Platform(new Texture("TestLevelSpriteSheet.png", 64, 0, 64, 64), x, y)
{
	mHingePlatformBase = new Platform(new Texture("TestLevelSpriteSheet.png", 128, 0, 64, 64), (GetPosition().x), GetPosition().y);
    mHingePlatformBase->GetTexture()->SetWidth(mHingePlatformBase->GetTexture()->GetWidth() * 3);
    mHingePlatformBase->SetPosition(GetPosition().x + Graphics::BLOCK_WIDTH +(mHingePlatformBase->GetTexture()->GetWidth() / 2), mHingePlatformBase->GetPosition().y);
	mHingePlatformBase->SetParent(this);
    rotSpeed = speed;
}

void HingePlatform::SetRot()
{
    SetRotation(currentRot);
}

void HingePlatform::Animate()
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

void HingePlatform::Update()
{
    Animate();
}

HingePlatform::~HingePlatform()
{
	delete mHingePlatformBase;
	mHingePlatformBase = nullptr;
}
