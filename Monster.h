#ifndef MONSTER_H
#define MONSTER_H
#include <string>
#include "AttackType.h"
using namespace std;

class Monster
{
public:
	Monster(int h = 0, int atk = 0, int def = 0, string t = " ", int ab = 0, int s = 0);
	void setHP(int num);					//set monster's Hp
	void setSpeed(int num);					//set monster's speed
	void setDef(int num);					//set monster's defense
	void setAtk(int num);					//set monster's attack
	int getHP();							//return monster's Hp

	int getAtk();							//return monster's attack
	int getDef();							//return monster's defense
	int getAbility();						//return monster's ability
	int getSpeed();							//return monster's speed
	int getMax();							//return monster's maxHP
	string getType();						//return monster's type
	int getTypeNumber();					//return monster's typeNumber
	string getName();						//return monster's name
	void setName(string n);					//set monster's name
	void ATTACK(Monster &m);				//monster attack
	virtual void ABILITY(Monster &m);		//for polymorphism ability

	Monster& operator=(const Monster &right);		//operator loading for assignment

private:
	int maxHp;
	int hp;
	int attack;
	int defense;
	int speed;
	string type;
	int ability;
	string name;
};

Monster::Monster(int h, int atk, int def, string t, int ab, int s)
	:hp(h), attack(atk), defense(def), type(t), ability(ab), speed(s), maxHp(h)
{
	name = " ";
}

void Monster::setHP(int num)
{
	hp = num;
}

int Monster::getHP()
{
	return hp;
}

int Monster::getAtk()
{
	return attack;
}

int Monster::getDef()
{
	return defense;
}

void Monster::ABILITY(Monster &m)
{
	cout << "monster ability" << endl;
	system("pause");
}

void Monster::ATTACK(Monster &m)
{
	AttackType attackType;
	
	float atk = (getAtk() - m.getDef()) * attackType.getAtkType(getTypeNumber(), m.getTypeNumber());

	m.setHP(m.getHP() - atk);

}

string Monster::getName()
{
	return name;
}

void Monster::setName(string n)
{
	name = n;
}

string Monster::getType()
{
	return type;
}

int Monster::getAbility()
{
	return ability;
}

int Monster::getSpeed()
{
	return speed;
}

void Monster::setSpeed(int num)
{
	speed = num;
}

void Monster::setDef(int num)
{
	defense = num;
}

void Monster::setAtk(int num)
{
	attack = num;
}

Monster& Monster::operator=(const Monster &right)
{
	hp = right.hp;
	maxHp = right.maxHp;
	attack = right.attack;
	defense = right.defense;
	speed = right.speed;
	ability = right.ability;
	type = right.type;
	name = right.name;

	return *this;
}

int Monster::getMax()
{
	return maxHp;
}

int Monster::getTypeNumber()
{
	string type = getType();

	if (type == "Normal")
		return 1;
	else if (type == "Fire")
		return 2;
	else if (type == "Water")
		return 3;
	else if (type == "Electric")
		return 4;
	else if (type == "Grass")
		return 5;
	else if (type == "Ice")
		return 6;
	else if (type == "Fighting")
		return 7;
	else if (type == "Poison")
		return 8;
	else if (type == "Ground")
		return 9;
	else if (type == "Flying")
		return 10;
	else if (type == "Psychic")
		return 11;
	else if (type == "Bug")
		return 12;
	else if (type == "Rock")
		return 13;
	else if (type == "Ghost")
		return 14;
	else if (type == "Dragon")
		return 15;
	else if (type == "Dark")
		return 16;
	else if (type == "Steel")
		return 17;
	else if (type == "Fairy")
		return 18;
}

//--------------------------------------Monster--------------------------------------

//1.Bulbasaur
class Bulbasaur : public Monster
{
public:
	Bulbasaur(int h, int atk, int def, string t, int ab, int s);
	void ABILITY(Monster &m);
private:
};

Bulbasaur::Bulbasaur(int h, int atk, int def, string t, int ab, int s)
	: Monster(h, atk, def, t, ab, s)
{
	setName("Bulbasaur");
}

