#pragma once
class BaseObject
{
public:
	//MEMBERS
	static const int width;
	static const int height;

	//PROPERTIES
	BaseObject();
	virtual void Update();
	~BaseObject();
};

