#include "Hero.h"

void Hero::incXp(int getxp) {
	/**
	 * The Hero get xp from attack and if it reach 100 xp it keep some extra dmg and hp.
	 * And its actual hp will be its maximum hp.
	*/
	xp += getxp;
	while(xp >= xpforlvlup){ 
		maxhp = (int)round(maxhp + bonus_health_per_level);
		dmg = (int)round(dmg + bonus_damage_per_level);
		atkspeed = (float)atkspeed * atkspeed_multiplier;
		acthp = maxhp;
		lvl++;
		xp -= xpforlvlup;
	}
}

int Hero::takeAttack(Monster& m)
{
	/**
	 * The monster keep attack from hero and decrease its hp.
	 * The attacker keep xp as much as it decrease from enemy.
	*/
	int dmgDealth = Monster::takeAttack(m);
	incXp(dmgDealth);
	return 0;
}

Hero Hero::parse(const std::string& s)
{
	/**
	 * This function read from file, or string input.
	 * This make a jsonMap type map and parse the hero.
	 * After parsing this return a new Hero, with the parsed attributes.
	*/
	JSON heroData = JSON::parseFromFile(s);
	return Hero(heroData.get<std::string>("name"), heroData.get<int>("base_health_points"),
	heroData.get<int>("health_point_bonus_per_level"), heroData.get<int>("experience_per_level"),
	heroData.get<int>("base_damage"), heroData.get<int>("damage_bonus_per_level"),
	heroData.get<float>("cooldown_multiplier_per_level"), heroData.get<float>("base_attack_cooldown"));
}

Hero Hero::parse(std::istream& stream){
	/**
	 * This function read from file, or string input.
	 * This make a jsonMap type map and parse the hero.
	 * After parsing this return a new Hero, with the parsed attributes.
	*/
	JSON heroData = JSON::parseFromStream(stream);
	return Hero(heroData.get<std::string>("name"), heroData.get<int>("base_health_points"), heroData.get<int>("health_point_bonus_per_level"), heroData.get<int>("experience_per_level"), heroData.get<int>("base_damage"), heroData.get<int>("damage_bonus_per_level"), heroData.get<float>("cooldown_multiplier_per_level"), heroData.get<float>("base_attack_cooldown"));
}