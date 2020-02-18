#ifndef ATTACHTYPE_H
#define ATTACKTYPE_H
#include <iostream>
#include <fstream>
#include <sstream>
using namespace std;

class AttackType
{
public:
	AttackType();
	float getAtkType(int left, int right);		//return attack rate
	void printType();							//test inFile
private:
	float attackType[20][20] = { 0.0 };
};

AttackType::AttackType()
{
	ifstream in("type.csv");
	int count = 0;
	float num;
	bool first = true;
	string row;
	string col;
	stringstream sd;
	stringstream sp;
	string b;
	while (getline(in, row))
	{
		sd.str("");
		sd.clear();

		sd << row;

		if (first)
		{
			first = false;
			continue;
		}

		for (int i = 0; i < 20; i++)
		{
			getline(sd, col, ',');

			sp.str("");
			sp.clear();

			sp << col;

			switch (i)
			{
			case 0:
				attackType[count][i] = 0.0;
			default:
				sp >> num;
				attackType[count][i] = num;
			}
		}
		++count;
	}
	in.close();
}

float AttackType::getAtkType(int left, int right)
{
	return attackType[left][right];
}

void AttackType::printType()
{
	for (int i = 0; i < 20; i++)
	{
		for (int j = 0; j < 20; j++)
			cout << attackType[i][j] << ' ';
		cout << endl;
	}
}
#endif
