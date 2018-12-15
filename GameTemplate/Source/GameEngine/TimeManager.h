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
	

private:

	TimeManager();
	~TimeManager();

	Uint32 actualTime;
	SDL_Color textColor;
	float contador;
	Uint32 startTime;
	std::stringstream timeText;

};

