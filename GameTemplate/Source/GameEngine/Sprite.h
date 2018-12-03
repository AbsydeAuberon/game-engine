#pragma once

#include <Texture.h>
#include <string>
#include "BaseObject.h"

class Sprite
{
public:
	///MEMBERS

	LTexture * texture;
	BaseObject * object;

	///PROPERTIES
	Sprite(std::string, BaseObject*);
	~Sprite();
};

