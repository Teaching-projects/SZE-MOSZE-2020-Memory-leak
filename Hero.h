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
#include <cmath>

class Hero
{
private:
	const std::string name; ///< The name of the hero
	int acthp; ///< The actual hp of the hero
	int maxhp; ///< The maximum hp of the hero at the start
	int xp; ///< The xp of the hero
	int dmg; ///< The damage of the heroes
	const float atkspeed; ///< How many seconds pass between the attacks of the hero
	float nextAttack=atkspeed; ///< Keeps track of the current attackspeed
	/**
	 * \brief A hero get damage from another hero
	 * \param enemy constant reference for the hero who get the attack
	*/
	void getAttack (Hero& h); 
	/**
	 * \brief getter for the name of the hero
	 * \return the name of the hero
	*/
	std::string getName() const { return name;}
	/**
	 * \brief getter for the maximum hp of the hero
	 * \return the maximum hp of the hero
	*/
	int getMaxHp() const { return maxhp; }
	/**
	 * \brief getter for the damage of the hero
	 * \return the damage of the hero
	*/
	int getDmg() const { return dmg; }
	/**
	 * \brief getter for the xp of the hero
	 * \return the xp of the hero
	*/
	int getXp() const { return xp; }
	/**
	 * \brief getter for the attack speed of the hero
	 * \return the attack speed of the hero
	*/
	float getAtkspeed() const { return atkspeed; }
	void setNextAttack() { nextAttack+=atkspeed; } /// simple setter for the next attack 
	/**
	 * \brief getter for the next attack time of the hero
	 * \return the next attack time of the hero
	*/
	float getNextAttack() const {return nextAttack; } 
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
	 * \param hp the healt points of the hero
	 * \param dmg the damage of the hero
	 * \param atkspeed the attack speed of the hero
	*/
	Hero(const std::string name, int maxhp, const int dmg, const float atkspeed) : name(name), acthp(maxhp), maxhp(maxhp), xp(0), dmg(dmg), atkspeed(atkspeed){} 	
	friend std::ostream& operator << (std::ostream& os, const Hero& hero); /// operator overloading for an easier write to any standard output
	/**
	 * \brief parse hero from json file
	 * \param filename name of the json file
	 * \return the read hero
	*/
	static Hero parseUnit (const std::string& filename);
	/**
	 * \brief the battle logic implementation
	 * \return The winner hero
	 * \param attacked the defender hero
	*/
	Hero fight(Hero& attacked);
	/**
	 * \brief getter for the actual hp of the hero
	 * \return the actual hp of the hero
	*/
	int getActHp() const { return acthp; }
};

#endif 