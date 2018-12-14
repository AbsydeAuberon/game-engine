#include "Player.h"
#include "InputManager.h"
#include "RenderManager.h"

Player::Player(float x, float y, float rot, std::string path) :
	BaseObject::BaseObject(x, y, rot, path)
{
	velX = 0;
	velY = 0;
	maxSpeed = 10;
	speed = 0;
}


Player::~Player()
{
}

void Player::Update()
{
	move();
}

void Player::move()
{
	velX = 0;
	velY = 0;
	
	if (InputManager::GetInstance().GetKey(SDL_SCANCODE_UP)) {
		velY -= maxSpeed;
	}
	if (InputManager::GetInstance().GetKey(SDL_SCANCODE_DOWN)) {
		velY += maxSpeed;
	}
	if (InputManager::GetInstance().GetKey(SDL_SCANCODE_LEFT)) {
		velX -= maxSpeed;
	}
	if (InputManager::GetInstance().GetKey(SDL_SCANCODE_RIGHT)) {
		velX += maxSpeed;
	}

	//Move the dot left or right
	posX += velX;

	//If the dot went too far to the left or right
	if ((posX < 0) || (posX + PLAYER_WIDTH > RenderManager::SCREEN_WIDTH))
	{
		//Move back
		posX -= velX;
	}

	//Move the dot up or down
	posY += velY;

	//If the dot went too far up or down
	if ((posY < 0) || (posY + PLAYER_HEIGHT > RenderManager::SCREEN_HEIGHT))
	{
		//Move back
		posY -= velY;
	}
}

