#include "Hero.h"

int main() {
	Hero* h1 = new Hero("Maple", 150, 10);
	Hero* h2 = new Hero("Sally", 45, 30);
	bool round = true;
	std::string n1 = h1->getName();
	int hp1 = h1->getHp();
	int dmg1 = h1->getDmg();
	std::string n2 = h2->getName();
	int hp2 = h2->getHp();
	int dmg2 = h2->getDmg();

	while (hp1 > 0 && hp2 > 0)
	{
		if (round)
		{
			h1->draw(n1, n2, hp1, hp2, dmg1, dmg2, round);
			hp2 = h1->lesshp(hp2, dmg1);
			if (hp2 > 0) {
				round = false;
			}
			else
			{
				h1->draw(n1, n2, hp1, hp2, dmg1, dmg2, round);
			}
		}
		else
		{
			h2->draw(n1, n2, hp1, hp2, dmg1, dmg2, round);
			hp1 = h2->lesshp(hp1, dmg2);
			if (hp1 > 0) {
				round = true;
			}
			else
			{
				h2->draw(n1, n2, hp1, hp2, dmg1, dmg2, round);
			}
		}
	}

	return 0;
}