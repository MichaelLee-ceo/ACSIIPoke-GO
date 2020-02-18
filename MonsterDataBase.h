#ifndef MONSTERDATABASE_H
#define MONSTERDATABASE_H
#include "Monster.h"
#include "Map.h"
#include <vector>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <sstream>
#include <string>
#include <ctime>
using namespace std;

class MonsterDataBase
{
public:
	MonsterDataBase();
	void printMonsters();								//test inFile
	void printMonsters(string name, int x, int y);		//print single monster
	Monster* pickMonster();								//return common monster
	Monster* pickGrass();								//return grass-type monster
	Monster* pickWater();								//return water-type monster
	void showMonster(string name, int x, int y);		//print picture of monster
	Monster* getMonster(string monsterName);			//return the pointer of current monster

private:
	vector<Monster*> monsters;
	void loadMonster();
};

MonsterDataBase::MonsterDataBase()
{
	loadMonster();
}

void MonsterDataBase::printMonsters()
{
	cout << setw(15) << left << "Name" << setw(10) << right << "Type" << setw(10) << right << "HP" << setw(10) << right << "Attack" << setw(10) << right << "Defense" << setw(10) << right << "Speed" << setw(10) << right << "Ability" << endl;
	for (int i = 0; i < monsters.size(); i++)
		cout << setw(15) << left << monsters[i]->getName() << setw(10) << right << monsters[i]->getType() << setw(10) << right << monsters[i]->getHP() << setw(10) << right << monsters[i]->getAtk() << setw(10) << right << monsters[i]->getDef() << setw(10) << right << monsters[i]->getSpeed() << setw(10) << right << monsters[i]->getAbility() << endl;
}

void MonsterDataBase::printMonsters(string name, int x, int y)
{
	Monster* currentMonster = getMonster(name);
	rlutil::locate(x, y);
	cout << "Name: " << setw(10) << right << currentMonster->getName();
	rlutil::locate(x, y + 2);
	cout << "Type: " << setw(10) << right << currentMonster->getType();
	rlutil::locate(x, y + 4);
	cout << "HP: " << setw(12) << right << currentMonster->getHP();
	rlutil::locate(x, y + 6);
	cout << "Attack: " << setw(8) << right << currentMonster->getAtk();
	rlutil::locate(x, y + 8);
	cout << "Defense: " << setw(7) << right << currentMonster->getDef();
	rlutil::locate(x, y + 10);
	cout << "Speed: " << setw(9) << right << currentMonster->getSpeed();
	rlutil::locate(x, y + 12);
	cout << "Ability: " << setw(7) << right << currentMonster->getAbility();
}

Monster* MonsterDataBase::getMonster(string monsterName)
{
	loadMonster();
	for (int i = 0; i < monsters.size(); i++)
		if (monsters[i]->getName() == monsterName)
			return monsters[i];

	return nullptr;
}

Monster* MonsterDataBase::pickMonster()
{
	//srand(time(NULL));
	int choice = rand() % 34;

	return monsters[choice];
}

void MonsterDataBase::showMonster(string name, int x, int y)
{
	int location;
	string mon;

	for (int i = 0; i < monsters.size(); i++)
		if (monsters[i]->getName() == name)
		{
			location = i + 1;
			break;
		}

	stringstream ss;
	ss << location;

	if (location < 10)
		mon = "00" + ss.str();
	else
		mon = "0" + ss.str();
	
	mon += ".txt";
	
	ifstream inFile(mon);
	char ch;
	string pic;
	while (!inFile.eof())
	{
		ch = inFile.get();
		if (ch == '\n')
			pic.push_back('~');
		else
			pic.push_back(ch);
	}
	inFile.close();

	rlutil::locate(x, y);

	for (int i = 0; i < pic.size(); i++)
	{
		if (pic[i] == '~')
		{
			++y;
			rlutil::locate(x, y);
			continue;
		}
		cout << pic[i];
	}
	
}

Monster* MonsterDataBase::pickGrass()
{
	return monsters[rand() % 3];
}

Monster* MonsterDataBase::pickWater()
{
	return monsters[rand() % 3 + 6];
}

