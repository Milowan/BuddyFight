#pragma once
#include "Platform.h"
#include "EntityPool.h"




class ChainPlatform : public Platform
{
	private:
		//Vector2* mOriginPos;
		//Vector2* mNewPosLeft;
		//Vector2* mNewPosRight;

		Entity* mChainLink1;
		Entity* mChainLink2;
		Entity* mChainPlatformBase;

	protected:

	public:

		//void Swing();

		ChainPlatform(float x, float y);
		~ChainPlatform();
};

