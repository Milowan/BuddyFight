#include "TestLevel.h"


TestLevel::TestLevel() :
	Scene(new Texture("Background.png"))
{}



void TestLevel::InitializeScene()
{
	mTimer = Timer::GetInstance();
	mInputManager = InputManager::GetInstance();
	mAudioManager = AudioManager::GetInstance();
	pool = EntityPool::GetInstance();
	bPool = BulletPool::GetInstance();

	player1 = new Player();
	player1->SetPosition(player1->GetPosition());
	player1->SetScale(Vector2(0.25, 0.25));
	pool->AddEntity(player1);

	chainPlatform1 = new ChainPlatform(1 * Graphics::BLOCK_WIDTH, 1 * Graphics::BLOCK_HEIGHT);
	pool->AddEntity(chainPlatform1);
	chainPlatform2 = new ChainPlatform(31 * Graphics::BLOCK_WIDTH, 1 * Graphics::BLOCK_HEIGHT);
	pool->AddEntity(chainPlatform2);

	basePlatform = new BasePlatform(20 * Graphics::BLOCK_WIDTH, 18 * Graphics::BLOCK_HEIGHT);
	pool->AddEntity(basePlatform);

	hingePlatform1 = new HingePlatformEast(7 * Graphics::BLOCK_WIDTH, 9* Graphics::BLOCK_HEIGHT);
	pool->AddEntity(hingePlatform1);
	hingePlatform2 = new HingePlatformWest(34 * Graphics::BLOCK_WIDTH, 9 * Graphics::BLOCK_HEIGHT);
	pool->AddEntity(hingePlatform2);

	crate1 = new Crate(22 * Graphics::BLOCK_WIDTH, 16 * Graphics::BLOCK_HEIGHT);
	pool->AddEntity(crate1);
	crate2 = new Crate(20 * Graphics::BLOCK_WIDTH, 16 * Graphics::BLOCK_HEIGHT);
	pool->AddEntity(crate2);
	crate3 = new Crate(18 * Graphics::BLOCK_WIDTH, 16 * Graphics::BLOCK_HEIGHT);
	pool->AddEntity(crate3);
	crate4 = new Crate(16 * Graphics::BLOCK_WIDTH, 16 * Graphics::BLOCK_HEIGHT);
	pool->AddEntity(crate4);
	crate5 = new Crate(24 * Graphics::BLOCK_WIDTH, 16 * Graphics::BLOCK_HEIGHT);
	pool->AddEntity(crate5);
	crate6 = new Crate(26 * Graphics::BLOCK_WIDTH, 16 * Graphics::BLOCK_HEIGHT);
	pool->AddEntity(crate6);
	crate7 = new Crate(24 * Graphics::BLOCK_WIDTH, 14 * Graphics::BLOCK_HEIGHT);
	pool->AddEntity(crate7);
	crate8 = new Crate(22 * Graphics::BLOCK_WIDTH, 14 * Graphics::BLOCK_HEIGHT);
	pool->AddEntity(crate8);
	crate9 = new Crate(20 * Graphics::BLOCK_WIDTH, 14 * Graphics::BLOCK_HEIGHT);
	pool->AddEntity(crate9);
	crate10 = new Crate(18 * Graphics::BLOCK_WIDTH, 14 * Graphics::BLOCK_HEIGHT);
	pool->AddEntity(crate10);
	crate11 = new Crate(22 * Graphics::BLOCK_WIDTH, 12 * Graphics::BLOCK_HEIGHT);
	pool->AddEntity(crate11);
	crate12 = new Crate(20 * Graphics::BLOCK_WIDTH, 12 * Graphics::BLOCK_HEIGHT);
	pool->AddEntity(crate12);

	// Weapons
	mPistol = new Pistol();
	pool->AddEntity(mPistol);
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

	delete basePlatform;
	basePlatform = nullptr;

	delete hingePlatform1;
	hingePlatform1 = nullptr;

	delete hingePlatform2;
	hingePlatform2 = nullptr;

	delete crate1;
	crate1 = nullptr;
	delete crate2;
	crate2 = nullptr;
	delete crate3;
	crate3 = nullptr;
	delete crate4;
	crate4 = nullptr;
	delete crate5;
	crate5 = nullptr;
	delete crate6;
	crate6 = nullptr;
	delete crate7;
	crate7 = nullptr;
	delete crate8;
	crate8 = nullptr;
	delete crate9;
	crate9 = nullptr;
	delete crate10;
	crate10 = nullptr;
	delete crate11;
	crate11 = nullptr;
	delete crate12;
	crate12 = nullptr;

}
