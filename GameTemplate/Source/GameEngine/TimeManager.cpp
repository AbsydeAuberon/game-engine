#include "TimeManager.h"


TimeManager::TimeManager()
{
	actualTime = 0;
	contador = 0.0f;
	startTime = 0;
	//SDL_Color textColor = { 0, 0, 0, 255 };
	//std::stringstream timeText;

}


TimeManager::~TimeManager()
{
}

void TimeManager::Update(void)
{
	actualTime = SDL_GetTicks();

	if (actualTime > startTime + 1000)
	{
		
		printf(" The actual time is: %f", contador);
		contador = 0;
		startTime = actualTime;
		//float timeInSeconds = actualTime / 1000;

	}
	contador++;

	
}