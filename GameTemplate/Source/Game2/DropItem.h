#pragma once
#include "BaseObject.h"
class DropItem : public BaseObject
{
public:
	///MEMBERS
	static const int OBJECT_WIDTH = 20;
	static const int OBJECT_HEIGHT = 20;


	///PROPERTIES
	DropItem(float x, float y, float rot, std::string path);
	~DropItem();
	virtual void Update();
	SDL_Rect getCollider();

private:
	
	float maxSpeed;
};

