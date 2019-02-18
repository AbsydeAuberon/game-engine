#include "BaseObject.h"
#include "RenderManager.h"

BaseObject::BaseObject(float x, float y, float rot, std::string path)
{
	posX = x;
	posY = y;
	rotation = rot;
	isTextureLoaded = true;
	RenderManager::GetInstance().addSprite(path, this);
}

BaseObject::~BaseObject()
{
}

