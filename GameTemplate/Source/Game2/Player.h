#pragma once
#include "BaseObject.h"
#include <SDL.h>

class Player : public BaseObject
{

public:
	///MEMBERS
	static const int PLAYER_WIDTH = 20;
	static const int PLAYER_HEIGHT = 20;


	///PROPERTIES
	Player(float x, float y, float rot, std::string path);
	~Player();
	virtual void Update();
	SDL_Rect getCollider();
	int getScore();
	void setScore(int);

private:

	int score;
	float velX;
	float velY;
	float maxSpeed;
	float speed;
	void move();
};
