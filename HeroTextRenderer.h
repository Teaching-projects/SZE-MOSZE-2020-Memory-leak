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
    HeroTextRenderer() {}
    virtual void render (const Game&) const override;
};

#endif