void Bulbasaur::ABILITY(Monster &m)
{
	setHP(getHP() + 3);
	if (getHP() > getMax())
		setHP(getMax());
}

//2.Ivysaur
class Ivysaur : public Monster
{
public:
	Ivysaur(int h, int atk, int def, string t, int ab, int s);
	void ABILITY(Monster &m);
private:
};

Ivysaur::Ivysaur(int h, int atk, int def, string t, int ab, int s)
	:Monster(h, atk, def, t, ab, s)
{
	setName("Ivysaur");
}

void Ivysaur::ABILITY(Monster &m)
{
	setHP(getHP() + 3);
	if (getHP() > getMax())
		setHP(getMax());
}

//3.Venusaur
class Venusaur : public Monster
{
public:
	Venusaur(int h, int atk, int def, string t, int ab, int s);
	void ABILITY(Monster &m);
private:
};

Venusaur::Venusaur(int h, int atk, int def, string t, int ab, int s)
	:Monster(h, atk, def, t, ab, s)
{
	setName("Venusaur");
}

void Venusaur::ABILITY(Monster &m)
{
	setHP(getHP() + 3);
	if (getHP() > getMax())
		setHP(getMax());
}

//4.Charmander
class Charmander : public Monster
{
public:
	Charmander(int h, int atk, int def, string t, int ab, int s);
	void ABILITY(Monster &m);
private:
};

Charmander::Charmander(int h, int atk, int def, string t, int ab, int s)
	:Monster(h, atk, def, t, ab, s)
{
	setName("Charmander");
}

void Charmander::ABILITY(Monster &m)
{
	m.setHP(m.getHP() - (rand() % 3 + 1));
}

//5.Charmeleon
class Charmeleon : public Monster
{
public:
	Charmeleon(int h, int atk, int def, string t, int ab, int s);
	void ABILITY(Monster &m);
private:
};

Charmeleon::Charmeleon(int h, int atk, int def, string t, int ab, int s)
	:Monster(h, atk, def, t, ab, s)
{
	setName("Charmeleon");
}

void Charmeleon::ABILITY(Monster &m)
{
	m.setHP(m.getHP() - (rand() % 3 + 1));
}

//6.Charizard
class Charizard : public Monster
{
public:
	Charizard(int h, int atk, int def, string t, int ab, int s);
	void ABILITY(Monster &m);
private:
};

Charizard::Charizard(int h, int atk, int def, string t, int ab, int s)
	:Monster(h, atk, def, t, ab, s)
{
	setName("Charizard");
}

void Charizard::ABILITY(Monster &m)
{
	m.setHP(m.getHP() - (rand() % 3 + 1));
}

//7.Squirtle
class Squirtle : public Monster
{
public:
	Squirtle(int h, int atk, int def, string t, int ab, int s);
	void ABILITY(Monster &m);
private:
};

Squirtle::Squirtle(int h, int atk, int def, string t, int ab, int s)
	:Monster(h, atk, def, t, ab, s)
{
	setName("Squirtle");
}

void Squirtle::ABILITY(Monster &m)
{
	m.setHP(m.getHP() - (m.getAtk() - getDef()) * 0.2);
}

//8.Wartortle
class Wartortle : public Monster
{
public:
	Wartortle(int h, int atk, int def, string t, int ab, int s);
	void ABILITY(Monster &m);
private:
};

Wartortle::Wartortle(int h, int atk, int def, string t, int ab, int s)
	:Monster(h, atk, def, t, ab, s)
{
	setName("Wartortle");
}

void Wartortle::ABILITY(Monster &m)
{
	m.setHP(m.getHP() - (m.getAtk() - getDef()) * 0.2);
}

//9.Blastoise
class Blastoise : public Monster
{
public:
	Blastoise(int h, int atk, int def, string t, int ab, int s);
	void ABILITY(Monster &m);
private:
};

Blastoise::Blastoise(int h, int atk, int def, string t, int ab, int s)
	:Monster(h, atk, def, t, ab, s)
{
	setName("Blastoise");
}

