#pragma once
#include "Technique.h"
class Genjutsu : public Technique
{
	public:
		Genjutsu(std::string s, int dmg = 0, int hCost = 0, int cCost = 0);
		virtual ~Genjutsu();
};

