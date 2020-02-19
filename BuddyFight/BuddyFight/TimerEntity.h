#pragma once
#include "Entity.h"

class TimerEntity :
	public Entity
{
private:

	int startTime = 2000;
	int currentTime;

public:

	TimerEntity(int time, float x = 0.0f, float y = 0.0f);

	int CountdownTimer();
	void Update() override;

};

