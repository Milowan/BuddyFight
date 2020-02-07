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

	player1 = new Player();
	player1->SetPosition(player1->GetPosition());
	player1->SetScale(Vector2(0.25, 0.25));
	pool->AddEntity(player1);

	chainPlatform1 = new ChainPlatform(1 * Graphics::BLOCK_WIDTH, 1 * Graphics::BLOCK_HEIGHT);
	pool->AddEntity(chainPlatform1);

	chainPlatform2 = new ChainPlatform(31 * Graphics::BLOCK_WIDTH, 1 * Graphics::BLOCK_HEIGHT);
	pool->AddEntity(chainPlatform2);

	chainPlatform3 = new ChainPlatform(16 * Graphics::BLOCK_WIDTH, 13 * Graphics::BLOCK_HEIGHT);
	pool->AddEntity(chainPlatform3);


}

void TestLevel::TestLevelAudio()
{}

void TestLevel::UpdateScene()
{
	chainPlatform1->UpdateChildren();
}

TestLevel::~TestLevel()
{
	mTimer = nullptr;
	mInputManager = nullptr;
	mAudioManager = nullptr;

	delete player1;
	player1 = nullptr;

	delete chainPlatform1;
	chainPlatform1 = nullptr;

	delete chainPlatform2;
	chainPlatform2 = nullptr;

	delete chainPlatform3;
	chainPlatform3 = nullptr;
}
