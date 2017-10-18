#include "GameObject.h"



GameObject::~GameObject()
{
	if (sprite)
	{
		delete sprite;
		sprite = 0;
	}
}

bool GameObject::Initialize(LPDIRECT3DDEVICE9 device, std::string fileName, int width, int height, int numFrames, int numRows)
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
	this->width = width;
	this->height = height;
	return true;
}

void GameObject::Update(float gameTime)
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
void GameObject::setUDLR(int up, int down, int left, int right)
{
	this->up = up;
	this->down = down;
	this->left = left;
	this->right = right;
}

void GameObject::Draw(float gameTime)
{
	if (sprite)
	{
		sprite->Draw(gameTime, position, curFrame, dir);
	}
}

RECT GameObject::getBoundaryBox(float gameTime)
{
	boundaryBox.right = (long)(position.x + (velocity.x* gameTime));
	boundaryBox.bottom = (long)(position.y + (velocity.y* gameTime));
	boundaryBox.left = (long)(position.x + (velocity.x* gameTime) - (width/2));
	boundaryBox.top = (long)(position.y + (velocity.y* gameTime) - (height/2));
	return boundaryBox;
}

ObjectStatus GameObject::getStatus() const
{
	return status;
}


int GameObject::getPosX() const
{
	return (int)position.x;
}

int GameObject::getPosY() const
{
	return (int)position.y;
}

void GameObject::setSpeed(float speed)
{
	if (speed >= 0 && speed <= maxSpeed)
	{
		this->speed = speed;
		velocity.x = cos(rotation) * speed;
		velocity.y = sin(rotation) * speed;
	}
}


GameObject::GameObject(float x, float y, float rotation, float speed, float maxSpeed)
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
}

