#ifndef HERO_H
#define HERO_H

#include <string>
#include <iostream>
#include <fstream>

class Hero
{
protected:
	int acthp;
	int maxhp;
	int xp;
	int dmg;
	const std::string name;

public:
	Hero(const std::string name, int maxhp, const int dmg) : name(name), acthp(maxhp), maxhp(maxhp), xp(0), dmg(dmg) {}

	friend std::ostream& operator << (std::ostream& os, const Hero& hero);
	void getAttack (Hero& h);
	std::string getName() const { return name; }
	int getActHp() const { return acthp; }
	int getMaxHp() const { return maxhp; }
	int getDmg() const { return dmg; }
	int getXp() const { return xp; }
	static Hero parseUnit (const std::string& filename);
};



#endif 