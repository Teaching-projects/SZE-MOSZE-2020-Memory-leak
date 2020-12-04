/**
 * \class PreparedGame
 * 
 * \brief PreparedGame class
 * 
 * \author joostibor, Krisiiii98, Peti96
 * 
 * \version 0.7
 * 
 * Here we do the prepared game main loop.
 * 
 * \date 2020/11/30
 * 
*/

#ifndef PREPAREDGAME_H
#define PREPAREDGAME_H

#include "Game.h"
#include "JSON.h"
#include "MarkedMap.h"

#include <string>

class PreparedGame : public Game{
public:
    /**
     * \brief construktor for PreparedGame class
     * \param filename the JSON, where we want to init the game
    */
    PreparedGame(const std::string filename) :gameJSON(filename) { initGame(filename); }
    /**
     * \brief this function start the main loop
    */
    void run() { Game::run(); }
    /**
     * \brief simply getter for the game's JSON filename
     * \return the game's JSON filename
    */
    virtual std::string getGameJSON() const override { return gameJSON; }
private:
    void initGame(const std::string);
    std::string gameJSON;
};

#endif