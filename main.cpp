#include <iostream>
#include <map>
#include <string>
#include <filesystem>
#include <sstream>
#include <algorithm>
#include <iterator>
#include <list>

#include "JSON.h"
#include "Hero.h"
#include "Monster.h"
#include "Game.h"
#include "Map.h"

struct unitData
{
    std::string name;
    int posx;
    int posy;
};

const std::map<int,std::string> error_messages = {
    { 1 , "Bad number of arguments. Only a single scenario file should be provided." },
    { 2 , "The provided scenario file is not accessible." },
    { 3 , "The provided scenario file is invalid." },
    { 4 , "JSON parsing error." }
};

void bad_exit(int exitcode){
    std::cerr 
        << (error_messages.count(exitcode) ? error_messages.at(exitcode) : "Unknown error")
        << std::endl;
    exit(exitcode);
}

unitData separateUnit(std::string data) {
    std::stringstream hero(data);
    std::string segment;
    std::vector<std::string> segments;

    while(std::getline(hero, segment, ';')){
        segments.push_back(segment);
    }

    return unitData( {segments[0], std::stoi(segments[1]), std::stoi(segments[2])} );
}

int main(int argc, char** argv){
    if (argc != 2) bad_exit(1);
    if (!std::filesystem::exists(argv[1])) bad_exit(2);

    std::string map_name;
    unitData hero_unit;
    std::list<unitData> monsters;
    try {
        JSON scenario = JSON::parseFromFile(argv[1]);
        if (!(scenario.count("hero")&&scenario.count("monsters"))) bad_exit(3);
        else {
            map_name = scenario.get<std::string>("map");
            hero_unit=separateUnit(scenario.get<std::string>("hero"));
            JSON::list monster_list=scenario.get<JSON::list>("monsters");
            for(auto monster: monster_list)
                monsters.push_back(separateUnit(std::get<std::string>(monster)));
        }
    } catch (const JSON::ParseException& e) {bad_exit(4);}

    try { 
        Hero hero{Hero::parse(hero_unit.name)};
        Game game(map_name);
        game.putHero(hero, hero_unit.posx, hero_unit.posy);
        for (const auto& monster : monsters)
            game.putMonster(Monster::parse(monster.name), monster.posx, monster.posy);
        game.run();       
    } catch (const JSON::ParseException& e) {bad_exit(4);}
    return 0;
}