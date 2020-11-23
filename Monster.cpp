#include "Monster.h"

Monster Monster::parse(const std::string& s)
{
    /**
	 * This function read from file, or string input.
	 * This make a jsonMap type map and parse the monster.
	 * After parsing this return a new Monster, with the parsed attributes.
	*/
	JSON monsterData = JSON::parseFromFile(s);
	return Monster(monsterData.get<std::string>("name"), monsterData.get<int>("health_points"),
	monsterData.get<int>("damage"), monsterData.get<float>("attack_cooldown"));
}

Monster Monster::parse(std::istream& stream)
{
    /**
	 * This function read from an istream input.
	 * This make a jsonMap type map and parse the monster.
	 * After parsing this return a new Monster, with the parsed attributes.
	*/
	JSON monsterData = JSON::parseFromStream(stream);
	return Monster(monsterData.get<std::string>("name"), monsterData.get<int>("health_points"),
	monsterData.get<int>("physical_damage"), monsterData.get<int>("magical_damage"), monsterData.get<float>("attack_cooldown"));
}

bool Monster::isAlive(){
	/**
	 * This function check the monster's health point, and it's greater than 0, return true, if less than 0, return false.
	*/
	if (this->getHealthPoints() > 0) return true;
	else return false;
}

int Monster::takeAttack(Monster& m)
{
	/**
	 * The monster take dmg for the enemy monster.
	 * And the fucntion return the death dmg.
	*/
	int dmgDealt = m.takeDamage(*this);

	return dmgDealt;
}

int Monster::takeDamage(Monster& m)
{
	/**
	 * This function descreare the monster's hp. The acthp - dmg less then 0, the monster's hp gonna be 0.
	 * If the actual hp will be greater than 0, set that actual - taken dmg.
	 * At the end the fucntion return the real taken damage.
	*/
	int takenDmg = 0;
	int realDmg = m.getPhysicalDamage() - defense;

	if (realDmg <= 0) realDmg = m.getMagicalDamage();
	else realDmg += m.getMagicalDamage();

	if (acthp - realDmg < 0)
	{
		takenDmg = acthp;
		acthp = 0;
	}
	else
	{
		acthp -= realDmg;
		takenDmg = realDmg;
	}

	return takenDmg;
}

void Monster::fightTilDeath(Monster& m){
	/**
	 * Here happens the fight. Here set the attack timer and it's start at this time.
	 * Which monster have less attack cooldown, it do damage first. If it's take its attack, its timer increase with the attack cooldown.
	 * If one of them have less than 0 hp, the fight end.
	*/
	this->nextAttack = this->getAttackCoolDown();
	m.nextAttack = m.getAttackCoolDown();

	while (this->isAlive() && m.isAlive())
	{
		if (this->getNextAttack() <= m.getNextAttack()) {
			this->takeAttack(m);
			this->nextAttack += this->getAttackCoolDown();
		}
		else
		{
			m.takeAttack(*this);
			m.nextAttack += m.getAttackCoolDown();
		}

	}
}