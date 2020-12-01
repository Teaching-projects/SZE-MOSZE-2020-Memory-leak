/**
 * \class HeroSVGRenderer
 * 
 * \brief HeroSVGRenderer class
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

#ifndef HEROSVGRENDERER_H
#define HEROSVGRENDERER_H

#include "SVGRenderer.h"

class HeroSVGRenderer : public SVGRenderer{
public:
    HeroSVGRenderer() : SVGRenderer(outfile) {}
    HeroSVGRenderer(std::string filename) : SVGRenderer(filename) {}
    virtual void render (const Game&) const override;
};

#endif