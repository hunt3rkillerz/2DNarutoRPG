#pragma once
#include <string>
class Technique
{
	protected:
		int baseDamage;
		int healthCost;
		int chakraCost;
		std::string name;
	public:
		Technique(int dmg = 0, int hCost = 0, int cCost = 0);
		Technique(std::string s, int dmg = 0, int hCost = 0, int cCost = 0);
		virtual ~Technique();
		//Getters
		std::string getName();
		int getBaseDmg();
		int getHealthCost();
		int getChakraCost();

};

