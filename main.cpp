#include "Hero.h"
#include "HeroFileError.h"

int main(int argc, char* argv[]) {
	try {
		Hero h1 = Hero::parseUnit(argv[1]);
		Hero h2 = Hero::parseUnit(argv[2]);

		h1.fight(h2);
	}

	catch (HeroFileError ex) {
		std::cout << ex << std::endl;
		return 1;
	}

	return 0;
}