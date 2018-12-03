#include "ObjectManager.h"
#include "BaseObject.h"


ObjectManager::ObjectManager()
{
}


ObjectManager::~ObjectManager()
{
}

void ObjectManager::addObject(BaseObject * referenceObject)
{
	ArrayObjects.push_back(referenceObject);
}

void ObjectManager::Update(void)
{
	for (size_t i = 0; i < ArrayObjects.size(); i++)
	{
		ArrayObjects[i]->Update();
	}
}

void ObjectManager::removeObject(BaseObject * referenceObject)
{
	for (size_t i = 0; i < ArrayObjects.size(); )
	{
		if (ArrayObjects[i] == referenceObject) {
			ArrayObjects.erase(ArrayObjects.begin + i);
		}
		else {
			++i;
		}
	}
}