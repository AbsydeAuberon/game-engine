#include "Sprite.h"
#include "Texture.h"


Sprite::Sprite(std::string path, BaseObject* reference)
{
	texture = new LTexture();
	texture->loadFromFile(path);
	
	
	if (texture == NULL)
	{
		reference->isTextureLoaded = false;
	}

	object = reference;
}


Sprite::~Sprite()
{
	//texture->free();
}

void Sprite::Render()
{
	texture->render(object->posX, object->posY);
}