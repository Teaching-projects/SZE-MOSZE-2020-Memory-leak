#include "Hero.h"
#include "HeroFileError.h"

int main(int argc, char* argv[]) {
	/**
	 * The programs starts with a try and if everything goes well it returns 0 and the program run.
	 * If the we can not reach the file the catch will return 1
	*/
	try {
		Hero h1 = Hero::parseUnit(argv[1]);
		Hero h2 = Hero::parseUnit(argv[2]);

		h1.fight(h2);
	
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