#ifndef MAP_H
#define MAP_H
#include "rlutil.h"
#include "Player.h"
#include "Monster.h"
#include "MonsterDataBase.h"
#include <iostream>
#include <fstream>
#include <string>
using namespace std;


class Map
{
public:
	Map(MonsterDataBase &theDataBase);
	~Map();
	void printMap();							//print out the map
	void move(int &x, int &y);					//singe movement
	void printNpc();							//print out the npc's monster
	Player getPlayer();							//return the reference of player
	char getMap(int x, int y);					//return the point in the map
	void showNpc(int place, int x, int y);		//print the picture of the npc's monster
	Monster* getNpc(int index);					//return the monster of the npc
	void execute(int index);					//execute the fight
	void fight(Monster* left, Monster* right, bool leftPlayer);			//define single fight
	void clear();								//clear the screen

private:
	string map[32];			// 32rows
	Player player;
	vector<Monster**> NPC;
	MonsterDataBase &dataBase;
};

Map::Map(MonsterDataBase &theDataBase)
	:player(theDataBase), dataBase(theDataBase)
{
	//construct the map
	ifstream inFile("yzumap.txt");
	int count = 0;
	Monster* npcMon;

	while (getline(inFile, map[count]))
		count++;

	inFile.close();

	// construct NPC
	NPC.resize(12);

	for (int i = 0; i < NPC.size(); i++)
	{
		NPC[i] = new Monster*[3]();
		for (int j = 0; j < 3; j++)
		{
			//do
			//{
			npcMon = dataBase.pickMonster();
				//system("pause");
			//} while (existMonster(npcMon->getName(), i));

			NPC[i][j] = npcMon;
		}
	}
}

Map::~Map()
{
	for (int i = 0; i < 12; i++)
		delete[] NPC[i];
}

void Map::printMap()
{
	rlutil::cls();
	rlutil::resetColor();

	//uncolored
	//for (int i = 0; i < 32; i++)
		//cout << map[i] << endl;

	//colored
	for (int i = 0; i < 32; i++)
	{
		for (int j = 0; j < map[i].size(); j++)
		{
			rlutil::resetColor();

			if (map[i][j] == ';')
				rlutil::setColor(10);
			else if (map[i][j] == '!')
				rlutil::setColor(4);
			else if (map[i][j] == '~')
				rlutil::setColor(11);
			else if (map[i][j] == '#')
				rlutil::setColor(14);

			cout << map[i][j];
		}
		cout << endl;
	}
}

void Map::move(int &x, int &y)
{
	srand(time(NULL));
	char key;
	char buffer;
	bool grass;
	bool water;
	
	while (true)
	{
		printMap();
		rlutil::locate(x, y);

		rlutil::setColor(12);
		rlutil::hidecursor();
		cout << '@';
		
		key = getch();			//getch() for input char
		getch();				//getch() for '\0'

		//only walk through ground, grass, water and door
		if (key == 'w')
		{
			if (map[y - 2][x - 1] == ' ' || map[y - 2][x - 1] == ';' || map[y - 2][x - 1] == '~' || map[y - 2][x - 1] == '#')
				--y;

		}
		else if (key == 'a')
		{
			if (map[y - 1][x - 2] == ' ' || map[y - 1][x - 2] == ';' || map[y - 1][x - 2] == '~' || map[y - 1][x - 2] == '#')
				--x;
				
		}
		else if (key == 's')
		{
			if (map[y][x - 1] == ' ' || map[y][x - 1] == ';' || map[y][x - 1] == '~' || map[y][x - 1] == '#')
				++y;

		}
		else if (key == 'd')
		{
			if (map[y - 1][x] == ' ' || map[y - 1][x] == ';' || map[y - 1][x] == '~' || map[y - 1][x] == '#')
				++x;
				
		}
		else if (key == ' ')
			break;

		grass = false;
		water = false;

		// 10% chance int catch monster
		if (rand() % 10 == 1)
		{
			rlutil::resetColor();

			if (map[y - 1][x - 1] == ';')
				grass = true;
			else if (map[y - 1][x - 1] == '~')
				water = true;

			player.getPet(grass, water);
		}

		// 13 NPC
		if (x == 14 && y == 18)
			execute(0);
		else if (x == 35 && y == 7)
			execute(1);
		else if (x == 31 && y == 15)
			execute(2);
		else if (x == 18 && y == 7)
			execute(3);
		else if (x == 10 && y == 11)
			execute(4);
		else if (x == 41 && y == 14)
			execute(5);
		else if (x == 76 && y == 9)
			execute(6);
		else if (x == 77 && y == 12)
			execute(7);
		else if (x == 75 && y == 4)
			execute(8);
		else if (x == 84 && y == 7)
			execute(9);
		else if (x == 76 && y == 7)
			execute(10);
		else if (x == 86 && y == 10)
			execute(11);

		//player.resetPet();

	}
	//rlutil::showcursor();
}

