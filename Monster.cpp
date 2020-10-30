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
	monsterData.get<int>("damage"), monsterData.get<float>("attack_cooldown"));
}

bool Monster::isAlive(){
	if (this->getHealthPoints() > 0) return true;
	else return false;
}

int Monster::takeAttack(Monster& m)
{
	int dmgDealt = m.takeDamage(*this);

	return dmgDealt;
}

int Monster::takeDamage(Monster& m)
{
	int takenDmg = 0;

	if (acthp - m.getDamage() < 0)
	{
		takenDmg = acthp;
		acthp = 0;
	}
	else
	{
		acthp -= m.getDamage();
		takenDmg = m.getDamage();
	}

	return takenDmg;
}

void Monster::fightTilDeath(Monster& m){
	/**
	 * Here happens the fight. First the attacker attacks then the monster after that if both of them survives the first attack the timers start. 
	 * The fighter who needs less seconds to attack attacks first then we "reset" his timer. 
	 * After the reset we repeat it until one of them has 0 or less than 0 attack
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