#include "BackgroundObject.h"



BackgroundObject::BackgroundObject(float x, float y)
{
	position.x = x;
	position.y = y;
	position.z = 0;
}


BackgroundObject::~BackgroundObject()
{
}

bool BackgroundObject::Initialize(LPDIRECT3DDEVICE9 device, std::string fileName, int width, int height)
{
	if (!sprite)
	{
		sprite = new GameSprite();
		if (!sprite->Initialize(device, fileName, width, height, 1, 1))
		{
			return false;
		}
		boundaryBox.right = position.x +(width/ 1.8);
		boundaryBox.bottom = position.y + (height/ 1.8);

		boundaryBox.left = (position.x - (width / 1.2));
		boundaryBox.top = (position.y - (height/ 1.2));
	}
	return true;
}

void BackgroundObject::Update(float gameTime)
{
	
}

RECT BackgroundObject::getBoundaryBox() const
{
	return boundaryBox;
}

void BackgroundObject::Draw(float gameTime)
{
	if (sprite)
	{
		sprite->Draw(gameTime, position, 0, 0);
	}
}
