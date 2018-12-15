#pragma once

#include "Singleton.h"
#include <vector>
#include "BaseObject.h"


class ObjectManager : public Singleton<ObjectManager>
{
	/**/
	friend class Singleton<ObjectManager>;
	std::vector<BaseObject*> ArrayObjects;

	/***/

private:
	ObjectManager();
	~ObjectManager();

public:

	void addObject(BaseObject *);
	void Update(void);
	void removeObject(BaseObject *);
	bool isMediaLoaded();

};