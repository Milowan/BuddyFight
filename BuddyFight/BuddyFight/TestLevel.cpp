#include "TestLevel.h"


TestLevel::TestLevel() :
	Scene(new Texture("Background.png"))
{
	mTimer = Timer::GetInstance();
	mInputManager = InputManager::GetInstance();
	mAudioManager = AudioManager::GetInstance();
	EntityPool* pool = EntityPool::GetInstance();
	player1 = new Player(new Texture("PlayerSpriteSheet.png", 10, 10, 200, 200), 10, 10);
	player1->SetPosition(10 * Graphics::BLOCK_WIDTH, 10 * Graphics::BLOCK_HEIGHT);
	pool->AddEntity(player1);
}

void TestLevel::TestLevelAudio()
{
}

void TestLevel::UpdateScene()
{
	//player1->Update();
}

TestLevel::~TestLevel()
{
	mTimer = nullptr;
	mInputManager = nullptr;
	mAudioManager = nullptr;

	delete player1;
	player1 = nullptr;
}
