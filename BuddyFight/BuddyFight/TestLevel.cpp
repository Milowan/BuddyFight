#include "TestLevel.h"


TestLevel::TestLevel() :
	Scene(new Texture("Background.png"))
{}



void TestLevel::InitializeScene()
{
	mTimer = Timer::GetInstance();
	mInputManager = InputManager::GetInstance();
	mAudioManager = AudioManager::GetInstance();
	EntityPool* pool = EntityPool::GetInstance();
	player1 = new Player(new Texture("PlayerSpriteSheet.png", 0, 0, 256, 256), 10 * Graphics::BLOCK_WIDTH, 10 * Graphics::BLOCK_HEIGHT);
	pool->AddEntity(player1);
}

void TestLevel::TestLevelAudio()
{}

void TestLevel::UpdateScene()
{}

TestLevel::~TestLevel()
{
	mTimer = nullptr;
	mInputManager = nullptr;
	mAudioManager = nullptr;

	delete player1;
	player1 = nullptr;
}
