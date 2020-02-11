#include "Crate.h"

Crate::Crate(float x , float y) : 
	Platform(new Texture("TestLevelSpriteSheet.png",64,64,64,64),x,y)
{
	texture->SetHeight(Graphics::BLOCK_HEIGHT * 2);
	texture->SetWidth(Graphics::BLOCK_WIDTH * 2);
}

Crate::~Crate()
{}
