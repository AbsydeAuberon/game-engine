#include "TimeManager.h"


TimeManager::TimeManager()
{
	actualTime = 0;
	count = -1;
	startTime = 0;
	secondsPassed = -1;
}


TimeManager::~TimeManager()
{
}

void TimeManager::Update(void)
{
	actualTime = SDL_GetTicks();
	deltaTime = (float(actualTime - lastTime))/1000;
	if (actualTime > startTime + 1000)
	{
		secondsPassed++;
		count = -1;
		startTime = actualTime;
	}
	count++;
	lastTime = actualTime;
}

int TimeManager::getSecondsPassed() { return secondsPassed; }

float TimeManager::getDelta() { return deltaTime; }