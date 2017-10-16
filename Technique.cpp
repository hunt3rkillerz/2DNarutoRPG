#include "Technique.h"



Technique::Technique(std::string s, int dmg, int hCost, int cCost) : name(s), baseDamage(dmg), healthCost(hCost), chakraCost(cCost)
{
}

Technique::Technique(int dmg, int hCost, int cCost) : baseDamage(dmg), healthCost(hCost), chakraCost(cCost)
{
	name = "";
}


Technique::~Technique()
{
}

std::string Technique::getName()
{
	return name;
}

int Technique::getBaseDmg()
{
	return baseDamage;
}

int Technique::getHealthCost()
{
	return healthCost;
}

int Technique::getChakraCost()
{
	return chakraCost;
}
