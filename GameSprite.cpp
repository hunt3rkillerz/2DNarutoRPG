#include "GameSprite.h"



GameSprite::GameSprite()
{
	color = D3DCOLOR_ARGB(255, 255, 255, 255);
	initialized = false;
}

GameSprite::~GameSprite()
{
	if (sprite)
	{
		sprite->Release();
		sprite = 0;
	}
	if (tex)
	{
		tex->Release();
		tex = 0;
	}
}

bool GameSprite::Initialize(LPDIRECT3DDEVICE9 device, std::string filename, int width, int height, int col, int row)
{
	if (!SUCCEEDED(D3DXCreateTextureFromFileEx(device, filename.c_str(), width, height, D3DX_DEFAULT, 0, D3DFMT_UNKNOWN,
		D3DPOOL_MANAGED, D3DX_DEFAULT, D3DX_DEFAULT, 0, NULL, NULL, &tex)))
	{
		std::string s = "Issue creating texture";
		MessageBox(NULL, s.c_str(), NULL, NULL);
		return false;
	}
	 //Creating Sprite
	if (!SUCCEEDED(D3DXCreateSprite(device, &sprite)))
	{
		std::string s = "Sprite creation failed";
		MessageBox(NULL, s.c_str(), NULL, NULL);
		return false;
	}
	spriteHeight = height / row;
	spriteWidth = width / col;
	initialized = true;

	return true;
}

bool GameSprite::isInitialized()
{
	return initialized;
}

void GameSprite::Draw(float gameTime, D3DXVECTOR3 position, int frameNumber, int dir)
{
	if (sprite && tex)
	{
		RECT sourceRectangle;
		sourceRectangle.left = ((long)spriteWidth * frameNumber);
		sourceRectangle.right = ((long)spriteWidth * frameNumber)+(long) spriteWidth;
		sourceRectangle.top = ((long)spriteHeight * dir);
		sourceRectangle.bottom = ((long)spriteHeight * dir)+(long) spriteHeight;
		sprite->Begin(D3DXSPRITE_ALPHABLEND | D3DXSPRITE_OBJECTSPACE);

		sprite->Draw(tex, &sourceRectangle, NULL, &position, color);
	
		sprite->End();
	}
}