void MonsterDataBase::loadMonster()
{
	monsters.clear();

	string data;
	string buffer;
	string type;
	int mon;
	int h;
	int atk;
	int def;
	int s;
	int ab;

	stringstream ss;
	stringstream sn;

	ifstream inFile("pokemons.csv");
	while (getline(inFile, buffer))
	{
		ss.str("");
		ss.clear();

		ss << buffer;

		for (int i = 1; i <= 8; i++)
		{
			getline(ss, data, ',');

			sn.str("");
			sn.clear();

			sn << data;

			switch (i)
			{
			case 1:
				sn >> mon;
				break;
			case 3:
				sn >> type;
				break;
			case 4:
				sn >> h;
				break;
			case 5:
				sn >> atk;
				break;
			case 6:
				sn >> def;
				break;
			case 7:
				sn >> s;
				break;
			case 8:
				sn >> ab;
				break;
			}
		}

		Monster* monster = nullptr;

		switch (mon)
		{
		case 1:
			monster = new Bulbasaur(h, atk, def, type, ab, s);
			break;
		case 2:
			monster = new Ivysaur(h, atk, def, type, ab, s);
			break;
		case 3:
			monster = new Venusaur(h, atk, def, type, ab, s);
			break;
		case 4:
			monster = new Charmander(h, atk, def, type, ab, s);
			break;
		case 5:
			monster = new Charmeleon(h, atk, def, type, ab, s);
			break;
		case 6:
			monster = new Charizard(h, atk, def, type, ab, s);
			break;
		case 7:
			monster = new Squirtle(h, atk, def, type, ab, s);
			break;
		case 8:
			monster = new Wartortle(h, atk, def, type, ab, s);
			break;
		case 9:
			monster = new Blastoise(h, atk, def, type, ab, s);
			break;
		case 10:
			monster = new Caterpie(h, atk, def, type, ab, s);
			break;
		case 11:
			monster = new Metapod(h, atk, def, type, ab, s);
			break;
		case 12:
			monster = new Butterfree(h, atk, def, type, ab, s);
			break;
		case 13:
			monster = new Weedle(h, atk, def, type, ab, s);
			break;
		case 14:
			monster = new Kakuna(h, atk, def, type, ab, s);
			break;
		case 15:
			monster = new Beedrill(h, atk, def, type, ab, s);
			break;
		case 16:
			monster = new Pidgey(h, atk, def, type, ab, s);
			break;
		case 17:
			monster = new Pidgeotto(h, atk, def, type, ab, s);
			break;
		case 18:
			monster = new Pidgeot(h, atk, def, type, ab, s);
			break;
		case 19:
			monster = new Rattata(h, atk, def, type, ab, s);
			break;
		case 20:
			monster = new Raticate(h, atk, def, type, ab, s);
			break;
		case 21:
			monster = new Spearow(h, atk, def, type, ab, s);
			break;
		case 22:
			monster = new Fearow(h, atk, def, type, ab, s);
			break;
		case 23:
			monster = new Ekans(h, atk, def, type, ab, s);
			break;
		case 24:
			monster = new Arbok(h, atk, def, type, ab, s);
			break;
		case 25:
			monster = new Pikachu(h, atk, def, type, ab, s);
			break;
		case 26:
			monster = new Raichu(h, atk, def, type, ab, s);
			break;
		case 27:
			monster = new Sandshrew(h, atk, def, type, ab, s);
			break;
		case 28:
			monster = new Sandslash(h, atk, def, type, ab, s);
			break;
		case 29:
			monster = new NidoranG(h, atk, def, type, ab, s);
			break;
		case 30:
			monster = new Nidorina(h, atk, def, type, ab, s);
			break;
		case 31:
			monster = new Nidoqueen(h, atk, def, type, ab, s);
			break;
		case 32:
			monster = new NidoranB(h, atk, def, type, ab, s);
			break;
		case 33:
			monster = new Nidorino(h, atk, def, type, ab, s);
			break;
		case 34:
			monster = new Nidoking(h, atk, def, type, ab, s);
			break;
		}

		monsters.push_back(monster);
	}
	inFile.close();
}

#endif
