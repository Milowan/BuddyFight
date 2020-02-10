#include "Spikes.h"

Spikes::Spikes(float x, float y) :
	Entity(new Texture("TestLevelSpriteSheet.png", 128, 64, 64, 64), x, y)
{
	mask = CollisionMask::SPIKE;
}

Spikes::~Spikes()
{}

//void Spikes::HandleCollision(Entity * other)
//{
//	if (other == player)
//	{
//		player->TakeDamage(10);
//		SetForwardVector(Vector2(forwardVector.x, -1));
//		grounded = false;
//		player->AddForce(Vector2(0, -15));
//	}
//}

