#pragma once
#include <d3dx9.h>
#include <string>
class GameSprite
{
	public:
		GameSprite();
		~GameSprite();

		//Sprite Functions
		bool Initialize(LPDIRECT3DDEVICE9 device, std::string filename, int width, int height, int columns, int rows);
		bool isInitialized();
		virtual void Draw(float gameTime, D3DXVECTOR3 position, int frameNumber, int dir);
	private:
		LPDIRECT3DTEXTURE9 tex;
		LPD3DXSPRITE sprite;

		D3DCOLOR color;
		bool initialized;
		double spriteWidth;
		double spriteHeight;
};

