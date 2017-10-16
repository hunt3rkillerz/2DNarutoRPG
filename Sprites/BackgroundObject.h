#pragma once
#define _USE_MATH_DEFINES
#define NUMDIR 4
#include <cmath>

#include "GameSprite.h"
#include <string>
class BackgroundObject
{
public:
	BackgroundObject(float x, float y);
	virtual ~BackgroundObject();
	virtual bool Initialize(LPDIRECT3DDEVICE9 device, std::string fileName, int width, int height);
	virtual void Update(float gameTime);
	RECT getBoundaryBox() const;
	virtual void Draw(float gameTime);

	protected:
		std::string Name;
		std::string Description;

		//Physics
		D3DXVECTOR3 position, velocity;
		float rotation, speed;
	private:
		GameSprite *sprite;
		RECT boundaryBox;
};