void Blastoise::ABILITY(Monster &m)
{
	m.setHP(m.getHP() - (m.getAtk() - getDef()) * 0.2);
}

//10.Caterpie
class Caterpie : public Monster
{
public:
	Caterpie(int h, int atk, int def, string t, int ab, int s);
	void ABILITY(Monster &m);
private:
};

Caterpie::Caterpie(int h, int atk, int def, string t, int ab, int s)
	:Monster(h, atk, def, t, ab, s)
{
	setName("Caterpie");
}

void Caterpie::ABILITY(Monster &m)
{
	
}

//11.Metapod
class Metapod : public Monster
{
public:
	Metapod(int h, int atk, int def, string t, int ab, int s);
	void ABILITY(Monster &m);
private:
};

Metapod::Metapod(int h, int atk, int def, string t, int ab, int s)
	:Monster(h, atk, def, t, ab, s)
{
	setName("Metapod");
}

void Metapod::ABILITY(Monster &m)
{
	return;
}

//12.Butterfree
class Butterfree : public Monster
{
public:
	Butterfree(int h, int atk, int def, string t, int ab, int s);
	void ABILITY(Monster &m);
private:
};

Butterfree::Butterfree(int h, int atk, int def, string t, int ab, int s)
	:Monster(h, atk, def, t, ab, s)
{
	setName("Butterfree");
}

void Butterfree::ABILITY(Monster &m)
{
	return;
}

//13.Weedle
class Weedle : public Monster
{
public:
	Weedle(int h, int atk, int def, string t, int ab, int s);
	void ABILITY(Monster &m);
private:
};

Weedle::Weedle(int h, int atk, int def, string t, int ab, int s)
	:Monster(h, atk, def, t, ab, s)
{
	setName("Weedle");
}

void Weedle::ABILITY(Monster &m)
{
	int blood = rand() % 2 + 2;
	setHP(getHP() + blood);
	m.setHP(m.getHP() - blood);
}

//14.Kakuna
class Kakuna : public Monster
{
public:
	Kakuna(int h, int atk, int def, string t, int ab, int s);
	void ABILITY(Monster &m);
private:
};

Kakuna::Kakuna(int h, int atk, int def, string t, int ab, int s)
	:Monster(h, atk, def, t, ab, s)
{
	setName("Kakuna");
}

void Kakuna::ABILITY(Monster &m)
{
	int blood = rand() % 2 + 2;
	setHP(getHP() + blood);
	m.setHP(m.getHP() - blood);
}

//15.Beedrill
class Beedrill : public Monster
{
public:
	Beedrill(int h, int atk, int def, string t, int ab, int s);
	void ABILITY(Monster &m);
private:
};

Beedrill::Beedrill(int h, int atk, int def, string t, int ab, int s)
	:Monster(h, atk, def, t, ab, s)
{
	setName("Beedrill");
}

void Beedrill::ABILITY(Monster &m)
{
	int blood = rand() % 2 + 2;
	setHP(getHP() + blood);
	m.setHP(m.getHP() - blood);
}

//16.Pidgey
class Pidgey : public Monster
{
public:
	Pidgey(int h, int atk, int def, string t, int ab, int s);
	void ABILITY(Monster &m);
private:
};

Pidgey::Pidgey(int h, int atk, int def, string t, int ab, int s)
	:Monster(h, atk, def, t, ab, s)
{
	setName("Pidgey");
}

void Pidgey::ABILITY(Monster &m)
{
	int chance = rand() % 5;
	if (chance == 1)
		setHP(getHP() + (m.getAtk() - getDef()));
}

//17.Pidgeotto
class Pidgeotto : public Monster
{
public:
	Pidgeotto(int h, int atk, int def, string t, int ab, int s);
	void ABILITY(Monster &m);
private:
};

Pidgeotto::Pidgeotto(int h, int atk, int def, string t, int ab, int s)
	:Monster(h, atk, def, t, ab, s)
{
	setName("Pidgeotto");
}

