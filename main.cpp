#include "Hero.h"
#include "HeroFileError.h"
#include "jsonParser.h"


/**
 * \brief the main function of the program 
 * \param argc number of the command line parameters 
 * \param argv command line parameters
 * \return 0 if the code goes well and 1 if we have error
 * 
*/
int main(int, char* argv[]) {
	/**
	 * This function have a try catch control flow.
	 * The main reason is that we can't be sure that the file name is correct or even it is exists.
	*/
	try {
		Hero h1 = Hero::parseUnit(argv[1]);
		Hero h2 = Hero::parseUnit(argv[2]);

		h1.fight(h2);
	
		if (h1.getActHp() == 0) {
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