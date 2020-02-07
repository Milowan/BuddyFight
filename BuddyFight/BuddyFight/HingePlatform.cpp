#include "HingePlatform.h"





HingePlatform::HingePlatform(float x, float y) :
	Platform(new Texture("TestLevelSpriteSheet.png", 64, 0, 64, 64), x, y)
{
	mHingePlatformBase = new Platform(new Texture("TestLevelSpriteSheet.png", 128, 0, 48, 128), x + 64, y);

	mHingePlatformBase->SetParent(this);
}

void HingePlatform::SetRot()
{
    SetRotation(currentRot);
}

void HingePlatform::Animate()
{
    if (!returning)
        if (currentRot <= endRot)
            currentRot += rotSpeed;
        else
            returning = true;
    else
        if (currentRot >= startRot)
            currentRot -= rotSpeed;
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
