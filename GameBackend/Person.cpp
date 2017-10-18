#include "Person.h"



Person::Person(std::string n, int hp, int ps, int l) : name(n), hitPoints(hp), physicalStrength(ps), level(l), curHP(hp)
{
}

Person::~Person()
{
}
void Person::setName(std::string n)
{
	name = n;
}
std::string Person::getName()
{
	return name;
}

int Person::getHP()
{
	return hitPoints;
}
