#include "GameChar.h"


GameChar::GameChar()
{
	player->setName("Alex");
	Genjutsu g("Bringer Of Darkness");
	Ninjutsu n("Rasengan");
	Taijutsu t("Lariat");
	Taijutsu t2("Shadow of the Dancing Leaf", 500, 25, 5);
	player->learnTechnique(g);
	player->learnTechnique(n);
	player->learnTechnique(t);
	player->learnTechnique(t2);
}


GameChar::~GameChar()
{
}
/*
	Opens the main game menu
*/
void GameChar::openMenu()
{
	start:
	system("cls");
	std::cout << player->getName() << ":" << std::endl;
	std::cout << "Level: " << player->getLevel() << std::endl;
	std::cout << "HP: " << player->getHP() << std::endl;
	std::cout << "Chakra: " << player->getChakra() << std::endl;
	std::cout << std::endl;
	std::cout << "1. Skill Menu" << std::endl;
	std::cout << "2. View Techniques" << std::endl;
	std::cout << "3. Inventory" << std::endl;
	Sleep(100);
	while (true)
	{
		if (GetAsyncKeyState('E') & 0x8000)
		{
			system("cls");
			return;
		}
		if (GetAsyncKeyState('1') & 0x8000)
		{
			skillMenu();
			goto start;
		}
		if (GetAsyncKeyState('2') & 0x8000)
		{
			techniqueList();
			goto start;
		}
	}
}
/*
	Provides a list of techniques the player knows
	TODO: Let user equip techniques
*/
void GameChar::techniqueList()
{
	std::vector<Genjutsu> g = player->getGenjutsu();
	std::vector<Ninjutsu> n = player->getNinjutsu();
	std::vector<Taijutsu> t = player->getTaijutsu();
	system("cls");
	std::cout << player->getName() << ":" << std::endl;
	std::cout << "Level: " << player->getLevel() << std::endl;
	std::cout << "HP: " << player->getHP() << std::endl;
	std::cout << "Chakra: " << player->getChakra() << std::endl;
	//Taijutsu
	std::cout << std::endl;
	std::cout << "Taijutsu List:" << std::endl;
	for (int i = 0; i < (int)t.size(); i++)
	{
		std::cout << "Name: " << t[i].getName()  << ", Base Damage: " << t[i].getBaseDmg()
			<< ", Chakra Cost: " << t[i].getChakraCost()	<< ", Health Cost: " << t[i].getHealthCost()  << std::endl;
	}
	//Ninjutsu
	std::cout << std::endl;
	std::cout << "Genjutsu List:" << std::endl;
	for (int i = 0; i < (int)n.size(); i++)
	{
		std::cout << "Name: " << n[i].getName() << ", Base Damage: " << n[i].getBaseDmg()
			<< ", Chakra Cost: " << n[i].getChakraCost() << ", Health Cost: " << n[i].getHealthCost() << std::endl;
	}
	//Genjutsu
	std::cout << std::endl;
	std::cout << "Genjutsu List:" << std::endl;
	for (int i = 0; i < (int)g.size(); i++)
	{
		std::cout << "Name: " << g[i].getName() << ", Base Damage: " << g[i].getBaseDmg()
			<< ", Chakra Cost: " << g[i].getChakraCost() << ", Health Cost: " << g[i].getHealthCost() << std::endl;
	}
	std::cout << std::endl;
	//Avoids double reading input
	Sleep(100);
	while (true)
	{
		if (GetAsyncKeyState('E') & 0x8000)
		{
			system("cls");
			return;
		}
		if (GetAsyncKeyState('2') & 0x8000)
		{
			return;
		}
	}
}

/*
	Shows user their skill stats
	TODO: Allow users to allocate skillpoints
*/
void GameChar::skillMenu()
{
	system("cls");
	std::cout << player->getName() << ":" << std::endl;
	std::cout << "Level: " << player->getLevel() << std::endl;
	std::cout << "HP: " << player->getHP() << std::endl;
	std::cout << "Chakra: " << player->getChakra() << std::endl;
	std::cout << std::endl;
	player->printSkills();

	std::cout << "Points Available: " << player->getSkillPoints() << std::endl;
	std::cout << std::endl;
	//Avoids double reading input
	Sleep(100);
	while (true)
	{
		if (GetAsyncKeyState('E') & 0x8000)
		{
			system("cls");
			return;
		}
		if (GetAsyncKeyState('1') & 0x8000)
		{
			return;
		}
	}
}

/*
	Currently the primary game loop that draws the first level and controls movement
*/
void GameChar::drawLevel(std::vector<std::vector<char>> map, int ySize, int xSize)
{
	while (true) 
	{
		if (GetAsyncKeyState('E') != 0)
		{
			openMenu();
		}
		for (int y = 0; y < ySize; y++)
		{
			for (int x = 0; x < xSize; x++)
			{
				std::cout << map[y][x];
			}
			std::cout << std::endl;
		}
		system("cls");
		for (int y = 0; y < ySize; y++)
		{
			for (int x = 0; x < xSize; x++)
			{
				switch (map[y][x])
				{
				case '#':
					map[y][x] = '#';
					break;
				case '@':
					if (GetAsyncKeyState('W') & 0x8000)
					{
						int y2 = y - 1;

						switch (map[y2][x])
						{
						case ' ':
							map[y][x] = ' ';
							y -= 1;
							map[y2][x] = '@';
							break;
						case '#':
							break;
						default:
							break;
						}
					}
					if (GetAsyncKeyState('S') & 0x8000)
					{
						int y2 = y + 1;

						switch (map[y2][x])
						{
						case ' ':
							map[y][x] = ' ';
							y += 1;
							map[y2][x] = '@';
							break;
						default:
							break;
						}
					}
					if (GetAsyncKeyState('A') & 0x8000)
					{
						int x2 = x - 1;

						switch (map[y][x2])
						{
						case ' ':
							map[y][x] = ' ';
							x -= 1;
							map[y][x2] = '@';
							break;
						default:
							break;
						}
					}
					if (GetAsyncKeyState('D') & 0x8000)
					{
						int x2 = x + 1;

						switch (map[y][x2])
						{
						case ' ':
							map[y][x] = ' ';
							x += 1;
							map[y][x2] = '@';
							break;
						default:
							break;
						}
					}
					break;
				default:
					break;
				}
			}
		}
	}
}