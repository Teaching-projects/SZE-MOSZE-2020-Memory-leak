/**
 * \class Hero
 * 
 * \brief Hero class
 * 
 * \author Peti96, joostibor, Krisiiii98
 * 
 * \version 0.5
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
#include <cmath>

#include "JSON.h"
#include "Monster.h"

class Hero : public Monster
{
private:
	const int bonus_health_per_level; ///< The hero keep this hp in every levelup.
	int xp; ///< The xp of the hero.
	const int xpforlvlup; ///< The xp what need for levelup.
	int lvl; ///< The lvl what the hero is in.
	const int bonus_damage_per_level; ///< The hero keep this damage in every levelup.
	const float atkspeed_multiplier; ///< This multiplier reduce the hero's attack cooldown in every levelup.
	/**
	 * \brief increment the xp of the hero
	 * \param getxp the xp, what the hero will recive
	*/
	void incXp(int getxp);

public:
/**
 * Setting the hero properties and the required things to the battle.
*/
	/**
	 * \brief constructor for the hero class
	 * \param name the name of the hero
	 * \param maxhp the maximum healt points of the hero
	 * \param bonus_health_per_level the hp, what keep the hero in levelup.
	 * \param xpforlvlup how many xp need for levelup.
	 * \param dmg the damage of the hero
	 * \param bonus_dmg_per_level the dmg, what keep the hero in levelup.
	 * \param atkspeed_multiplier this multiplier reduce atkspeed in levelup.
	 * \param atkspeed the attack speed of the hero
	 * 
	*/
	Hero(const std::string name, int maxhp, const int bonus_health_per_level, const int xpforlvlup, int dmg,
	    const int bonus_dmg_per_level, const float atkspeed_multiplier, float atkspeed)
		: Monster(name, maxhp, dmg, atkspeed), bonus_health_per_level(bonus_health_per_level),
		xp(0), xpforlvlup(xpforlvlup), lvl(1), bonus_damage_per_level(bonus_dmg_per_level),
		atkspeed_multiplier(atkspeed_multiplier) {} 	
	/**
	 * \brief parse hero from json file or string input
	 * \param s name of the json file or the content of string parameter
	 * \return the read hero
	*/
	static Hero parse (const std::string& s);
	/**
	 * \brief parse hero from inputstream
	 * \param stream the input stream what contain the hero's attribute
	 * \return the read hero
	*/
	static Hero parse (std::istream& stream);
	/**
	 * \brief A monster get damage from the hero
	 * \param m constant reference for the monster who get the attack
	 * \return 0 if the funciton gonna be okay.
	*/
	virtual int takeAttack (Monster& m) override; 
	/**
	 * \brief getter for the xp of the hero
	 * \return the xp of the hero
	*/
	int getXp() const { return xp; }
	/**
	 * \brief getter for the level of the hero
	 * \return the level of the hero
	*/
	int getLevel() const { return lvl; }
};

#endif 
