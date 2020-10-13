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
	const float atkspeed;
	const std::string name;
	float nextAttack=atkspeed;
	void getAttack (const Hero& enemy);

public:
	Hero(const std::string name, int hp, const int dmg, const float atkspeed) : name(name), hp(hp), dmg(dmg), atkspeed(atkspeed){}
	friend std::ostream& operator << (std::ostream& os, const Hero& hero);
	std::string getName() const { return name; }
	int getHp() const { return hp; }
	int getDmg() const { return dmg; }
	static Hero parseUnit (const std::string& filename);
	float getAtkspeed() const { return atkspeed; }
	void setNextAttack() { nextAttack+=atkspeed; }
	float getNextAttack() const {return nextAttack; }
	void fight(Hero& attacked);
	void takeAttack(Hero& enemy) { enemy.getAttack(*this); }

};



#endif 