#pragma once
#include "Platform.h"




class HingePlatform : public Platform
{
	private:

		Entity* mHingePlatformBase;

	protected:

		//void Hinge();

	public:



		HingePlatform(float x, float y);
		~HingePlatform();

};

