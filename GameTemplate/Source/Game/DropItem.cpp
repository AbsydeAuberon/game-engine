#include "DropItem.h"
#include "BaseObject.h"
#include <cstdlib>
#include "RenderManager.h"
#include "TimeManager.h"
#include <time.h>

DropItem::DropItem(float x, float y, float rot, std::string path) :
	BaseObject::BaseObject(x, y, rot, path)
{	
	int maxWidth = RenderManager::SCREEN_WIDTH - OBJECT_WIDTH;
	int maxHeight = RenderManager::SCREEN_HEIGHT - OBJECT_HEIGHT;
	posX = rand() % (maxWidth);
	posY = rand() % (maxHeight);
	mCollider.w = OBJECT_WIDTH;
	mCollider.h = OBJECT_HEIGHT;
}


DropItem::~DropItem()
{

}


void DropItem::Update()
{
	mCollider.x = posX;
	mCollider.y = posY;

}

SDL_Rect DropItem::getCollider() { return mCollider; }