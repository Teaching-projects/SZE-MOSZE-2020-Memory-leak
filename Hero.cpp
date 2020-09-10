#include "Hero.h"

int Hero::lesshp(int hp, const int edmg)
{
	return hp -= edmg;
}

void Hero::draw(const std::string n1, const std::string n2, int hp1, int hp2, const int dmg1, const int dmg2, bool round)
{
	if (hp1 > 0 && hp2 > 0)
	{
		std::cout << n1 << ": HP: " << hp1 << ", DMG: " << dmg1 << std::endl;
		std::cout << n2 << ": HP: " << hp2 << ", DMG: " << dmg2 << std::endl;
		if (round) std::cout << n1 << " -> " << n2 << std::endl;
		else
		{
			std::cout << n2 << " -> " << n1 << std::endl;
		}
	}
	else if (hp1 < 0)
	{
		std::cout << n1 << ": HP: " << 0 << ", DMG: " << dmg1 << std::endl;
		std::cout << n2 << ": HP: " << hp2 << ", DMG: " << dmg2 << std::endl;
		std::cout << n1 << " died. " << n2 << " wins.";
	}
	else if (hp2 < 0)
	{
		std::cout << n1 << ": HP: " << hp1 << ", DMG: " << dmg1 << std::endl;
		std::cout << n2 << ": HP: " << 0 << ", DMG: " << dmg2 << std::endl;
		std::cout << n2 << " died. " << n1 << " wins.";
	}
}

Hero::Hero(const std::string name, int hp, const int dmg)
	: name(name), hp(hp), dmg(dmg)
{
}

Hero::~Hero()
{
}
