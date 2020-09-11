#include "Hero.h"

Hero::Hero(const std::string name, int hp, const int dmg)
	: name(name), hp(hp), dmg(dmg)
{
}

Hero::~Hero()
{
}

void Hero::attackEnemy(Hero* h)
{
	h->hp -= dmg;
}

std::ostream & operator<<(std::ostream & os, const Hero & hero)
{
	os << hero.name << ": HP: " << hero.hp << ", DMG: " << hero.dmg << std::endl;
	return os;
}
