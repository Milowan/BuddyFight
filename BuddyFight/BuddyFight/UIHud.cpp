#include "UIHud.h"

UIHud::UIHud(int time) :
	Entity(NULL, Graphics::SCREEN_WIDTH * 0.1f, Graphics::SCREEN_HEIGHT * 0.1f)
{
	EntityPool* pool = EntityPool::GetInstance();

	mTime = new TimerEntity(time, Graphics::SCREEN_WIDTH * 0.5f, Graphics::SCREEN_HEIGHT * 0.1f);
	pool->AddEntity(mTime);

	mTime->SetParent(this);

}

int UIHud::Timer()
{
	return mTime->CountdownTimer();
}

UIHud::~UIHud()
{
	delete mTime;
	mTime = nullptr;
}

