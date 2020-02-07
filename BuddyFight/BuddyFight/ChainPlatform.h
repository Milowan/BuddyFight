#pragma once
#include "Entity.h"
#include "EntityPool.h"
#include "Platform.h"



class ChainPlatform : public Entity
{
	private:
		//Vector2* mOriginPos;
		//Vector2* mNewPosLeft;
		//Vector2* mNewPosRight;

		Entity* mChainLink1;
		Entity* mChainLink2;
		Entity* mChainLink3;
		Entity* mChainLink4;
		Entity* mChainLink5;
		Platform* mChainPlatformBase;


	protected:

	public:

		//void Swing();

		ChainPlatform(float x, float y);
		~ChainPlatform();
};

