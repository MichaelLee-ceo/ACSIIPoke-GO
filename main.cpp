//ASCIIPOKEGO
#include "rlutil.h"
#include "Map.h"
#include "MonsterDataBase.h"
#include "Error.h"
#include <algorithm>
#include <cstdlib>
#include <cstdio>
#include <ctime>
using namespace std;

int main()
{
	system("mode con cols=110 lines=40");
	//system("color F0");
	srand(time(NULL));

	MonsterDataBase m;
	
	AttackType a;
	//a.printType();
	//system("pause");

	//read yzumap.txt
	Map YzuMap(m);
	
	//YzuMap.printNpc();
	//system("pause");
	
	string c;

	int x = 20, y = 21;
	
	while (true)
	{
		YzuMap.move(x, y);
		rlutil::setColor(11);

		while (true)
		{
			try
			{
				rlutil::cls();
				rlutil::locate(45, 20);
				cout << "End Game(Y/N)? ";
				cin >> c;

				if (c == "Y" || c == "y" || c == "N" || c == "n")
					break;
				else
					throw WrongInput();
			}
			catch (WrongInput &e)
			{
				rlutil::locate(45, 21);
				cerr << e.what();
				rlutil::locate(45, 22);
				system("pause");
			}
		}
		
		if (c == "Y" || c == "y")
			break;
	}
	
	rlutil::cls();
	rlutil::locate(45, 20);
	cout << "Your total score: " << YzuMap.getPlayer().getScore();
	rlutil::locate(45, 21);
	system("pause");
	return 0;
}
