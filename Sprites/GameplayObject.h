#pragma once
#define _USE_MATH_DEFINES
#define NUMDIR 4
#include <cmath>

#include "GameSprite.h"
#include "../GameBackend/Ninja.h"
#include <string>

enum class ObjectStatus {Active, Dying, Dead};
class GameplayObject
{
	public:
		GameplayObject(float x, float y, float rotation, float speed, float maxSpeed);
		~GameplayObject();

		virtual bool Initialize(LPDIRECT3DDEVICE9 device, std::string fileName, int width, int height, int numFrames, int numRows);
		virtual void Update(float gameTime);
		virtual void setUDLR(int up, int down, int left, int right);
		virtual void Draw(float gameTime);
		virtual void HandleInput();
		RECT getBoundaryBox(float gameTime);
		ObjectStatus getStatus() const;
		Ninja* getNinja() const;
		int getPosX() const;
		int getPosY() const;
		void setSpeed(float speed);

	protected:
		std::string Name;
		std::string Description;

		//Physics
		D3DXVECTOR3 position, velocity;
		float rotation, speed;
	private:
		Ninja *nin;
		ObjectStatus status;
		GameSprite *sprite;
		RECT boundaryBox;
		float maxSpeed;
		int curFrame, dir, numFrames;
		int up, down, left, right;
};