Player Map::getPlayer()
{
	return player;
}

void Map::printNpc()
{
	for (int i = 0; i < NPC.size(); i++)
	{
		for (int j = 0; j < 3; j++)
			cout << setw(15) << left << NPC[i][j]->getName() << setw(10) << right << NPC[i][j]->getType() << setw(10) << right << NPC[i][j]->getHP() << setw(10) << right << NPC[i][j]->getAtk() << setw(10) << right << NPC[i][j]->getDef() << setw(10) << right << NPC[i][j]->getSpeed() << setw(10) << right << NPC[i][j]->getAbility() << endl;
		cout << endl;
	}
		
}

void Map::showNpc(int place, int x, int y)
{
	rlutil::locate(x + 8, y);
	rlutil::setColor(9);
	cout << "NPC's pet:";
	rlutil::resetColor();
	++y;
	for (int i = 0; i < 3; i++)
	{
		++y;
		rlutil::locate(x, y);
		cout << setw(15) << left << NPC[place][i]->getName() << setw(10) << right << NPC[place][i]->getType();
	}

}

Monster* Map::getNpc(int index)
{
	for (int i = 0; i < 3; i++)
		if (NPC[index][i]->getHP() > 0)
			return NPC[index][i];

	return nullptr;
}

void Map::execute(int index)
{
	rlutil::cls();
	rlutil::resetColor();

	if (player.get() == nullptr)
	{
		rlutil::locate(40, 20);
		cout << "Player do not have any pets!";
		rlutil::locate(40, 21);
		system("pause");
		return;
	}

	rlutil::locate(20, 10);
	rlutil::setColor(13);
	cout << "- - - - - - - - - - - - - - - FIGHT - - - - - - - - - - - - - - -";
	rlutil::resetColor();
	showNpc(index, 60, 18);
	player.printPet(20, 18);

	rlutil::locate(45, 35);
	system("pause");

	while (true)
	{
		rlutil::cls();

		if (player.get() != nullptr)
		{
			dataBase.showMonster(player.get()->getName(), 1, 1);
			player.printPet(10, 28);
		}
		else
		{
			rlutil::cls();
			rlutil::locate(43, 20);
			cout << "Player lost, NPC win!";
			rlutil::locate(43, 21);
			system("pause");
			break;
		}

		if (getNpc(index) != nullptr)
		{
			dataBase.showMonster(getNpc(index)->getName(), 60, 1);
			showNpc(index, 70, 28);
		}
		else
		{
			rlutil::cls();
			rlutil::locate(43, 20);
			cout << "NPC lost, Player win!";
			rlutil::locate(43, 21);
			player.setScore(player.getScore() + 100);
			system("pause");
			break;
		}

		if (player.get()->getSpeed() > getNpc(index)->getSpeed())
			fight(player.get(), getNpc(index), true);
		else
			fight(getNpc(index), player.get(), false);
		
		//rlutil::locate(45, 38);
		//system("pause");
	}
	player.resetPet();
}

