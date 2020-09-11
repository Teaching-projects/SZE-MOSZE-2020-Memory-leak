#include "Hero.h"

int main(int argc, char *argv[]) {
	Hero* h1 = new Hero(argv[1], std::stoi(argv[2]), std::stoi(argv[3]));
	Hero* h2 = new Hero(argv[4], std::stoi(argv[5]), std::stoi(argv[6]));

	bool round = true;

	do
	{
		if (round) {
			std::cout << h1;
			std::cout << h2;
			std::cout << h1->getName() << " -> " << h2->getName() << std::endl;
			h1->attackEnemy(h2);
			if (h2->getHp() < 0) { std::cout << h2->getName() << " died. " << h1->getName() << " wins."; }
			else
			{
				round = false;
			}
		}
		else
		{
			std::cout << h1;
			std::cout << h2;
			std::cout << h2->getName() << " -> " << h1->getName() << std::endl;
			h2->attackEnemy(h1);
			if (h1->getHp() < 0) { std::cout << h1->getName() << " died. " << h2->getName() << " wins."; }
			else
			{
				round = true;
			}
		}

	} while (h1->getHp() > 0 && h2->getHp() > 0);

	delete h1;
	delete h2;
}