#include "Game.h"



Game::Game()
{

}

Game::~Game()
{
	if (camera) 
	{ 
		delete camera; 
		camera = nullptr; 
	}
	if (player)
	{
		delete player;
		player = 0;
	}
	if (gDevice)
	{
		delete gDevice;
		gDevice = 0;
	}
	for (int i = 0; i < (int)background.size(); i++)
	{
		if (background[i])
		{
			delete background[i];
			background[i] = 0;
		}
	}
	for (int i = 0; i < (int)tree.size(); i++)
	{
		if (tree[i])
		{
			delete tree[i];
			tree[i] = 0;
		}
	}
	if (font)
	{
		font->Release();
		font = 0;
	}

}

bool Game::Initialize(HWND hWnd, int w, int h)
{
	gDevice = new GraphicsDevice;
	if (!gDevice->Initialize(hWnd, true))
	{
		return false;
	}
	//Init game camera
	camera = new Camera(w, h, 0, DirectX::XMFLOAT3(1.0f, 1.0f, 1.0f));

	//Uses tile map to build screen
	//Resize tiles so 1 footstep = 1 tile?
	//This will remove the need to worry about diagonals?
	for (int y = 0; y < 15; y++)
	{
		for (int x = 0; x < 25; x++)
		{
			switch (map[y][x])
			{
				case '@':
				{
					player = new GameplayObject((float)(x*64), (float)(y*72), (float)M_PI_4, (float) 120.0f, 120.0f);
					if (!player->Initialize(gDevice->device, "Images/link.png", 64, 72, 12, 4))
					{
						return false;
					}
					player->setUDLR(0, 2, 3, 1);
				}
				break;
				case '#':
				{
					BackgroundObject *t = new BackgroundObject((float)(x * 64), (float)(y * 72));
					if (!t->Initialize(gDevice->device, "images/tree.png", 64, 72))
					{
						return false;
					}
					tree.push_back(t);
				}
				break;
				case '1':
				{
					BackgroundObject *t = new BackgroundObject((float)(x * 64), (float)(y * 72));
					if (!t->Initialize(gDevice->device, "images/person.png", 64, 72))
					{
						return false;
					}
					tree.push_back(t);
				}
				break;
				case ' ':
				{
					
				}
				break;
			}
			BackgroundObject *grass = new BackgroundObject((float)(x * 64), (float)(y * 72));
			if (!grass->Initialize(gDevice->device, "images/PokemonGrass.png", 64, 72))
			{
				return false;
			}
			background.push_back(grass);
		}
	}
	frameLimit = 0;
	gameTime = new GameTime();
	if (!gameTime->Initialize())
	{
		return false;
	}
	return true;
}

void Game::Run()
{
	gameTime->Update();

	Update(gameTime->elapsedGameTime);
	Draw(gameTime->elapsedGameTime);
}

void Game::Update(float gameTime)
{
	if (GetAsyncKeyState(VK_ESCAPE) & 0x8000)
	{
		PostQuitMessage(0);
	}
	if (GetAsyncKeyState('E') & 0x8000)
	{
		Menu(gameTime);
	}
	
	
	if (camera)
	{
		/*
		if (GetAsyncKeyState('F') & 0x8000) //70 is the vKey value for F
		{
			if (!camera->IsFollowing())
			{
				camera->Follow(player);
			}
		}

		if (GetAsyncKeyState('U') & 0x8000) //85 is the vKey value for U
		{
			if (camera->IsFollowing())
			{
				camera->Unfollow();
			}
		}*/
		if (!camera->IsFollowing())
		{
			camera->Follow(player);
		}
		camera->Update(gameTime);
	}
	if (player)
	{
		bool doesNotCollide = true;
		player->HandleInput();
		for (int i = 0; i < (int)tree.size(); i++)
		{		
			//TODO FIX COLLISION DETECTION
			if (doesCollide(player->getBoundaryBox(gameTime), tree[i]->getBoundaryBox()))
			{
				doesNotCollide = false;
				break;
			}
		}
		if (doesNotCollide)
		{
			player->Update(gameTime);
		}
		
	}
}

void Game::Draw(float gameTime)
{
	if (frameLimit < 0.05)
	{
		frameLimit += gameTime;
		return;
	}
	frameLimit = 0;
	//Simple RGB value for the background so use XRGB instead of ARGB
	gDevice->Clear(D3DCOLOR_XRGB(0, 0, 0));
	gDevice->Begin();

	//Draw logic here.
	if (camera)
	{
		camera->SetTransform(gDevice);
	}

	for (int i = 0; i < (int)background.size(); i++)
	{
		if (background[i])
		{
			background[i]->Draw(gameTime);
		}
	}
	for (int i = 0; i < (int)tree.size(); i++)
	{
		if (tree[i])
		{
			tree[i]->Draw(gameTime);
		}
	}
	if (player)
	{
		player->Draw(gameTime);
	}
	gDevice->End();
	gDevice->Present();
}

bool Game::doesCollide(RECT a, RECT b)
{
	if (a.left < b.right && a.right > b.left &&
		a.bottom > b.top && a.top < b.bottom)
	{
		return true;
	}
	return false;
}

void Game::Menu(float gameTime)
{
	gDevice->Clear(D3DCOLOR_XRGB(0, 0, 0));
	gDevice->Begin();
	/*
		Menu Draw Logic:
	*/
	font = nullptr;
	HRESULT hr = D3DXCreateFont(gDevice->device, 40, 0, FW_NORMAL, 1, false, DEFAULT_CHARSET, OUT_DEFAULT_PRECIS, ANTIALIASED_QUALITY, FF_DONTCARE, "Arial", &font);
	if (!SUCCEEDED(hr))
	{
		return;
	}
	std::string msg = "Hello world";
	RECT r;
	SetRect(&r, 0, 0, 200, 200);
	font->DrawTextA(NULL, msg.c_str(), -1, &r, DT_LEFT, D3DCOLOR_XRGB(255, 255, 255));
	gDevice->End();
	gDevice->Present();
	Sleep(100);
	while (true)
	{
		if (GetAsyncKeyState('E') & 0x8000)
		{
			//need to fix double read of input
			Sleep(100);
			return;
		}
	}
}


