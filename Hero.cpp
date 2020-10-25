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
		atkspeed = (float)round(atkspeed * 0.9);
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

Hero Hero::parseUnit(const std::string& s)
{
	/**
	 * This function read from file, or string input.
	 * This make a jsonMap type map and parse the hero.
	 * After parsing this return a new Hero, with the parsed attributes.
	*/
	jsonMap heroData = jsonParser::parseFile(s);
	return Hero(heroData["name"], std::stoi(heroData["hp"]), std::stoi(heroData["dmg"]), std::stof(heroData["attackCooldown"]));
}

Hero Hero::parseUnit(std::istream& stream){
	/**
	 * This function read from file, or string input.
	 * This make a jsonMap type map and parse the hero.
	 * After parsing this return a new Hero, with the parsed attributes.
	*/
	jsonMap heroData = jsonParser::parseStream(stream);
	return Hero(heroData["name"], std::stoi(heroData["hp"]), std::stoi(heroData["dmg"]), std::stof(heroData["attackCooldown"]));
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
