#pragma once
#include <SDL.h>




class Timer
{
private:

	static Timer* instance;
	unsigned int startTick;
	unsigned int elapsedTicks;
	float deltaTime;
	float timeScale;

public:

	static Timer* GetInstance();
	static void Release();

	void Reset();
	float GetDeltaTime();

	void SetTimeScale(float scale);
	float GetTimeScale();

	void Update();
};

