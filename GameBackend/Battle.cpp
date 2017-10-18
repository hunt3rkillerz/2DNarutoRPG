#include "Battle.h"



Battle::Battle(std::vector<Ninja> ally, std::vector<Ninja> enemy)
{
	this->ally = ally;
	this->enemy = enemy;
}

Battle::~Battle()
{
}

void Battle::attack(Ninja *target)
{

}
