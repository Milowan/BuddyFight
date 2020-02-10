#include "Spikes.h"

Spikes::Spikes(float x, float y) :
	Entity(new Texture("TestLevelSpriteSheet.png", 128, 64, 64, 64), x, y)
{
	mask = CollisionMask::SPIKE;
}

Spikes::~Spikes()
{}

void Spikes::HandleCollision(Entity * other)
{
	Body* body;
	Player* player;
	if (other->GetMask() == BODY)
	{
		body = (Body*)other;
		player = (Player*)body->GetParent();
		player->TakeDamage(10);
		player->ResetAcceleration();
		player->AddForce(Vector2(0, -15));
	}
}

