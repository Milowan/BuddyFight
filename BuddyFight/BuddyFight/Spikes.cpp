#include "Spikes.h"

Spikes::Spikes(float x, float y) :
	Entity(new Texture("TestLevelSpriteSheet.png", 192, 0, 64, 64), x, y)
{}

Spikes::~Spikes()
{}
