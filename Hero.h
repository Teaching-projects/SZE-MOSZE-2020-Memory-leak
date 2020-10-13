/**
 * \class Hero
 * 
 * \brief Hero class
 * 
 * Here we crate the heroes and set their properties.
 * 
 * \date 2020/10/13
 * 
*/


#ifndef HERO_H
#define HERO_H

#include <string>
#include <iostream>
#include <fstream>

class Hero
{
private:
	int hp; ///< The starting HP of the heroes
	const int dmg; ///< The damage of the heroes
	const float atkspeed; ///< How many seconds pass between the attacks of the hero
	const std::string name; ///< The name of the hero
	float nextAttack=atkspeed; ///< Keeps track of the current attackspeed
	void getAttack (const Hero& enemy); ///< A hero take damage from another hero
	std::string getName() const { return name; } ///< getter for the name of the hero
	int getDmg() const { return dmg; } ///< getter for the damage of the hero
	float getAtkspeed() const { return atkspeed; } ///< getter for the attack speed of the hero
	void setNextAttack() { nextAttack+=atkspeed; } ///< after an attack setting the nextattack as a "timer" 
	float getNextAttack() const {return nextAttack; } ///< getter for the next attack of the hero

public:
/**
 * Setting the hero properties and the required things to the battle.
*/
	Hero(const std::string name, int hp, const int dmg, const float atkspeed) : name(name), hp(hp), dmg(dmg), atkspeed(atkspeed){} ///< Setting the heroes properties
	friend std::ostream& operator << (std::ostream& os, const Hero& hero); /// operator overloading
	static Hero parseUnit (const std::string& filename); ///< reading the properties from file
	Hero fight(Hero& attacked); ///< the hero who get attacked
	int getHp() const { return hp; } ///< getter for the hp of the hero
};



#endif 