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

	player1 = new Player(new Texture("PlayerSpriteSheet.png", 0, 0, 256, 256));
	player1->SetPosition(Vector2(10 * Graphics::BLOCK_WIDTH, 15 * Graphics::BLOCK_HEIGHT));
	player1->SetScale(Vector2(0.25, 0.25));
	pool->AddEntity(player1);

	chainPlatform = new ChainPlatform(11 * Graphics::BLOCK_WIDTH, 16 * Graphics::BLOCK_HEIGHT);
	pool->AddEntity(chainPlatform);
}

void TestLevel::TestLevelAudio()
{}

void TestLevel::UpdateScene()
{
	chainPlatform->UpdateChildren();
}

TestLevel::~TestLevel()
{
	mTimer = nullptr;
	mInputManager = nullptr;
	mAudioManager = nullptr;

	delete player1;
	player1 = nullptr;

	delete chainPlatform;
	chainPlatform = nullptr;
}
