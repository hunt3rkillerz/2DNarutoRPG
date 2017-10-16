#pragma once
#include "Technique.h"
class Taijutsu : public Technique
{
	public:
		Taijutsu(std::string s, int dmg = 0, int hCost = 0, int cCost = 0);
		virtual ~Taijutsu();
};

