#include "Crate.h"

Crate::Crate(float x , float y) : 
	Platform(new Texture("TestLevelSpriteSheet.png",64,64,64,64),x,y)
{}

Crate::~Crate()
{}
