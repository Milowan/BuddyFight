#pragma once
#include "Platform.h"




class HingePlatformWest : public Platform
{
private:

	float startRot = 270;
	float endRot = 360;
	float rotSpeed;
	float currentRot = 270;
	bool returning = false;

	Entity* mHingePlatformBase1;
	Entity* mHingePlatformBase2; 
	Entity * mHingePlatformBase3;

protected:


public:

	void SetRot();
	void Animate();

	virtual void Update() override;

	HingePlatformWest(float x, float y, float speed = 0.5f);
	~HingePlatformWest();

};

