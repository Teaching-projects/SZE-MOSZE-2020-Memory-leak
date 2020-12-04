#include "Hero.h"

void Hero::incXp(const int getxp) {
	/**
	 * The Hero get xp from attack and if it reach xpforlvlup parameter xp it keep some extra dmg, hp and decrease the attack cooldown.
	 * And its actual hp will be its maximum hp.
	 * The xp will decrease with xpforlvlup.
	*/
	xp += getxp;
	while(xp >= xpforlvlup){ 
		maxhp += bonus_health_per_level;
		dmg.physical += bonus_physical_damage_per_level;
		dmg.magical += bonus_magical_damage_per_level;
		atkspeed = (float)atkspeed * atkspeed_multiplier;
		defense += bonus_defense_per_level;
		light_radius += bonus_light_radius;
		acthp = maxhp;
		lvl++;
		xp -= xpforlvlup;
	}
}

int Hero::takeAttack(Monster& m)
{
	/**
	 * The hero call the Monster class takeattack function with the real taken dmg.
	 * The hero keep same xp with the dealth dmg and it's increase it's xp.
	*/
	int dmgDealth = Monster::takeAttack(m);
	incXp(dmgDealth);
	return 0;
}

Hero Hero::parse(const std::string& s)
{
	/**
	 * This function read from file, or string input.
	 * After parsing this return a new Hero, with the parsed attributes.
	*/
	JSON heroData = JSON::parseFromFile(s);
	return Hero(heroData.get<std::string>("name"), heroData.get<int>("base_health_points"),
	heroData.get<int>("health_point_bonus_per_level"), heroData.get<int>("experience_per_level"),
	heroData.get<int>("base_physical_damage"), heroData.get<int>("base_magical_damage"),
	heroData.get<int>("physical_damage_bonus_per_level"), heroData.get<int>("magical_damage_bonus_per_level"),
	heroData.get<float>("cooldown_multiplier_per_level"), heroData.get<float>("base_attack_cooldown"),
	heroData.get<int>("defense"), heroData.get<int>("bonus_defense_per_level"),
	heroData.get<int>("light_radius"), heroData.get<int>("bonus_light_radius"), heroData.get<std::string>("texture"));
}

Hero Hero::parse(std::istream& stream){
	/**
	 * This function read from file, or string input.
	 * After parsing this return a new Hero, with the parsed attributes.
	*/
	JSON heroData = JSON::parseFromStream(stream);
	return Hero(heroData.get<std::string>("name"), heroData.get<int>("base_health_points"),
	heroData.get<int>("health_point_bonus_per_level"), heroData.get<int>("experience_per_level"),
	heroData.get<int>("base_physical_damage"), heroData.get<int>("base_magical_damage"),
	heroData.get<int>("physical_damage_bonus_per_level"), heroData.get<int>("magical_damage_bonus_per_level"),
	heroData.get<float>("cooldown_multiplier_per_level"), heroData.get<float>("base_attack_cooldown"),
	heroData.get<int>("defense"), heroData.get<int>("bonus_defense_per_level"),
	heroData.get<int>("light_radius"), heroData.get<int>("bonus_light_radius"), heroData.get<std::string>("texture"));
}