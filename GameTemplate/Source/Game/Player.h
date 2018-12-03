#pragma once
#include "BaseObject.h"


class Player : public BaseObject
{

public:
	Player(float x, float y, float rot, std::string path);
	~Player();
	virtual void Update();

};
