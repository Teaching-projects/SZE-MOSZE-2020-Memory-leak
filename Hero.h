#ifndef HERO_H
#define HERO_H

#include <string>
#include <iostream>
#include <fstream>
#include <cmath>

class Hero
{
protected:
	const std::string name;
	int acthp;
	int maxhp;
	int dmg;
	int xp;
	

public:
	Hero(const std::string name, int maxhp, const int dmg) : name(name), acthp(maxhp), maxhp(maxhp), dmg(dmg), xp(0) {}

	friend std::ostream& operator << (std::ostream& os, const Hero& hero);
	void getAttack (Hero& h);
	std::string getName() const { return name; }
	int getActHp() const { return acthp; }
	int getMaxHp() const { return maxhp; }
	int getDmg() const { return dmg; }
	int getXp() const { return xp; }
	void incXp (int getxp);
	static Hero parseUnit (const std::string& filename);
};



#endif 