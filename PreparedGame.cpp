#include "PreparedGame.h"

void PreparedGame::initGame(const std::string filename) {
    JSON gameData = JSON::parseFromFile(filename);

    MarkedMap map(gameData.get<std::string>("map"));
    setMap(map);
    putHero(Hero::parse(gameData.get<std::string>("hero")), map.getHeroPosition().xpos, map.getHeroPosition().ypos);
    std::vector<char> monsterSign = map.getMonsterSign();
    for (auto ms: monsterSign){
        std::vector<MarkedMap::mapElement> monsterPos = map.getMonsterPositions(ms);

        for (auto mp: monsterPos){
            std::string monsterfile = "monster-";
            monsterfile += ms;
            Monster m = Monster::parse(gameData.get<std::string>(monsterfile));
            putMonster(m, mp.xpos, mp.ypos);
        }
    }
}