/**
 * \class SVGRenderer
 * 
 * \brief SVGRenderer class
 * 
 * \author joostibor, Krisiiii98, Peti96
 * 
 * \version 0.7
 * 
 * Here we init the svg renderer.
 * 
 * \date 2020/12/01
 * 
*/

#ifndef SVGRENDERER_H
#define SVGRENDERER_H

#include "Renderer.h"

class SVGRenderer : public Renderer{
public:
    std::string outfile;
    SVGRenderer(std::string filename) : outfile(filename) {}
    virtual void render(const Game&) const = 0;
};

#endif