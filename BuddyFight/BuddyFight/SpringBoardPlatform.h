#pragma once
#include "Platform.h"
#include "EntityPool.h"



class SpringBoardPlatform : public Platform
{
	private:
		Entity* mEntity1;
	protected:

		void Spring();

	public:


		SpringBoardPlatform(float x, float y);
		~SpringBoardPlatform();
};
