#ifndef HERO_H
#define HERO_H

#include <string>
#include <iostream>
#include <fstream>

class Hero
{
private:
	int hp;
	const int dmg;
	const std::string name;

public:
	Hero(const std::string name, int hp, const int dmg) : name(name), hp(hp), dmg(dmg) {}

	friend std::ostream& operator << (std::ostream& os, const Hero& hero);
	void getAttack (const Hero& h);
	std::string getName() const { return name; }
	int getHp() const { return hp; }
	int getDmg() const { return dmg; }
	static Hero parseUnit (const std::string& filename);
};



#endif 