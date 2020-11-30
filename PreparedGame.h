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
    PreparedGame(const std::string filename) { initGame(filename); }
    void run() { Game::run(); }
private:
    void initGame(const std::string);
};

#endif