#ifndef HERO_H
#define HERO_H

#include <string>
#include <iostream>

class Hero
{
private:
	int hp;
	const int dmg;
	const std::string name;

public:
	Hero(const std::string name, int hp, const int dmg);
	~Hero();

	int lesshp(int hp, const int edmg);
	void draw(const std::string n1, const std::string n2, int hp1, int hp2, const int dmg1, const int dmg2, bool round);
	std::string getName() const { return name; }
	int getHp() const { return hp; }
	int getDmg() const { return dmg; }
};



#endif 