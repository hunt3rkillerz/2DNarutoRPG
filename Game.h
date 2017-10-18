#pragma once
#include "DrawEngine/GraphicsDevice.h"
#include "Sprites/GameplayObject.h"
#include "Sprites/BackgroundObject.h"
#include "Sprites/EnemyObject.h"
#include "GameBackend/GameTime.h"
#include "DrawEngine/BattleScreen.h"
#include "Sprites/Camera.h"
#include <vector>
class Game
{
	public:
		Game();
		~Game();
	//Functions
		bool Initialize(HWND hWnd, int w, int h);
		void Run();
		void Update(float gameTime);
		void Draw(float gameTime);
		void Menu(float gameTime);
		void battleScreen(float gameTime);
	private:
		bool doesCollide(RECT a, RECT b);
		GraphicsDevice *gDevice;
		GameplayObject *player;
		GameTime *gameTime;
		char map[15][25] = {
			"########################",
			"#                      #",
			"#   #          1       #",
			"#                      #",
			"#        #             #",
			"#                      #",
			"#         @            #",
			"#                      #",
			"#         1            #",
			"#           #          #",
			"#                      #",
			"#                      #",
			"#                      #",
			"#                      #",
			"########################"
		};
		float frameLimit;
		std::vector<BackgroundObject *> background;
		std::vector<BackgroundObject *> tree;
		std::vector<EnemyObject *> enemies;
		ID3DXFont *font;
		Camera *camera;
		int width;
		int height;
};

