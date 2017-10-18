#include "GameplayObject.h"



GameplayObject::~GameplayObject()
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

void GameplayObject::HandleInput()
{
	D3DXVECTOR3 movementVector(0,0,0);
	//Do nothing when multiple keys pressed
	if ((GetAsyncKeyState('W') & 0x8000 && GetAsyncKeyState('D') & 0x8000)
		|| (GetAsyncKeyState('W') & 0x8000 && GetAsyncKeyState('A') & 0x8000)
		|| (GetAsyncKeyState('W') & 0x8000 && GetAsyncKeyState('S') & 0x8000)
		|| (GetAsyncKeyState('A') & 0x8000 && GetAsyncKeyState('S') & 0x8000)
		|| (GetAsyncKeyState('A') & 0x8000 && GetAsyncKeyState('D') & 0x8000)
		|| (GetAsyncKeyState('D') & 0x8000 && GetAsyncKeyState('S') & 0x8000))
	{
		velocity.x = 0;
		velocity.y = 0;
		return;
	}
	if (GetAsyncKeyState('W') & 0x8000)
	{
		if (dir != up)
		{
			dir = up;
			curFrame = 0;
		}
		else
		{
			curFrame++;
		}
		if (curFrame >= numFrames)
		{
			curFrame = 0;
		}
		movementVector.y -= 1;
	}
	if (GetAsyncKeyState('A') & 0x8000)
	{
		if (dir != left)
		{
			dir = left;
			curFrame = 0;
		}
		else
		{
			curFrame++;
		}
		if (curFrame >= numFrames)
		{
			curFrame = 0;
		}
		movementVector.x -= 1;
	}
	if (GetAsyncKeyState('D') & 0x8000)
	{
		if (dir != right)
		{
			dir = right;
			curFrame = 0;
		}
		else
		{
			curFrame++;
		}
		if (curFrame >= numFrames)
		{
			curFrame = 0;
		}
		movementVector.x = 1;
	}
	if (GetAsyncKeyState('S') & 0x8000)
	{
		if (dir != down)
		{
			dir = down;
			curFrame = 0;
		}
		else
		{
			curFrame++;
		}
		if (curFrame >= numFrames)
		{
			curFrame = 0;
		}
		movementVector.y += 1;
	}



	if (movementVector.x != 0 || movementVector.y != 0)
	{
		float angle = atan2(movementVector.y, movementVector.x);
		velocity.x = speed * cos(angle);
		velocity.y = speed * sin(angle);
	}
	else
	{
		velocity.x = 0;
		velocity.y = 0;
	}
	
}

Ninja * GameplayObject::getNinja() const
{
	return nin;
}


GameplayObject::GameplayObject(float x, float y, float rotation, float speed, float maxSpeed) : GameObject(x, y, rotation, speed, maxSpeed)
{
	//Creates accociated ninja
	nin = new Ninja();
	if (!nin)
	{
		MessageBox(NULL, "ERROR CREATING NINJA", NULL, NULL);
	}
}

