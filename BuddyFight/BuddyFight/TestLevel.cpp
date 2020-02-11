#include "TestLevel.h"

TestLevel::TestLevel() :
	Scene(new Texture("Background.png"))
{}



void TestLevel::InitializeScene()
{
	mTimer = Timer::GetInstance();
	mInputManager = InputManager::GetInstance();
	mAudioManager = AudioManager::GetInstance();
	mSceneManager = SceneManager::GetInstance();

	pool = EntityPool::GetInstance();
	bPool = BulletPool::GetInstance();

	stringstream ss;
	ss << "Time: " << currentTime;
	clock = new Entity(new Texture(ss.str(), "emulogic.TTF", 18, { 230, 230, 230 }), Graphics::SCREEN_WIDTH * 0.5f, Graphics::SCREEN_HEIGHT * 0.1f);
	pool->AddEntity(clock);

	player1 = new Player(true);
	player1->SetPosition(player1->GetPosition());
	player1->SetScale(Vector2(0.25, 0.25));
	pool->AddEntity(player1);

	player2 = new Player(false);
	player2->SetPosition(player2->GetPosition());
	player2->SetScale(Vector2(0.25, 0.25));
	pool->AddEntity(player2);

	chainPlatform1 = new ChainPlatform(1 * Graphics::BLOCK_WIDTH, 1 * Graphics::BLOCK_HEIGHT);
	pool->AddEntity(chainPlatform1);
	chainPlatform2 = new ChainPlatform(31 * Graphics::BLOCK_WIDTH, 1 * Graphics::BLOCK_HEIGHT);
	pool->AddEntity(chainPlatform2);

	basePlatform = new BasePlatform(20 * Graphics::BLOCK_WIDTH, 18 * Graphics::BLOCK_HEIGHT);
	pool->AddEntity(basePlatform);

	hingePlatform1 = new HingePlatformEast(7 * Graphics::BLOCK_WIDTH, 9* Graphics::BLOCK_HEIGHT);
	pool->AddEntity(hingePlatform1);
	hingePlatform2 = new HingePlatformWest(33 * Graphics::BLOCK_WIDTH, 9 * Graphics::BLOCK_HEIGHT);
	pool->AddEntity(hingePlatform2);

	crate1 = new Crate(21 * Graphics::BLOCK_WIDTH, 16 * Graphics::BLOCK_HEIGHT);
	pool->AddEntity(crate1);
	crate2 = new Crate(19 * Graphics::BLOCK_WIDTH, 16 * Graphics::BLOCK_HEIGHT);
	pool->AddEntity(crate2);
	crate3 = new Crate(17 * Graphics::BLOCK_WIDTH, 16 * Graphics::BLOCK_HEIGHT);
	pool->AddEntity(crate3);
	crate4 = new Crate(15 * Graphics::BLOCK_WIDTH, 16 * Graphics::BLOCK_HEIGHT);
	pool->AddEntity(crate4);
	crate5 = new Crate(23 * Graphics::BLOCK_WIDTH, 16 * Graphics::BLOCK_HEIGHT);
	pool->AddEntity(crate5);
	crate6 = new Crate(25 * Graphics::BLOCK_WIDTH, 16 * Graphics::BLOCK_HEIGHT);
	pool->AddEntity(crate6);
	crate7 = new Crate(23 * Graphics::BLOCK_WIDTH, 14 * Graphics::BLOCK_HEIGHT);
	pool->AddEntity(crate7);
	crate8 = new Crate(21 * Graphics::BLOCK_WIDTH, 14 * Graphics::BLOCK_HEIGHT);
	pool->AddEntity(crate8);
	crate9 = new Crate(19 * Graphics::BLOCK_WIDTH, 14 * Graphics::BLOCK_HEIGHT);
	pool->AddEntity(crate9);
	crate10 = new Crate(17 * Graphics::BLOCK_WIDTH, 14 * Graphics::BLOCK_HEIGHT);
	pool->AddEntity(crate10);
	crate11 = new Crate(21 * Graphics::BLOCK_WIDTH, 12 * Graphics::BLOCK_HEIGHT);
	pool->AddEntity(crate11);
	crate12 = new Crate(19 * Graphics::BLOCK_WIDTH, 12 * Graphics::BLOCK_HEIGHT);
	pool->AddEntity(crate12);

	//Spikes are causing an error in the vector class i cant figure out, hence why i just commented them out for now. 

	//spike1 = new Spikes(1 * Graphics::BLOCK_WIDTH, 20 * Graphics::BLOCK_HEIGHT);
	//pool->AddEntity(spike1);
	//spike2 = new Spikes(2 * Graphics::BLOCK_WIDTH, 20 * Graphics::BLOCK_HEIGHT);
	//pool->AddEntity(spike2);
	//spike3 = new Spikes(3 * Graphics::BLOCK_WIDTH, 20 * Graphics::BLOCK_HEIGHT);
	//pool->AddEntity(spike3);
	//spike4 = new Spikes(4 * Graphics::BLOCK_WIDTH, 20 * Graphics::BLOCK_HEIGHT);
	//pool->AddEntity(spike4);
	//spike5 = new Spikes(5 * Graphics::BLOCK_WIDTH, 20 * Graphics::BLOCK_HEIGHT);
	//pool->AddEntity(spike5);
	//spike6 = new Spikes(6 * Graphics::BLOCK_WIDTH, 20 * Graphics::BLOCK_HEIGHT);
	//pool->AddEntity(spike6);
	//spike7 = new Spikes(7 * Graphics::BLOCK_WIDTH, 20 * Graphics::BLOCK_HEIGHT);
	//pool->AddEntity(spike7);
	//spike8 = new Spikes(8 * Graphics::BLOCK_WIDTH, 20 * Graphics::BLOCK_HEIGHT);
	//pool->AddEntity(spike8);
	//spike9 = new Spikes(32 * Graphics::BLOCK_WIDTH, 20 * Graphics::BLOCK_HEIGHT);
	//pool->AddEntity(spike9);
	//spike10 = new Spikes(33 * Graphics::BLOCK_WIDTH, 20 * Graphics::BLOCK_HEIGHT);
	//pool->AddEntity(spike10);
	//spike11 = new Spikes(34 * Graphics::BLOCK_WIDTH, 20 * Graphics::BLOCK_HEIGHT);
	//pool->AddEntity(spike11);
	//spike12 = new Spikes(35 * Graphics::BLOCK_WIDTH, 20 * Graphics::BLOCK_HEIGHT);
	//pool->AddEntity(spike12);
	//spike13 = new Spikes(36 * Graphics::BLOCK_WIDTH, 20 * Graphics::BLOCK_HEIGHT);
	//pool->AddEntity(spike13);
	//spike14 = new Spikes(37 * Graphics::BLOCK_WIDTH, 20 * Graphics::BLOCK_HEIGHT);
	//pool->AddEntity(spike14);
	//spike15 = new Spikes(38 * Graphics::BLOCK_WIDTH, 20 * Graphics::BLOCK_HEIGHT);
	//pool->AddEntity(spike15);
	//spike16 = new Spikes(39 * Graphics::BLOCK_WIDTH, 20 * Graphics::BLOCK_HEIGHT);
	//pool->AddEntity(spike16);
	//spike17 = new Spikes(40 * Graphics::BLOCK_WIDTH, 20 * Graphics::BLOCK_HEIGHT);
	//pool->AddEntity(spike17);

	// Weapons
	mPistol = new Pistol();
	pool->AddEntity(mPistol);
	mSword = new Sword();
	pool->AddEntity(mSword);
	mSpear = new Spear();
	pool->AddEntity(mSpear);

	TestLevelAudio();
}

