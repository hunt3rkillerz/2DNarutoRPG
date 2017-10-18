#pragma once
#include <vector>>
#include "Ninja.h"
class Battle
{
	public:
		Battle(std::vector<Ninja> ally, std::vector<Ninja> enemy);
		~Battle();
		void attack(Ninja *target);
	private:
		std::vector<Ninja> ally, enemy;

};

