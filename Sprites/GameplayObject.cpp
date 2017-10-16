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

bool GameplayObject::Initialize(LPDIRECT3DDEVICE9 device, std::string fileName, int width, int height, int numFrames, int numRows)
{
	status = ObjectStatus::Active;

	if (!sprite)
	{
		sprite = new GameSprite();
		if (!sprite->Initialize(device, fileName, (width * numFrames), (height * numRows), numFrames, numRows))
		{
			return false;
		}
	}
	curFrame = 0;
	dir = 0;
	this->numFrames = numFrames;
	boundaryBox.right = (long)position.x;
	boundaryBox.bottom = (long)position.y;

	boundaryBox.left = (long)(position.x - width);
	boundaryBox.top = (long)(position.y - height);
	return true;
}

void GameplayObject::Update(float gameTime)
{
	if (status == ObjectStatus::Active)
	{
		position.x += velocity.x * gameTime;
		position.y += velocity.y * gameTime;
	}
}
/*
	Sets the row for the up down, left right control
*/
void GameplayObject::setUDLR(int up, int down, int left, int right)
{
	this->up = up;
	this->down = down;
	this->left = left;
	this->right = right;
}

void GameplayObject::Draw(float gameTime)
{
	if (sprite)
	{
		sprite->Draw(gameTime, position, curFrame, dir);
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

RECT GameplayObject::getBoundaryBox(float gameTime)
{
	boundaryBox.right = (long)(position.x+(velocity.x* gameTime));
	boundaryBox.bottom = (long)(position.y + (velocity.y* gameTime));
	boundaryBox.left = (long)(position.x + (velocity.x* gameTime));
	boundaryBox.top = (long)(position.y + (velocity.y* gameTime));
	return boundaryBox;
}

ObjectStatus GameplayObject::getStatus() const
{
	return status;
}

Ninja * GameplayObject::getNinja() const
{
	return nin;
}

int GameplayObject::getPosX() const
{
	return (int)position.x;
}

int GameplayObject::getPosY() const
{
	return (int)position.y;
}

void GameplayObject::setSpeed(float speed)
{
	if (speed >= 0 && speed <= maxSpeed)
	{
		this->speed = speed;
		velocity.x = cos(rotation) * speed;
		velocity.y = sin(rotation) * speed;
	}
}


GameplayObject::GameplayObject(float x, float y, float rotation, float speed, float maxSpeed)
{
	float twopi = (float)(M_PI * 2);
	position.x = x;
	position.y = y;
	position.z = 0;

	//Rotation safety
	if (rotation > twopi)
	{
		rotation = twopi;
	}
	if (rotation < 0)
	{
		rotation = 0;
	}

	//Speed safety
	if (speed > maxSpeed)
	{
		speed = maxSpeed;
	}
	if (speed < 0)
	{
		speed = 0;
	}

	this->rotation = rotation;
	this->speed = speed;

	velocity.x = cos(rotation) * speed;
	velocity.y = sin(rotation) * speed;
	velocity.z = 0;
	up = 0;
	right = 1;
	left = 2;
	down = 3;

	this->maxSpeed = maxSpeed;

	nin = new Ninja();
	if (!nin)
	{
		MessageBox(NULL, "ERROR CREATING NINJA", NULL, NULL);
	}
}

