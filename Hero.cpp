#include "Hero.h"

void Hero::getAttack(const Hero& h)
{
	if (hp - h.getDmg() > 0) { hp -= h.getDmg(); }
	else { hp = 0; }
}

std::ostream & operator<<(std::ostream & os, const Hero & hero)
{
	os << hero.name << ": HP: " << hero.hp << ", DMG: " << hero.dmg << std::endl;
	return os;
}