void Pidgeotto::ABILITY(Monster &m)
{
	int chance = rand() % 5;
	if (chance == 1)
		setHP(getHP() + (m.getAtk() - getDef()));
}

//18.Pidgeot
class Pidgeot : public Monster
{
public:
	Pidgeot(int h, int atk, int def, string t, int ab, int s);
	void ABILITY(Monster &m);
private:
};

Pidgeot::Pidgeot(int h, int atk, int def, string t, int ab, int s)
	:Monster(h, atk, def, t, ab, s)
{
	setName("Pidgeot");
}

void Pidgeot::ABILITY(Monster &m)
{
	int chance = rand() % 5;
	if (chance == 1)
		setHP(getHP() + (m.getAtk() - getDef()));
}

//19.Rattata
class Rattata : public Monster
{
public:
	Rattata(int h, int atk, int def, string t, int ab, int s);
	void ABILITY(Monster &m);
private:
};

Rattata::Rattata(int h, int atk, int def, string t, int ab, int s)
	:Monster(h, atk, def, t, ab, s)
{
	setName("Rattata");
}

void Rattata::ABILITY(Monster &m)
{
	//none
}

//20.Raticate
class Raticate : public Monster
{
public:
	Raticate(int h, int atk, int def, string t, int ab, int s);
	void ABILITY(Monster &m);
private:
};

Raticate::Raticate(int h, int atk, int def, string t, int ab, int s)
	:Monster(h, atk, def, t, ab, s)
{
	setName("Raticate");
}

void Raticate::ABILITY(Monster &m)
{
	//none
}

//21.Spearow
class Spearow : public Monster
{
public:
	Spearow(int h, int atk, int def, string t, int ab, int s);
	void ABILITY(Monster &m);
private:
};

Spearow::Spearow(int h, int atk, int def, string t, int ab, int s)
	:Monster(h, atk, def, t, ab, s)
{
	setName("Spearow");
}

void Spearow::ABILITY(Monster &m)
{
	int chance = rand() % 5;
	if (chance == 1)
		ATTACK(m);
}

//22.Fearow
class Fearow : public Monster
{
public:
	Fearow(int h, int atk, int def, string t, int ab, int s);
	void ABILITY(Monster &m);
private:
};

Fearow::Fearow(int h, int atk, int def, string t, int ab, int s)
	:Monster(h, atk, def, t, ab, s)
{
	setName("Fearow");
}

void Fearow::ABILITY(Monster &m)
{
	int chance = rand() % 5;
	if (chance == 1)
		ATTACK(m);
}

//23.Ekans
class Ekans : public Monster
{
public:
	Ekans(int h, int atk, int def, string t, int ab, int s);
	void ABILITY(Monster &m);
private:
};

Ekans::Ekans(int h, int atk, int def, string t, int ab, int s)
	:Monster(h, atk, def, t, ab, s)
{
	setName("Ekans");
}

void Ekans::ABILITY(Monster &m)
{
	m.setHP(m.getHP() - 2);
}

//24.Arbok
class Arbok : public Monster
{
public:
	Arbok(int h, int atk, int def, string t, int ab, int s);
	void ABILITY(Monster &m);
private:
};

Arbok::Arbok(int h, int atk, int def, string t, int ab, int s)
	:Monster(h, atk, def, t, ab, s)
{
	setName("Arbok");
}

void Arbok::ABILITY(Monster &m)
{
	m.setHP(m.getHP() - 2);
}

//25.Pikachu
class Pikachu : public Monster
{
public:
	Pikachu(int h, int atk, int def, string t, int ab, int s);
	void ABILITY(Monster &m);
private:
};

Pikachu::Pikachu(int h, int atk, int def, string t, int ab, int s)
	:Monster(h, atk, def, t, ab, s)
{
	setName("Pikachu");
}

void Pikachu::ABILITY(Monster &m)
{
	m.setSpeed(m.getSpeed() - 2);
}

//26.Raichu
class Raichu : public Monster
{
public:
	Raichu(int h, int atk, int def, string t, int ab, int s);
	void ABILITY(Monster &m);
private:
};

