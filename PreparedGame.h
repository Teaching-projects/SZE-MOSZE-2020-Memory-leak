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
    PreparedGame(const std::string filename) :gameJSON(filename) { initGame(filename); }
    void run() { Game::run(); }
    virtual std::string getGameJSON() const override { return gameJSON; }
private:
    void initGame(const std::string);
    std::string gameJSON;
};

#endif