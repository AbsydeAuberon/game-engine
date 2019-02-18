#include "Player.h"
#include "InputManager.h"
#include "RenderManager.h"
#include "TimeManager.h"

Player::Player(float x, float y, float rot, std::string path) :
	BaseObject::BaseObject(x, y, rot, path)
{
	score = 0;
	velX = 0;
	velY = 0;
	mCollider.w = PLAYER_WIDTH;
	mCollider.h = PLAYER_HEIGHT;
	maxSpeed = 200;
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
		velY -= maxSpeed * TimeManager::GetInstance().getDelta();
	}
	if (InputManager::GetInstance().GetKey(SDL_SCANCODE_DOWN)) {
		velY += maxSpeed * TimeManager::GetInstance().getDelta();
	}
	if (InputManager::GetInstance().GetKey(SDL_SCANCODE_LEFT)) {
		velX -= maxSpeed * TimeManager::GetInstance().getDelta();
	}
	if (InputManager::GetInstance().GetKey(SDL_SCANCODE_RIGHT)) {
		velX += maxSpeed * TimeManager::GetInstance().getDelta();
	}

	//Move the dot left or right
	posX += velX;
	mCollider.x = posX;

	//If the dot went too far to the left or right
	if ((posX < 0) || (posX + PLAYER_WIDTH > RenderManager::SCREEN_WIDTH))
	{
		//Move back
		posX -= velX;
	}

	//Move the dot up or down
	posY += velY;
	mCollider.y = posY;

	//If the dot went too far up or down
	if ((posY < 0) || (posY + PLAYER_HEIGHT > RenderManager::SCREEN_HEIGHT))
	{
		//Move back
		posY -= velY;
	}
}

SDL_Rect Player::getCollider() { return mCollider; }

int Player::getScore() { return score; }
void Player::setScore(int value) { score = value; }