#include <sstream>
#include <string>
#include "TimerEntity.h"



TimerEntity::TimerEntity(int time, float x, float y) :
	Entity(NULL, x, y),
	currentTime(time)
{
	stringstream ss;
	ss << "Time: " << time;
	texture = new Texture(ss.str(), "emulogic.TTF", 18, { 255, 255, 255 });
}

int TimerEntity::CountdownTimer()
{
	currentTime--;
	return currentTime;
}

void TimerEntity::Update()
{
	CountdownTimer();
}
