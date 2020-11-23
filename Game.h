/**
 * \class Game
 * 
 * \brief Game class
 * 
 * \author joostibor, Krisiiii98, Peti96
 * 
 * \version 0.7
 * 
 * Here we do the game main loop.
 * 
 * \date 2020/11/23
 * 
*/

#include "Map.h"
#include "Hero.h"
#include "Monster.h"
#include <string>

class Game{
public:
    struct monster{
        Monster* name;
        int posx;
        int posy;
    };

    Game();
    Game(std::string mapfilename);
    ~Game();
    
    void setMap(Map map);
    void putHero(Hero hero, int x, int y);
    void putMonster(Monster monster, int x, int y);
    void run();

    class OccupiedException : public std::runtime_error{
        public:
            OccupiedException(const std::string& msg) : std::runtime_error(msg) {}
    };

    class AlreadyHasHeroExpection : public std::runtime_error{
        public:
            AlreadyHasHeroExpection(const std::string& msg) : std::runtime_error(msg) {}
    };

    class AlreadyHasUnitsExpection : public std::runtime_error{
        public:
            AlreadyHasUnitsExpection(const std::string& msg) : std::runtime_error(msg) {}
    };

    class GameAlreadyStartedExpection : public std::runtime_error{
        public:
            GameAlreadyStartedExpection(const std::string& msg) : std::runtime_error(msg) {}
    };

    class NotInitializedExpection : public std::runtime_error{
        public:
            NotInitializedExpection(const std::string& msg) : std::runtime_error(msg) {}
    };

private:
    Map gameMap;
    monster gameHero;
    std::vector<monster> gameMonsters;
    std::vector<int> monsterInPos;

    bool isMapSet;
    bool isHeroSet;
    bool isMonsterSet;
    bool isStarted;

    bool isOccupied(int x, int y);
    std::vector<int> getMonsterInThisPos(int x, int y);
    void draw();
};