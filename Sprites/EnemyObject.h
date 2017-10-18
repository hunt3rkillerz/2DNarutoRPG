#pragma once
#include "GameObject.h"
class EnemyObject : public GameObject
{
	public:
		EnemyObject(float x, float y, float rotation, float speed, float maxSpeed);
		virtual ~EnemyObject();
		virtual RECT getBoundaryBox(float gameTime);
	private:
		Ninja *nin;
};

