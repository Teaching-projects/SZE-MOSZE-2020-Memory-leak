#include "Hero.h"
#include "HeroFileError.h"

void Hero::getAttack(const Hero& h)
{
	if (hp - h.getDmg() > 0) { hp -= h.getDmg(); }
	else { hp = 0; }
}

Hero Hero::parseUnit(const std::string& s)
{
	jsonMap heroData = jsonParser::parseFile(s);
	return Hero(heroData["name"], std::stoi(heroData["hp"]), std::stoi(heroData["dmg"]));
}

Hero Hero::parseUnit(std::istream& stream){
	jsonMap heroData = jsonParser::parseStream(stream);
	return Hero(heroData["name"], std::stoi(heroData["hp"]), std::stoi(heroData["dmg"]));
}

std::ostream & operator<<(std::ostream & os, const Hero & hero)
{
	os << hero.name << " wins. Remaining HP: " << hero.hp << std::endl;
	return os;
}
