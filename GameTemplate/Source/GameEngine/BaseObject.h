#pragma once

#include <SDL.h>
#include <SDL_image.h>
#include "Texture.h"


class BaseObject
{
public:
	///MEMBERS
	//Position
	float posX;
	float posY;
	//Rotation
	float rotation;
	//Texture check boolean
	bool isTextureLoaded;
	SDL_Rect mCollider;

	///PROPERTIES
	BaseObject(float, float, float, std::string);
	virtual void Update() = 0;
	virtual SDL_Rect getCollider() = 0;
	virtual ~BaseObject();
};

