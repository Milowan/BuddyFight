#include "TestLevel.h"


TestLevel::TestLevel() :
	Scene()
{
	mTimer = Timer::GetInstance();
	mInputManager = InputManager::GetInstance();
	mAudioManager = AudioManager::GetInstance();
	EntityPool* pool = EntityPool::GetInstance();
}

void TestLevel::TestLevelAudio()
{
}

void TestLevel::UpdateScene()
{
}

TestLevel::~TestLevel()
{
}
