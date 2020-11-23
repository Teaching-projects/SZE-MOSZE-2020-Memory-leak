/**
 * \class Monster
 * 
 * \brief Monster class
 * 
 * \author joostibor, Peti96, Krisiiii98
 * 
 * \version 0.1
 * 
 * Here we crate the monsters and set their properties.
 * 
 * \date 2020/10/30
 * 
*/


#ifndef MONSTER_H
#define MONSTER_H

#include <string>
#include <iostream>
#include <fstream>
#include <cmath>

#include "JSON.h"

class Monster
{
protected:
	struct Damage {
		int physical;
		int magical;

		Damage& operator+(const Damage& another){
			Damage tmp;
			tmp.physical = this->physical + another.physical;
			tmp.magical = this->magical + another.magical;
			return tmp;
		}

		Damage& operator+=(const Damage& another){
			this->physical += another.physical;
			this->magical += another.magical;
			return *this;
		}

		Damage& operator*=(const Damage& another){
			this->physical *= another.physical;
			this->magical *+ another.magical;
			return *this;
		}
	};
	const std::string name; ///< The name of the monster
	int acthp; ///< The actual hp of the monster
	int maxhp; ///< The maximum hp of the monster at the start
	Damage dmg; ///< The damage of the monster
	int defense; ///< The defense of the monster
	float atkspeed; ///< How many seconds pass between the attacks of the monster
	float nextAttack=atkspeed; ///< Keeps track of the current attackspeed 
    /**
	 * \brief A monster get damage from the monster
	 * \param m constant reference for the hero who get the attack
	 * \return the dmg, what the Monster taken.
	*/
    virtual int takeAttack(Monster& m);
    /**
	 * \brief getter for the next attack time of the hero
	 * \return the next attack time of the hero
	*/
	float getNextAttack() const { return nextAttack; }
	/**
	 * \brief return the real damage what monster take to the opponent and setup the enemy monster's hp.
	 * \param m the opponent Monster
	 * \return taken damage
	*/
	int takeDamage(Monster& m);

public:
/**
 * Setting the hero properties and the required things to the battle.
*/
	/**
	 * \brief constructor for the monster class
	 * \param name the name of the monster
	 * \param hp the healt points of the monster
	 * \param dmg the damage of the monster
	 * \param defense the defense of the monster
	 * \param atkspeed the attack speed of the monster
	*/
	Monster(const std::string name, int maxhp, int phdmg, int magdmg, int defense, float atkspeed) : name(name), acthp(maxhp), maxhp(maxhp),
	dmg({phdmg, magdmg}), defense(defense), atkspeed(atkspeed){} 
	virtual ~Monster() {} 	///< Virtual destructor for the class
	/**
	 * \brief parse a monster from json file or string input
	 * \param s name of the json file or the content of string parameter
	 * \return the read monster
	*/
	static Monster parse (const std::string& s);
	/**
	 * \brief parse monster from inputstream
	 * \param stream the input stream what contain the monster's attribute
	 * \return the read monster
	*/
	static Monster parse (std::istream& stream);
	/**
	 * \brief This function check monster's hp >= 0.
     * \return True if monster is alive, false if monster actual hp <= 0.
	*/
	bool isAlive ();
    /**
	 * \brief getter for the name of the monster
	 * \return the name of the hero
	*/
	std::string getName() const { return name;}
	/**
	 * \brief the battle logic implementation
	 * \param m the enemy monster
	*/
	void fightTilDeath(Monster& m);
	/**
	 * \brief getter for the next attack time of the monster
	 * \return the next attack time of the hero
	*/
	float getAttackCoolDown() const { return atkspeed; } 
	/**
	 * \brief getter for the actual hp of the monster
	 * \return the actual hp of the monster
	*/
	int getHealthPoints() const { return acthp; }
	/**
	 * \brief getter for the maximum hp of the monster
	 * \return the maximum hp of the monster
	*/
	int getMaxHealthPoints() const { return maxhp; }
	/**
	 * \brief getter for the defense of the monster
	 * \return the defense of the monster
	*/
	int getDefense() const { return defense; }
	/**
	 * \brief getter for the physical damage of the monster
	 * \return the physical damage of the monster
	*/
	int getPhysicalDamage() const { return dmg.physical; }
	/**
	 * \brief getter for the magical damage of the monster
	 * \return the magical damage of the monster
	*/
	int getMagicalDamage() const { return dmg.magical; }
};

#endif 
