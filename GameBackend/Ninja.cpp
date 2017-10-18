#include "Ninja.h"

Ninja::Ninja(std::string n, int hp, int ps, int l, int ms) : Person(n, hp, ps, l),mentalStrength(ms)
{
	/*std::cout << "hp: " << hitPoints << std::endl;
	std::cout << "ps: " << physicalStrength << std::endl;
	std::cout << "ms: " << mentalStrength << std::endl;
	std::cout << "level: " << level << std::endl;*/
	skillPoints = 0;
	skillList.accuracy = BASESKILLLEVEL;
	skillList.chakraControl = BASESKILLLEVEL;
	skillList.speech = BASESKILLLEVEL;
	skillList.speed = BASESKILLLEVEL;
	skillList.strength = BASESKILLLEVEL;
	skillList.weaponSkill = BASESKILLLEVEL;
	setChakra();
}


Ninja::~Ninja()
{
}

void Ninja::setChakra()
{
	chakra = (physicalStrength * mentalStrength) / 2;
}

void Ninja::learnTechnique(Genjutsu t)
{
	genJutsu.push_back(t);
}

void Ninja::learnTechnique(Taijutsu t)
{
	taiJutsu.push_back(t);
}

void Ninja::learnTechnique(Ninjutsu t)
{
	ninJutsu.push_back(t);
}

int Ninja::getChakra()
{
	return chakra;
}

int Ninja::getMS()
{
	return mentalStrength;
}

int Ninja::getPS()
{
	return physicalStrength;
}

int Ninja::getLevel()
{
	return level;
}

int Ninja::getSkillPoints()
{
	return skillPoints;
}

int Ninja::getCurHP() const
{
	return curHP;
}

void Ninja::takeDamage(int dmg)
{
	curHP -= dmg;
}

std::vector<Ninjutsu> Ninja::getNinjutsu()
{
	return ninJutsu;
}

std::vector<Genjutsu> Ninja::getGenjutsu()
{
	return genJutsu;
}

std::vector<Taijutsu> Ninja::getTaijutsu()
{
	return taiJutsu;
}

void Ninja::levelUp()
{
	level++;
	skillPoints += 22;
	hitPoints += 5;
	mentalStrength += 5;
	physicalStrength += 5;
	setChakra();
}

void Ninja::printSkills()
{
	std::cout << "Accuracy: " << skillList.accuracy << std::endl;
	std::cout << "Speech: " << skillList.speech << std::endl;
	std::cout << "Speed: " << skillList.speed << std::endl;
	std::cout << "Chakra Control: " << skillList.chakraControl << std::endl;
	std::cout << "Strength: " << skillList.strength << std::endl;
	std::cout << "Weapon Skill: " << skillList.weaponSkill << std::endl;
}