Raichu::Raichu(int h, int atk, int def, string t, int ab, int s)
	:Monster(h, atk, def, t, ab, s)
{
	setName("Raichu");
}

void Raichu::ABILITY(Monster &m)
{
	m.setSpeed(m.getSpeed() - 2);
}

//27.Sandshrew
class Sandshrew : public Monster
{
public:
	Sandshrew(int h, int atk, int def, string t, int ab, int s);
	void ABILITY(Monster &m);
private:
};

Sandshrew::Sandshrew(int h, int atk, int def, string t, int ab, int s)
	:Monster(h, atk, def, t, ab, s)
{
	setName("Sandshrew");
}

void Sandshrew::ABILITY(Monster &m)
{
	setDef(getDef() + 2);
}

//28.Sandslash
class Sandslash : public Monster
{
public:
	Sandslash(int h, int atk, int def, string t, int ab, int s);
	void ABILITY(Monster &m);
private:
};

Sandslash::Sandslash(int h, int atk, int def, string t, int ab, int s)
	:Monster(h, atk, def, t, ab, s)
{
	setName("Sandslash");
}

void Sandslash::ABILITY(Monster &m)
{
	setDef(getDef() + 2);
}

//29.Nidoran¡ð
class NidoranG : public Monster
{
public:
	NidoranG(int h, int atk, int def, string t, int ab, int s);
	void ABILITY(Monster &m);
private:
};

NidoranG::NidoranG(int h, int atk, int def, string t, int ab, int s)
	:Monster(h, atk, def, t, ab, s)
{
	setName("NidoranG");
}

void NidoranG::ABILITY(Monster &m)
{
	m.setDef(m.getDef() - 2);
}

//30.Nidorina
class Nidorina : public Monster
{
public:
	Nidorina(int h, int atk, int def, string t, int ab, int s);
	void ABILITY(Monster &m);
private:
};

Nidorina::Nidorina(int h, int atk, int def, string t, int ab, int s)
	:Monster(h, atk, def, t, ab, s)
{
	setName("Nidorina");
}

void Nidorina::ABILITY(Monster &m)
{
	m.setDef(m.getDef() - 2);
}

//31.Nidoqueen
class Nidoqueen : public Monster
{
public:
	Nidoqueen(int h, int atk, int def, string t, int ab, int s);
	void ABILITY(Monster &m);
private:
};

Nidoqueen::Nidoqueen(int h, int atk, int def, string t, int ab, int s)
	:Monster(h, atk, def, t, ab, s)
{
	setName("Nidoqueen");
}

void Nidoqueen::ABILITY(Monster &m)
{
	m.setDef(m.getDef() - 2);
}

//32.Nidoran¡ñ
class NidoranB : public Monster
{
public:
	NidoranB(int h, int atk, int def, string t, int ab, int s);
	void ABILITY(Monster &m);
private:
};

NidoranB::NidoranB(int h, int atk, int def, string t, int ab, int s)
	:Monster(h, atk, def, t, ab, s)
{
	setName("NidoranB");
}

void NidoranB::ABILITY(Monster &m)
{
	m.setAtk(m.getAtk() - 2);
}

//33.Nidorino
class Nidorino : public Monster
{
public:
	Nidorino(int h, int atk, int def, string t, int ab, int s);
	void ABILITY(Monster &m);
private:
};

Nidorino::Nidorino(int h, int atk, int def, string t, int ab, int s)
	:Monster(h, atk, def, t, ab, s)
{
	setName("Nidorino");
}

void Nidorino::ABILITY(Monster &m)
{
	m.setAtk(m.getAtk() - 2);
}

//34.Nidoking
class Nidoking : public Monster
{
public:
	Nidoking(int h, int atk, int def, string t, int ab, int s);
	void ABILITY(Monster &m);
private:
};

Nidoking::Nidoking(int h, int atk, int def, string t, int ab, int s)
	:Monster(h, atk, def, t, ab, s)
{
	setName("Nidoking");
}

void Nidoking::ABILITY(Monster &m)
{
	m.setAtk(m.getAtk() - 2);
}

#endif
