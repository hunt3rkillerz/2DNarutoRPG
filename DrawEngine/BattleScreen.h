#pragma once
#include "../GameBackend/Ninja.h"
#include "GraphicsDevice.h"
#include <d3dx9.h>
class BattleScreen
{
	public:
		BattleScreen(Ninja *a, Ninja* b);
		~BattleScreen();
		void draw(GraphicsDevice *gDevice);
	private:
		Ninja *a, *b;
};

