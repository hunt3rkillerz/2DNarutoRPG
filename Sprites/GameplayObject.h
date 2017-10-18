#pragma once
#define _USE_MATH_DEFINES
#define NUMDIR 4
#include <cmath>

#include "GameObject.h"

class GameplayObject : public GameObject
{
	public:
		GameplayObject(float x, float y, float rotation, float speed, float maxSpeed);
		virtual ~GameplayObject();
		
		void HandleInput();
		Ninja* getNinja() const;

	protected:
	private:
		Ninja *nin;
};

