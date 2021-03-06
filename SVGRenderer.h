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
    /**
     * \brief construktor for the class, which init the output file
     * \param filename the filename where we will render out
    */
    SVGRenderer(std::string filename) : outfile(filename) {}
    /**
     * \brief Virtual function which will declarate in children classes
     * \param game the game what wi will render out
    */
    virtual void render(const Game&) const = 0;
protected:
    std::string outfile;
};

#endif