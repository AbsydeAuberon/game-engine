#include "SoundManager.h"

/*****************************************************************************/

SoundManager::SoundManager(void)
{
}

/*****************************************************************************/

SoundManager::~SoundManager(void)
{
	//Free the sound effects
	Mix_FreeChunk(gScratch);
	Mix_FreeChunk(gHigh);
	Mix_FreeChunk(gMedium);
	Mix_FreeChunk(gLow);
	gScratch = NULL;
	gHigh = NULL;
	gMedium = NULL;
	gLow = NULL;

	//Free the music
	Mix_FreeMusic(gMusic);
	gMusic = NULL;

	//Quit SDL subsystems
	Mix_Quit();
	SDL_Quit();
}

bool SoundManager::Init(void)
{
	//Initialization flag
	bool success = true;

	if (SDL_Init(SDL_INIT_AUDIO) < 0)
	{
		//Initialize SDL
		printf("SDL could not initialize! SDL Error: %s\n", SDL_GetError());
		success = false;
	}
	else
	{
		//Initialize SDL_mixer
		if (Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 2048) < 0)
		{
			printf("SDL_mixer could not initialize! SDL_mixer Error: %s\n", Mix_GetError());
			success = false;
		}

	}

	return success;
}

void SoundManager::Update(void)
{
	Mix_PlayMusic(gMusic, -1 );
}
/*****************************************************************************/




