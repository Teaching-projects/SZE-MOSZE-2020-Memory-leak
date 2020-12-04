/**
 * \class Renderer
 * 
 * \brief Renderer class
 * 
 * \author joostibor, Krisiiii98, Peti96
 * 
 * \version 0.7
 * 
 * Here we init the renderer.
 * 
 * \date 2020/12/01
 * 
*/

#ifndef RENDERER_H
#define RENDERER_H

#include <iostream>

class Game;

class Renderer{
public:
    /**
     * Default construktor for the class
    */
    Renderer() {}
    /**
     * \brief Virtual function which will declarate in children classes
     * \param game the game what wi will render out
    */
    virtual void render(const Game& game) const = 0;
};

#endif