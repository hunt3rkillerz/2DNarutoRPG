#include "EnemyObject.h"



EnemyObject::~EnemyObject()
{
	if (sprite)
	{
		delete sprite;
		sprite = 0;
	}
	if (nin)
	{
		delete nin;
		nin = 0;
	}
}


EnemyObject::EnemyObject(float x, float y, float rotation, float speed, float maxSpeed) : GameObject(x, y, rotation, speed, maxSpeed)
{
	velocity.x = 0;
	velocity.y = 0;
	nin = new Ninja();
	if (!nin)
	{
		MessageBox(NULL, "ERROR CREATING NINJA", NULL, NULL);
	}
}

RECT EnemyObject::getBoundaryBox(float gameTime)
{
	boundaryBox.right = (long)(position.x + (velocity.x* gameTime));
	boundaryBox.bottom = (long)(position.y + (velocity.y* gameTime) + (height / 4.5));
	boundaryBox.left = (long)(position.x + (velocity.x* gameTime) - (width / 2));
	boundaryBox.top = (long)(position.y + (velocity.y* gameTime) - (height / 2));
	return boundaryBox;
}

