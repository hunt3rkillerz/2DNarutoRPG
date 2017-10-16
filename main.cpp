/*
	Credit to Nathan Biefeld's C++ DirectX Tutorial for the startup code
	The tutorial's can be found on his youtube channel (link below)
	https://www.youtube.com/user/Whiplashx86
*/
#define WKEY 87
#define SKey 83
#define DKey 68
#define AKEY 65
#define WIDTH 1280
#define HEIGHT 720
//Windows.h include necessary functions for Windows API
#include <Windows.h>
#include <windowsx.h>
#include <d3d11.h>
#include <d3d9.h>
#include <d3dx11.h>
#include <d3dx9.h>

// include the Direct3D Library file
#pragma comment (lib, "d3d11.lib")
#pragma comment (lib, "d3dx11.lib")
#pragma comment (lib, "d3dx10.lib")
#pragma comment (lib, "d3d9.lib")
#pragma comment (lib, "d3dx9.lib")
#include "Game.h"

//Prototypes for the GenerateWindow function, otherwise WinMain cannot call GenerateWindow
bool GenerateWindow(HINSTANCE hInstance, int nCmdShow, LPCSTR className, LPCSTR windowTitle, int width, int height, HWND& hWnd);
bool GenerateWindow(HINSTANCE hInstance, int nCmdShow, LPCSTR className, LPCSTR windowTitle, int x, int y, int width, int height, HWND& hWnd);

//Another prototype
LRESULT CALLBACK WindowProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam);

bool InitializeInput(void);
//Game Ptr
Game *game;
//WinMain function, set up window and message loop
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
	HWND hWnd;

	if (GenerateWindow(hInstance, nCmdShow, "Direct3D", "Alex RPG", WIDTH, HEIGHT, hWnd)
		&& InitializeInput())
	{
		MSG msg;
		game = new Game();
		if (game->Initialize(hWnd, WIDTH, HEIGHT))
		{
			while (true)
			{
				while (PeekMessage(&msg, NULL, 0, 0, PM_REMOVE))
				{
					TranslateMessage(&msg);

					DispatchMessage(&msg);
				}
				if (msg.message == WM_QUIT) break;
				else
				{
					game->Run();
				}
			}
		}
		delete game;
		return msg.wParam;
	}

	return 0;
}

bool InitializeInput()
{
	RAWINPUTDEVICE rawInput[1];

	rawInput[0].usUsagePage = 0x01;
	//0x02 for mouse
	rawInput[0].usUsage = 0x06;
	rawInput[0].dwFlags = 0;
	rawInput[0].hwndTarget = 0;

	if (RegisterRawInputDevices(rawInput, 1, sizeof(rawInput[0])) == FALSE)
	{
		return false;
	}
	return true;
}

bool GenerateWindow(HINSTANCE hInstance, int nCmdShow, LPCSTR className, LPCSTR windowTitle, int width, int height, HWND& hWnd)
{
	return GenerateWindow(hInstance, nCmdShow, className, windowTitle, (GetSystemMetrics(SM_CXSCREEN) - width) / 2,
		(GetSystemMetrics(SM_CYSCREEN) - height) / 2, width, height, hWnd);
}

//Generic GenerateWindow function
bool GenerateWindow(HINSTANCE hInstance, int nCmdShow, LPCSTR className, LPCSTR windowTitle, int x, int y, int width, int height, HWND& hWnd)
{
	WNDCLASSEX wcex;

	ZeroMemory(&wcex, sizeof(WNDCLASSEX));
	wcex.cbSize = sizeof(wcex);
	wcex.style = CS_HREDRAW | CS_VREDRAW;
	wcex.lpfnWndProc = WindowProc;
	wcex.hInstance = hInstance;
	wcex.hIcon = LoadIcon(NULL, IDI_APPLICATION);
	wcex.hCursor = LoadCursor(NULL, IDC_ARROW);
	wcex.hbrBackground = (HBRUSH)COLOR_WINDOW;
	wcex.lpszClassName = className;
	wcex.hIconSm = LoadIcon(NULL, IDI_APPLICATION);

	if (!RegisterClassEx(&wcex))
	{
		return false;
	}

	//Now we are using Direct3D, we need to make sure the window will not be adjusted by the user
	hWnd = CreateWindowEx(NULL, className, windowTitle, WS_OVERLAPPED | WS_SYSMENU | WS_MINIMIZEBOX, x, y, width, height, NULL, NULL, hInstance, NULL);

	ShowWindow(hWnd, nCmdShow);

	return true;
}

//WindowProc - Handles input sent to the window
LRESULT CALLBACK WindowProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	switch (message)
	{
		case WM_DESTROY:
		{
			PostQuitMessage(0);
			return 0;
		} 
		break;
		/*case WM_INPUT:
		{
			UINT dwSize;

			GetRawInputData((HRAWINPUT)lParam, RID_INPUT,
				NULL, &dwSize, sizeof(RAWINPUTHEADER));
			LPBYTE lpb = new BYTE[dwSize];
			if (lpb == NULL)
			{
				return 0;
			}
			GetRawInputData((HRAWINPUT)lParam, RID_INPUT,
				lpb, &dwSize, sizeof(RAWINPUTHEADER));

			RAWINPUT * raw = (RAWINPUT*)lpb;
			
			if (raw->header.dwType == RIM_TYPEKEYBOARD)
			{
				OutputDebugString("\n");
				OutputDebugString(std::to_string(raw->data.keyboard.VKey).c_str());
				if (raw->data.keyboard.Message == WM_KEYDOWN
					|| raw->data.keyboard.Message == WM_SYSKEYDOWN)
				{
					if (raw->data.keyboard.VKey == VK_SPACE)
					{
						MessageBox(NULL, "Space Key", NULL, NULL);
					}
					if (raw->data.keyboard.VKey == AKEY)
					{
						MessageBox(NULL, "A Key", NULL, NULL);
					}
					if (raw->data.keyboard.VKey == SKey)
					{
						MessageBox(NULL, "S Key", NULL, NULL);
					}
					if (raw->data.keyboard.VKey == WKEY)
					{
						MessageBox(NULL, "W Key", NULL, NULL);
					}
					if (raw->data.keyboard.VKey == DKey)
					{
						MessageBox(NULL, "D Key", NULL, NULL);
					}
				}
			}
		}
		break;*/
	}

	return DefWindowProc(hWnd, message, wParam, lParam);
}

void Update(float gameTime)
{
	//Update our sprites and other game logic
}

void Draw(GraphicsDevice *gDevice, float gameTime)
{

}

/*int main(int argc, char* argv[])
{
	Game game;
	std::vector<std::vector<char>> board;
	board.resize(10, std::vector<char>(20));
	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 20; j++)
		{
			board[i][j] = map[i][j];
		}
	}
	game.drawLevel(board, 10, 20);
	return 0;
}*/