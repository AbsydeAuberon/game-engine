#pragma once

#include "Singleton.h"
#include <SDL.h>
#include <SDL_image.h>
#include <SDL_mixer.h>
#include <string>

class SoundManager : public Singleton<SoundManager>
{
	/*****************************************************************************/
	friend class Singleton<SoundManager>;
	/*****************************************************************************/

public:
	

	bool Init(void);

	Mix_Music   * getMainMusic (void) { return gMusic; }

	Mix_Chunk   * getSound1 (void) { return gScratch; }

	Mix_Chunk   * getSound2 (void) { return gHigh; }

	Mix_Chunk   * getSound3 (void) { return gMedium; }

	Mix_Chunk   * getSound4(void) { return gLow; }

	void Update(void);

	   
private:
	//The music that will be played
	Mix_Music * gMusic = Mix_LoadMUS("../../Media/beat.wav");

	//The sound effects that will be used
	Mix_Chunk * gScratch = Mix_LoadWAV("../../Media/scratch.wav");;
	Mix_Chunk * gHigh = Mix_LoadWAV("../../Media/high.wav");
	Mix_Chunk * gMedium = Mix_LoadWAV("../../Media/medium.wav");
	Mix_Chunk * gLow = Mix_LoadWAV("../../Media/low.wav");

	SoundManager();
	~SoundManager();
};