void Map::fight(Monster* left, Monster* right, bool leftPlayer)
{
	char ch;
	bool check1 = true;
	bool check2 = true;
	bool check3 = false;
	bool check4 = false;
	bool check5 = true;
	bool check6 = true;
	int beforeLeft;
	int afterLeft;
	int beforeRight;
	int afterRight;
	int count = 0;
	int x1, x2;

	while (true)
	{
		++count;					//count for rounds;

		if (leftPlayer)
		{
			x1 = 1;
			x2 = 60;
		}
		else
		{
			x1 = 60;
			x2 = 1;
		}

		//print player's current pet state
		rlutil::locate(x1, 25);
		cout << setw(10) << left->getName() << setw(10) << left->getType() << setw(6) << left->getMax() << setw(6) << left->getAtk() << setw(6) << left->getDef() << setw(6) << left->getSpeed() << setw(6) << left->getAbility();
		//print NPC's current pet state
		rlutil::locate(x2, 25);
		cout << setw(10) << right->getName() << setw(10) << right->getType() << setw(6) << right->getMax() << setw(6) << right->getAtk() << setw(6) << right->getDef() << setw(6) << right->getSpeed() << setw(6) << right->getAbility();
		
		beforeLeft = left->getHP();
		beforeRight = right->getHP();

		if (left->getHP() <= 0 || right->getHP() <= 0)
			break;

		rlutil::locate(50, 33);
		rlutil::setColor(13);
		cout << "Round " << count;

//------------------------------------------left attack-----------------------------------------
		left->ATTACK(*right);
		//for ability 10
		if (check5 && left->getAbility() == 10)
		{
			left->ABILITY(*right);
			check5 = false;
		}

		//for ability 9, 11, 12
		if (check1 && (left->getAbility() == 9 || left->getAbility() == 11 || left->getAbility() == 12))
		{
			left->ABILITY(*right);
			check1 = false;
		}

		if (check3 || (left->getAbility() != 8 && left->getAbility() != 9 && left->getAbility() != 10 && left->getAbility() != 11 && left->getAbility() != 12))
			left->ABILITY(*right);

		//for ability 8
		if (left->getAbility() == 8)
			check3 = true;

		afterRight = right->getHP();

		if (right->getHP() <= 0)
		{
			clear();
			rlutil::setColor(15);
			rlutil::locate(20, 35);
			cout << left->getName() << " attacks " << right->getName() << ", " << right->getName() << ' ';
			rlutil::setColor(12);
			cout << afterRight - beforeRight;
			rlutil::setColor(15);
			cout << " bloods. " << right->getName() << " ( " << right->getHP() << " / " << right->getMax() << " )";
			rlutil::resetColor();
			rlutil::locate(45, 38);
			system("pause");
			break;
		}

//------------------------------------------right attack-----------------------------------------
		right->ATTACK(*left);
		//for ability 10
		if (check6 && right->getAbility() == 10)
		{
			right->ABILITY(*left);
			check6 = false;
		}

		//for ability 9, 11, 12
		if (check2 && (right->getAbility() == 9 || right->getAbility() == 11 || right->getAbility() == 12))
		{
			right->ABILITY(*left);
			check2 = false;
		}
		if (check4 || (right->getAbility() != 8 && right->getAbility() != 9 && right->getAbility() != 10 && right->getAbility() != 11 && right->getAbility() != 12))
			right->ABILITY(*left);

		//for ability 8
		if (right->getAbility() == 8)
			check4 = true;

		afterLeft = left->getHP();

		if (left->getHP() <= 0)
		{
			clear();
			rlutil::setColor(15);
			rlutil::locate(20, 36);
			cout << right->getName() << " attacks " << left->getName() << ", " << left->getName() << ' ';
			rlutil::setColor(12);
			cout << afterLeft - beforeLeft;
			rlutil::setColor(15);
			cout << " bloods. " << left->getName() << " ( " << left->getHP() << " / " << left->getMax() << " )";
			rlutil::resetColor();
			rlutil::locate(45, 38);
			system("pause");
			break;
		}

		clear();

		rlutil::setColor(15);
		rlutil::locate(20, 35);
		cout << left->getName() << " attacks " << right->getName() << ", " << right->getName() << ' ';
		rlutil::setColor(12);
		cout << afterRight - beforeRight;
		rlutil::setColor(15);
		cout << " bloods. " << right->getName() << " ( " << right->getHP() << " / " << right->getMax() << " )";
		rlutil::locate(20, 36);
		cout << right->getName() << " attacks " << left->getName() << ", " << left->getName() << ' ';
		rlutil::setColor(12);
		cout << afterLeft - beforeLeft;
		rlutil::setColor(15);
		cout << " bloods. " << left->getName() << " ( " << left->getHP() << " / " << left->getMax() << " )";
		rlutil::resetColor();

		rlutil::locate(45, 38);
		system("pause");
	}
}

char Map::getMap(int x, int y)
{
	return map[x][y];
}

void Map::clear()
{
	rlutil::locate(20, 35);
	cout << "                                                                                            ";

	rlutil::locate(20, 36);
	cout << "                                                                                            ";
}


#endif