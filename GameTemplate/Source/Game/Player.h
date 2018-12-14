#pragma once
#include "BaseObject.h"


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

private:
	float velX;
	float velY;
	float maxSpeed;
	float speed;
	void move();
};
