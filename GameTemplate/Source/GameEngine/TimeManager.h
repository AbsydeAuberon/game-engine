#pragma once

#include "Singleton.h"
#include <SDL.h>
#include <SDL_image.h>
#include <stdio.h>
#include <string>
#include <sstream>
#include <stdlib.h>

class TimeManager : public Singleton<TimeManager>
{

	friend class Singleton<TimeManager>;

public:

	
	
	void Update(void);
	float getDelta();
	int getSecondsPassed();

private:

	TimeManager();
	~TimeManager();

	Uint32 lastTime;
	Uint32 actualTime;
	SDL_Color textColor;
	float deltaTime;
	int count;
	Uint32 startTime;
	int secondsPassed;

};

