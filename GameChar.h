#pragma once
#include <windows.h>
#include <vector>
#include <iostream>
#include <utility>
#include <memory>
#include "Ninja.h"
class GameChar
{
	private:
		std::unique_ptr<Ninja> player = std::make_unique<Ninja>();
	public:
		GameChar();
		virtual ~GameChar();
		void openMenu();
		void skillMenu();
		void techniqueList();
		void drawLevel(std::vector<std::vector<char>> map, int ySize, int xSize);
};

