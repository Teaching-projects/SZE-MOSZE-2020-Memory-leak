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
	const int bonus_physical_damage_per_level; ///< The hero keep this physical damage in every levelup.
	const int bonus_magical_damage_per_level; ///< The hero keep this magical damage in every levelup.
	const float atkspeed_multiplier; ///< This multiplier reduce the hero's attack cooldown in every levelup.
	const int bonus_defense_per_level; ///< The hero keep this defense in every levelup.
	int light_radius; ///< The radius, which the hero can see.
	const int bonus_light_radius; ///< The radius which the hero keep in every levelup.

public:
/**
 * Setting the hero properties and the required things to the battle.
*/
	/**
	 * \brief constructor for the hero class where the JSON has all infos
	 * \param name the name of the hero
	 * \param maxhp the maximum healt points of the hero
	 * \param bonus_health_per_level the hp, what keep the hero in levelup.
	 * \param xpforlvlup how many xp need for levelup.
	 * \param physical_damage the physical damage of the hero
	 * \param magical_damage the magical damage of the hero
	 * \param bonus_physical_dmg_per_level the physical dmg, what keep the hero in levelup.
	 * \param bonus_magical_dmg_per_level the magical dmg, what keep the hero in levelup.
	 * \param atkspeed_multiplier this multiplier reduce atkspeed in levelup.
	 * \param atkspeed the attack speed of the hero
	 * \param bonus_defense_per_level the defense, what keep the hero in levelup
	 * \param light_radius the radius, what the hero can see
	 * \param bonus_light_radius the radius what the hero keep in every levelup
	 * \param texture the svg texture of the hero
	*/
	Hero(const std::string name, int maxhp, const int bonus_health_per_level, const int xpforlvlup, int physical_damage, int magical_damage,
	    const int bonus_physical_dmg_per_level, const int bonus_magical_dmg_per_level, const float atkspeed_multiplier, float atkspeed,
		const int defense, const int bonus_defense_per_level, int light_radius, const int bonus_light_radius, const std::string texture)
		: Monster(name, maxhp, physical_damage, magical_damage, defense, atkspeed, texture), bonus_health_per_level(bonus_health_per_level),
		xp(0), xpforlvlup(xpforlvlup), lvl(1), bonus_physical_damage_per_level(bonus_physical_dmg_per_level), bonus_magical_damage_per_level(bonus_magical_dmg_per_level),
		atkspeed_multiplier(atkspeed_multiplier), bonus_defense_per_level(bonus_defense_per_level),
		light_radius(light_radius), bonus_light_radius(bonus_light_radius){} 	

	/**
	 * \brief constructor for the hero class where the JSON don't have all attributes
	 * \param name the name of the hero
	 * \param maxhp the maximum healt points of the hero
	 * \param xpforlvlup how many xp need for levelup.
	 * \param physical_damage the physical damage of the hero
	 * \param magical_damage the magical damage of the hero
	 * \param atkspeed the attack speed of the hero
	 * \param texture the svg texture of the hero
	*/
	Hero(const std::string name, int maxhp, const int bonus_health_per_level, const int xpforlvlup, int physical_damage, int magical_damage, float atkspeed,
		const int defense, const std::string texture)
		: Monster(name, maxhp, physical_damage, magical_damage, defense, atkspeed, texture), bonus_health_per_level(0),
		xp(0), xpforlvlup(xpforlvlup), lvl(1), bonus_physical_damage_per_level(0), bonus_magical_damage_per_level(0),
		atkspeed_multiplier(1), bonus_defense_per_level(0),
		light_radius(2), bonus_light_radius(1){} 
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
	/**
	 * \brief increment the xp of the hero
	 * \param getxp the xp, what the hero will recive
	*/
	void incXp(const int getxp);
	/**
	 * \brief getter for the light radius of the hero
	 * \return the light radius of the hero
	*/
	int getLightRadius() const { return light_radius; }
};

#endif 
