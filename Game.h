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

#ifndef GAME_H
#define GAME_H

#include "Map.h"
#include "Hero.h"
#include "Monster.h"
#include <string>

class Game{
public:
    /**
     * Struct for store the datas of the monster.
    */
    struct hero{
        Hero* name;
        int posx;
        int posy;
    };
    /**
     * Struct for store the datas of the monster.
    */
    struct monster{
        Monster* name;
        int posx;
        int posy;
    };
    /**
     * \brief Constructor for the game class without input.
    */
    Game() : isMapSet(false), isHeroSet(false), isMonsterSet(false), isStarted(false), gameHero(){}
    /**
     * \brief Constructor for the game class with input.
     * \param mapfilename name of the file which contains map data.
    */
    Game(std::string mapfilename);
    /**
     * \brief Destructor for the game class.
    */
    ~Game();
    
    /**
     * \brief This function make the map ready to game
     * \param map the map what we want to use for the game
    */
    void setMap(Map map);
    /**
     * \brief This function put a hero to the map
     * \param hero The hero 
     * \param x the horizontal position of the hero
     * \param y the vertical position of the hero
    */
    void putHero(Hero hero, int x, int y);
    /**
     * \brief This function put a monster to the map
     * \param monster The monster 
     * \param x the horizontal position of the monster
     * \param y the vertical position of the monster
     * \param light_radius the light radius of the monster
    */
    void putMonster(Monster monster, int x, int y);
    /**
     * \brief THis function is for the game loop
    */
    void run();
    /**
     * In this section happens all the known errors
    */
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
    bool isMapSet;
    bool isHeroSet;
    bool isMonsterSet;
    bool isStarted;

    Map gameMap;
    hero gameHero;
    std::vector<monster> gameMonsters;
    std::vector<int> monsterInPos;

    std::vector<int> getMonsterInThisPos(int x, int y);
    void draw();
};

#endif