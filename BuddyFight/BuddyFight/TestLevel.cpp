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

	hingePlatform1 = new HingePlatform(10 * Graphics::BLOCK_WIDTH, 6 * Graphics::BLOCK_HEIGHT);
	pool->AddEntity(hingePlatform1);

	hingePlatform2 = new HingePlatform(10 * Graphics::BLOCK_WIDTH, 10 * Graphics::BLOCK_HEIGHT,0.3);
	pool->AddEntity(hingePlatform2);

	hingePlatform3 = new HingePlatform(10 * Graphics::BLOCK_WIDTH, 14 * Graphics::BLOCK_HEIGHT,0.1);
	pool->AddEntity(hingePlatform3);
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

	delete hingePlatform1;
	hingePlatform1 = nullptr;

	delete hingePlatform2;
	hingePlatform2 = nullptr;

	delete hingePlatform3;
	hingePlatform3 = nullptr;
}
