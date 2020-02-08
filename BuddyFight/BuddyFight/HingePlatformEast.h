#pragma once
#include "Platform.h"




class HingePlatformEast : public Platform
{
	private:

		float startRot = 0;
		float endRot = 90;
		float rotSpeed;
		float currentRot;
		bool returning = false;

		Entity* mHingePlatformBase;

	protected:


	public:

		void SetRot();
		void Animate();

		virtual void Update() override;

		HingePlatformEast(float x, float y, float speed = 0.5f);
		~HingePlatformEast();

};

