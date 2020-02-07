#include "Spikes.h"

Spikes::Spikes(float x, float y) :
	Entity(new Texture("TestLevelSpriteSheet.png", 128, 64, 64, 64), x, y)
{
	mask = CollisionMask::SPIKE;
}

Spikes::~Spikes()
{}
