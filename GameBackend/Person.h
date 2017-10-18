#pragma once
#include <string>
class Person
{
	public:
		Person(std::string n = "", int hp = 5, int ps = 5, int l = 1);
		std::string getName();
		int getHP();
		void setName(std::string n);
		virtual ~Person();
	protected:
		int hitPoints;
		int curHP;
		int physicalStrength;
		int level;
		std::string name;
};

