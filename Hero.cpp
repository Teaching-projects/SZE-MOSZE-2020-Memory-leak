#include "Hero.h"
#include "HeroFileError.h"

void Hero::getAttack(const Hero& h)
{
/**
 * After a hero get attecked reduce its HP by the DMG of the enemy, if the reduced hp is less then 0 set it 0.
*/
	if (hp - h.getDmg() > 0) { hp -= h.getDmg(); }
	else { hp = 0; }
}

Hero Hero::parseUnit(const std::string& filename)
{
	/**
	 * Setting the hero properties from a JSON file.
	*/
	std::ifstream jsonFile(filename);

	if (jsonFile.fail()) { throw HeroFileError("Can't open the file."); }

	std::string line;
	std::string key;
	int pos;
	std::string name;
	int hp;
	int dmg;
	float atkspeed;

	while (getline(jsonFile, line))
	{
		if (line == "{" || line == "}") {}
		else
		{
			key = "";
			pos = line.find("\"");
			line = line.erase(0, pos + 1);
			pos = line.find("\"");
			for (int i = 0; i < pos; i++)
			{
				key += line[i];
			}
			line = line.erase(0, pos + 4);

			if (key == "name") {
				line.erase(0, 1);
				line.erase(line.size() - 3);
				name = line;
			}

			else if (key == "hp")
			{
				line.erase(line.size());
				hp = std::stoi(line);
			}

			else if (key == "dmg")
			{
				line.erase(line.size());
				dmg = std::stoi(line);
			}

			else if (key == "attackCooldown")
			{
				atkspeed = std::stof(line);
			}
		}
	}
	jsonFile.close();
	return Hero(name, hp, dmg, atkspeed);
}

void Hero::fight(Hero& attacked){
	/**
	 * Here happens the fight. First the attacker attacks then the other Hero after that if both of them survives the first attack the timers start. 
	 * The hero who needs less seconds to attack attacks first then we "reset" his timer. 
	 * After the reset we repeat it until one of them has 0 or less than 0 attack
	*/
	attacked.takeAttack(*this);
	this->takeAttack(attacked);

	while (this->getHp() > 0 && attacked.getHp() > 0)
	{
		if (this->getNextAttack() <= attacked.getNextAttack()) {
			attacked.takeAttack(*this);
			this->setNextAttack();
		}
		else
		{
			this->takeAttack(attacked);
			attacked.setNextAttack();
		}

	}

	if (this->getHp() == 0) {
		std::cout << attacked;
	}
	else
	{
		std::cout << *this;
	}
}

std::ostream & operator<<(std::ostream & os, const Hero & hero)
/**
 * Writng out the winner and the remaining HP
*/
{
	os << hero.name << " wins. Remaining HP: " << hero.hp << std::endl;
	return os;
}
