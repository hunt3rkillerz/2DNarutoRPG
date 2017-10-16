#pragma once
#include "Technique.h"
class Ninjutsu : public Technique
{
	public:
		Ninjutsu(std::string s, int dmg = 0, int hCost = 0, int cCost = 0);
		virtual ~Ninjutsu();
};

