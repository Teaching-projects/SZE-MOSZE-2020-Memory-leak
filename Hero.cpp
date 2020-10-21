#include "Hero.h"
#include "HeroFileError.h"

void Hero::incXp(int getxp) {
	/**
	 * The Hero get xp from attack and if it reach 100 xp it keep some extra dmg and hp.
	 * And its actual hp will be its maximum hp.
	*/
	this->xp += getxp;
	while(this->xp >= 100){
		maxhp = (int)round(maxhp * 1.10);
		dmg = (int)round(dmg * 1.10);
		acthp = maxhp;
		xp -= 100;
	}
}

void Hero::getAttack(Hero& h)
{
	/**
	 * The hero keep attack for enemy hero and decrease its hp.
	 * The attacker hero keep xp as much as it decrease from enemy.
	*/
	if (acthp - h.getDmg() > 0) { 
		acthp -= h.getDmg();
		h.incXp(h.getDmg());
	}
	else { 
		acthp = 0; 
		h.incXp(acthp);
	}
}

Hero Hero::parseUnit(const std::string& filename)
{
	/**
	 * Reading the hero properties from a JSON file and return the hero.
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

Hero Hero::fight(Hero& attacked){
	/**
	 * Here happens the fight. First the attacker attacks then the other Hero after that if both of them survives the first attack the timers start. 
	 * The hero who needs less seconds to attack attacks first then we "reset" his timer. 
	 * After the reset we repeat it until one of them has 0 or less than 0 attack
	*/
	attacked.getAttack(*this);
	this->getAttack(attacked);

	while (this->getActHp() > 0 && attacked.getActHp() > 0)
	{
		if (this->getNextAttack() <= attacked.getNextAttack()) {
			attacked.getAttack(*this);
			this->setNextAttack();
		}
		else
		{
			this->getAttack(attacked);
			attacked.setNextAttack();
		}

	}

	if (this->getActHp() == 0) {
		return attacked;
	}
	else
	{
		return *this;
	}
}

std::ostream & operator<<(std::ostream & os, const Hero & hero)
/**
 * Writng out the winner and the remaining HP
*/
{
	os << hero.name << " wins. Remaining HP: " << hero.acthp << std::endl;
	return os;
}