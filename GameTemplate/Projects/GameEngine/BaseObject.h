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
	float rotX;
	float rotY;
	//Texture
	LTexture * texture;

	//PROPERTIES
	BaseObject(float, float, float, float);
	virtual void Update() = 0;
	virtual ~BaseObject();
};

