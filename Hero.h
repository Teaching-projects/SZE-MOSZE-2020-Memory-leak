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
	~Hero() {}

	friend std::ostream& operator << (std::ostream& os, const Hero& hero);
	const void attackEnemy (Hero& h1, Hero& h2);
	std::string getName() const { return name; }
	int getHp() const { return hp; }
	int getDmg() const { return dmg; }
};



#endif 