void TestLevel::TestLevelAudio()
{
	mAudioManager->PlayMusic("Audio/Fight.wav", 10);
}

void TestLevel::UpdateScene()
{
	chainPlatform1->UpdateChildren();

	if (!player1->GetAlive())
	{
		if (mInputManager->KeyDown(SDL_SCANCODE_RETURN))
		{
			mSceneManager->ChangeScene(new TestLevel());
		}
	}
	CountdownTimer();
}

int TestLevel::CountdownTimer()
{
	for (int i = 0; i < maxTime; i++)
	{
		i++;
		currentTime--;
	}
	return currentTime;
}

TestLevel::~TestLevel()
{
	mTimer = nullptr;
	mInputManager = nullptr;
	mAudioManager = nullptr;
	mSceneManager = nullptr;


	delete player1;
	player1 = nullptr;

	delete clock;
	clock = nullptr;

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

	//delete spike1;
	//spike1 = nullptr;
	//delete spike2;
	//spike2 = nullptr;
	//delete spike3;
	//spike3 = nullptr;
	//delete spike4;
	//spike4 = nullptr;
	//delete spike5;
	//spike5 = nullptr;
	//delete spike6;
	//spike6 = nullptr;
	//delete spike7;
	//spike7 = nullptr;
	//delete spike8;
	//spike8 = nullptr;
	//delete spike9;
	//spike9 = nullptr;
	//delete spike10;
	//spike10 = nullptr;
	//delete spike11;
	//spike11 = nullptr;
	//delete spike12;
	//spike12 = nullptr;
	//delete spike13;
	//spike13 = nullptr;
	//delete spike14;
	//spike14 = nullptr;
	//delete spike15;
	//spike15 = nullptr;
	//delete spike16;
	//spike16 = nullptr;
	//delete spike17;
	//spike17 = nullptr;


}
