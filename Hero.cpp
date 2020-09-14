#include "Hero.h"

Hero::Hero(const std::string name,  int hp, const int dmg)
	: name(name), hp(hp), dmg(dmg)
{
}

const void Hero::attackEnemy(Hero& h2, Hero& h1)
{
	if (h2.hp - h1.getDmg() > 0) { h2.hp -= h1.getDmg(); }
	else
	{
		h2.hp = 0;
	}
}

std::ostream & operator<<(std::ostream & os, const Hero & hero)
{
	os << hero.name << ": HP: " << hero.hp << ", DMG: " << hero.dmg << std::endl;
	return os;
}
