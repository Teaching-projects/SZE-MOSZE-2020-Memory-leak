#include "Hero.h"

int main(int argc, char *argv[]) {
	Hero h1(argv[1], std::stoi(argv[2]), std::stoi(argv[3]));
	Hero h2(argv[4], std::stoi(argv[5]), std::stoi(argv[6]));

	bool round = false;

	do
	{
		round = !round;
		if (round) {
			std::cout << h1;
			std::cout << h2;
			std::cout << h1.getName() << " -> " << h2.getName() << std::endl;
			h2.getAttack(h1);
		}
		else
		{
			std::cout << h1;
			std::cout << h2;
			std::cout << h2.getName() << " -> " << h1.getName() << std::endl;
			h1.getAttack(h2);
		}

	} while (h1.getHp() > 0 && h2.getHp() > 0);

	if (h1.getHp() == 0) { 
		std::cout << h1;
		std::cout << h2;
		std::cout << h1.getName() << " died. " << h2.getName() << " wins."; 
	}
	else
	{
		std::cout << h1;
		std::cout << h2;
		std::cout << h2.getName() << " died. " << h1.getName() << " wins.";
	}
}