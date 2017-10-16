#pragma once
#include<vector>
#include<typeinfo>
#include<iostream>
#include <string>
#define BASESKILLLEVEL 10
#include "Person.h"
#include "Genjutsu.h"
#include "Taijutsu.h"
#include "Ninjutsu.h"
class Ninja : public Person
{
	private:
		int chakra;
		int mentalStrength;
		std::vector<Ninjutsu> ninJutsu;
		std::vector<Genjutsu> genJutsu;
		std::vector<Taijutsu> taiJutsu;
		int skillPoints;
		struct Skills{
			int accuracy; //Modifier to inaccurate attacks
			int speed; //who goes first
			int speech; //Talk no jutsu
			int chakraControl; //More efficient jutsu
			int strength; //How hard base hits are
			int weaponSkill; //Effectiveness with different weapons
		};
		Skills skillList;
		void setChakra();
	public:
		Ninja(std::string n = "", int hp = 5, int ps = 5, int l = 1, int ms = 5);
		~Ninja();
		void learnTechnique(Genjutsu t);
		void learnTechnique(Taijutsu t);
		void learnTechnique(Ninjutsu t);
		void levelUp();
		void printSkills();
		/* getters */
		int getChakra();
		int getMS();
		int getPS();
		int getLevel();
		int getSkillPoints();
		std::vector<Ninjutsu> getNinjutsu();
		std::vector<Genjutsu> getGenjutsu();
		std::vector<Taijutsu> getTaijutsu();

};

