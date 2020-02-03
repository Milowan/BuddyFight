#include "Timer.h"





Timer* Timer::instance = NULL;

Timer* Timer::GetInstance()
{
	if (instance == NULL)
		instance = new Timer();

	return instance;
}

void Timer::Release()
{
	delete instance;
	instance = NULL;
}

void Timer::Reset()
{
	startTick = SDL_GetTicks();
	elapsedTicks = 0;
	deltaTime = 0.0f;
}

float Timer::GetDeltaTime()
{
	return deltaTime;
}

void Timer::SetTimeScale(float scale)
{
	timeScale = scale;
}

float Timer::GetTimeScale()
{
	return timeScale;
}

void Timer::Update()
{
	elapsedTicks = SDL_GetTicks() - startTick;
	deltaTime = elapsedTicks * 0.001f;
}