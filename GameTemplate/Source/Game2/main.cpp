//Using SDL, SDL_image, standard IO, and strings
#include <SDL.h>
#include <SDL_image.h>
#include <SDL_mixer.h>
#include <stdio.h>
#include <string>

#include "Texture.h"

#include "TimeManager.h"
#include "InputManager.h"
#include "RenderManager.h"
#include "ObjectManager.h"
#include "SoundManager.h"
#include "Player.h"
#include "DropItem.h"
#include <ctime>
#include <Windows.h>

bool checkCollision(SDL_Rect a, SDL_Rect b)
{
	//The sides of the rectangles
	int leftA, leftB;
	int rightA, rightB;
	int topA, topB;
	int bottomA, bottomB;

	//Calculate the sides of rect A
	leftA = a.x;
	rightA = a.x + a.w;
	topA = a.y;
	bottomA = a.y + a.h;

	//Calculate the sides of rect B
	leftB = b.x;
	rightB = b.x + b.w;
	topB = b.y;
	bottomB = b.y + b.h;

	//If any of the sides from A are outside of B
	if (bottomA <= topB)
	{
		return false;
	}

	if (topA >= bottomB)
	{
		return false;
	}

	if (rightA <= leftB)
	{
		return false;
	}

	if (leftA >= rightB)
	{
		return false;
	}

	//If none of the sides from A are outside B
	return true;
}



int main( int argc, char* args[] )
{
	int lives = 6;
	int spawnTime = 0;


	srand(time(NULL));

	TimeManager::CreateSingleton();
	
	InputManager::CreateSingleton();

	RenderManager::CreateSingleton();

	SoundManager::CreateSingleton();
	
	


	//Start up SDL and create window
	if( !RenderManager::GetInstance().Init() )
	{
		printf( "Failed to initialize!\n" );
	}
	else
	{


		ObjectManager::CreateSingleton();

		BaseObject * player = new Player(RenderManager::SCREEN_WIDTH/2,
										 RenderManager::SCREEN_HEIGHT - Player::PLAYER_HEIGHT,
										 0.0f, "dot.bmp");

		ObjectManager::GetInstance().addObject(player);





		//Load media
		if(!ObjectManager::GetInstance().isMediaLoaded())
		{
			printf( "Failed to load media!\n" );
		}
		else
		{	
			//Main loop flag
			bool quit = false;

			//Event handler
			SDL_Event e;

			//The dot that will be moving around on the screen

			//While application is running
			while( !quit )
			{
				//Handle events on queue
				while( SDL_PollEvent( &e ) != 0 )
				{
					

					//User requests quit
					if( e.type == SDL_QUIT )
					{
						quit = true;
					}

				}

				TimeManager::GetInstance().Update();

				if (TimeManager::GetInstance().getSecondsPassed() >= spawnTime)
				{
					ObjectManager::GetInstance().addObject(new DropItem(0.0f, 0.0f, 0.0f, "item.png"));  //Adds a new drop each two seconds
					spawnTime += 2;
				}

				InputManager::GetInstance().Update();
				ObjectManager::GetInstance().Update();
				
				//some kind of physics update
				for (int i = 1; i < ObjectManager::GetInstance().getArrayLength(); i++)
				{
					Player * pl = (Player*)ObjectManager::GetInstance().getObjectFromIndex(0);
					DropItem * di = (DropItem*)ObjectManager::GetInstance().getObjectFromIndex(i);
					
					if (i != 1) {
						if (checkCollision(pl->getCollider(), di->getCollider()))
						{
							int score = pl->getScore() + 1;
							pl->setScore(score);
							printf("\nSCORE: %i", pl->getScore());
							ObjectManager::GetInstance().removeObject(di);
						}

						if (di->posY > RenderManager::SCREEN_HEIGHT
							&& di->posY < RenderManager::SCREEN_HEIGHT + 1)
						{
							lives--;
							printf("\nYOU HAVE ONLY %i LIVES!", lives);
							ObjectManager::GetInstance().removeObject(di);
						}

						if (lives == 0) {
							quit = true;
						}
					}
					
				}

				
				RenderManager::GetInstance().Update();
				SoundManager::GetInstance().Update();
				

				if (quit == true)
				{
					Player * pl = (Player*)ObjectManager::GetInstance().getObjectFromIndex(0);
					printf("\nYOU LOSE!! YOU GET %i SCORE!", pl->getScore());
					Sleep(1000);
				}


			}
		}
	}

	//Free resources and close SDL
	return 0;
}

