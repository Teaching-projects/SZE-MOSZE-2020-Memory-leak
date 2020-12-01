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
    Renderer() {}
    virtual void render(const Game&) const = 0;
};

#endif