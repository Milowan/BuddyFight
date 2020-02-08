#pragma once
#include "Platform.h"





class BasePlatform : public Platform
{
	private:

		Entity* peg1;
		Entity* peg2;

	protected:

	public:



		BasePlatform(float x, float y);
		~BasePlatform();

};

