#include "Hero.h"
#include "HeroFileError.h"

int main(int argc, char* argv[]) {
	(void)argc;
	try {
		Hero h1 = Hero::parseUnit(argv[1]);
		Hero h2 = Hero::parseUnit(argv[2]);

		bool round = false;

		do
		{
			round = !round;
			if (round) {
				h2.getAttack(h1);
			}
			else
			{
				h1.getAttack(h2);
			}

		} while (h1.getHp() > 0 && h2.getHp() > 0);

		if (h1.getHp() == 0) {
			std::cout << h2;
		}
		else
		{
			std::cout << h1;
		}
	}

	catch (HeroFileError ex) {
		std::cout << ex << std::endl;
		return 1;
	}

	return 0;
}