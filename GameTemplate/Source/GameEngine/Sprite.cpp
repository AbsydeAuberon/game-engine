#include "Sprite.h"
#include "Texture.h"


Sprite::Sprite(std::string path, BaseObject* reference)
{
	texture->loadFromFile(path);
	object = reference;
}


Sprite::~Sprite()
{
}
