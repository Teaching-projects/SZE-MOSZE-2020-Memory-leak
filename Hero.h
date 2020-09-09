#ifndef HERO_H
#define HERO_H

#include <string>
#include <iostream>

class Hero
{
private:
	int hp;
	int dmg;
	std::string name;

public:
	Hero(std::string name, int hp, int dmg);
	~Hero();

	int lesshp(int hp, int edmg);
	void draw(std::string n1, std::string n2, int hp1, int hp2, int dmg1, int dmg2, bool round);
	std::string getName() { return name; }
	int getHp() { return hp; }
	int getDmg() { return dmg; }
};



#endif 