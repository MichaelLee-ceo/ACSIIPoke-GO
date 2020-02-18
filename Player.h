#ifndef PLAYER_H
#define PLAYER_H
#include "Monster.h"
#include "Error.h"
#include "MonsterDataBase.h"
#include <vector>
using namespace std;

class Player
{
public:
	Player(MonsterDataBase &mon);
	void printPet(int x, int y);				//print single pet
	void getPet(bool grass, bool water);		//return random pet
	void resetPet();							//reset all pet's ability
	int getScore();								//return player's score
	void setScore(int num);						//set player's score
	Monster* get();								//return player's pet

private:
	int score;
	vector<Monster*> pets;
	MonsterDataBase &monsterDataBase;
};

Player::Player(MonsterDataBase &mon)
	:monsterDataBase(mon), score(0)
{
}

void Player::printPet(int x, int y)
{
	rlutil::locate(x + 8, y);
	rlutil::setColor(11);
	cout << "Player's pet:";
	rlutil::resetColor();
	++y;
	for (int i = 0; i < pets.size(); i++)
	{
		++y;
		rlutil::locate(x, y);
		cout << setw(15) << left << pets[i]->getName() << setw(10) << right << pets[i]->getType();
	}

}

void Player::getPet(bool grass, bool water)
{
	int x = 60, y = 5;
	rlutil::cls();
	Monster* newMonster = monsterDataBase.pickMonster();

	if (grass)
	{
		if (rand() % 2 == 1)
			newMonster = monsterDataBase.pickGrass();
	}
	
	if (water)
	{
		if (rand() % 2 == 1)
			newMonster = monsterDataBase.pickWater();
	}
	
	monsterDataBase.showMonster(newMonster->getName(), 1, 1);
	monsterDataBase.printMonsters(newMonster->getName(), x, y);
	
	
	printPet(1, 25);
	
	string choice;

	while (true)				//enter choice
	{
		try
		{
			rlutil::locate(1, 30);
			cout << "                                     ";
			rlutil::locate(1, 31);
			cout << "                                     ";
			rlutil::locate(1, 32);
			cout << "                                     ";

			rlutil::locate(1, 30);
			cout << "Get it(Y/N)? ";
			cin >> choice;

			if (choice == "Y" || choice == "y")
				break;
			else if (choice == "N" || choice == "n")
				return;
			else
				throw WrongInput();
		}
		catch (WrongInput &e)
		{
			rlutil::locate(1, 31);
			cout << e.what();
			rlutil::locate(1, 32);
			system("pause");
		}
	}
		
	int chance = rand() % 2;
	 
	if (chance == 1)			//catch = true(can catch)
	{
		if (pets.size() == 3)
		{
			string throwAway;
			cout << "\nChoose the pet you want to take away: ";
			cin >> throwAway;

			for (int i = 0; i < pets.size(); i++)
				if (pets[i]->getName() == throwAway)
				{
					pets[i] = newMonster;
					break;
				}
		}
		else
			pets.push_back(newMonster);

		cout << endl << "Catch successed!" << endl;
		system("pause");
	}
	else
	{
		cout << endl << "Catch failed!" << endl;
		system("pause");
	}	
}

void Player::resetPet()
{
	Monster* currentMonster = nullptr;

	for (int i = 0; i < pets.size(); i++)
	{
		currentMonster = monsterDataBase.getMonster(pets[i]->getName());
		pets[i]->setHP(currentMonster->getHP());
		pets[i]->setAtk(currentMonster->getAtk());
		pets[i]->setDef(currentMonster->getDef());
		pets[i]->setSpeed(currentMonster->getSpeed());
	}
}

int Player::getScore()
{
	return score;
}

void Player::setScore(int num)
{
	score = num;
}

Monster* Player::get()
{
	for (int i = 0; i < pets.size(); i++)
		if (pets[i]->getHP() > 0)
			return pets[i];

	return nullptr;
}


#endif
