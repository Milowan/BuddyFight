#include "AnimatedTexture.h" 
#include "SDL.h"
#include "EntityPool.h"
#include "TimerEntity.h"

class UIHud : public Entity
{
private:
	TimerEntity* mTime;

public:

	int Timer();

	UIHud(int time);
	~UIHud();

};
