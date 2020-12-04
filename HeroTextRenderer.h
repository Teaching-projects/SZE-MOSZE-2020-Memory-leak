/**
 * \class HeroTextRenderer
 * 
 * \brief HeroTextRenderer class
 * 
 * \author joostibor, Krisiiii98, Peti96
 * 
 * \version 0.7
 * 
 * Here we render the map, what the hero see.
 * 
 * \date 2020/12/01
 * 
*/

#ifndef HEROTEXTRENDERER_H
#define HEROTEXTRENDERER_H

#include "TextRenderer.h"

class HeroTextRenderer : public TextRenderer{
public:
    /**
     * Default construktor for the class
    */
    HeroTextRenderer() {}
    /**
     * \brief construkor for the class
     * \param ofs the outputstream what we want to initialize
    */
    HeroTextRenderer(std::ofstream ofs) : TextRenderer(ofs) {}
    /**
     * \brief this function render the actual state of the game
     * \param game the game what we want to render 
    */
    virtual void render (const Game&) const override;
};

#endif