/**
 * \class ObserverSVGRenderer
 * 
 * \brief ObserverSVGRenderer class
 * 
 * \author joostibor, Krisiiii98, Peti96
 * 
 * \version 0.7
 * 
 * Here we render the map, what the observer see.
 * 
 * \date 2020/12/04
 * 
*/

#ifndef OBSERVERSVGRENDERER_H
#define OBSERVERSVGRENDERER_H

#include "SVGRenderer.h"

class ObserverSVGRenderer : public SVGRenderer{
public:
    /**
     * \brief construktor for the class
     * \param outfile the filename where we print the SVG file
    */
    ObserverSVGRenderer(std::string outfile) : SVGRenderer(outfile), filename(outfile) {}
    /**
     * \brief this function render the actual state of the game
     * \param game the game what we want to render 
    */
    virtual void render (const Game&) const override;

private:
    std::string getSVGContent(const std::string filename, const Game& game) const;
    std::string setXYInSVG(std::string content, const std::string x, const std::string y) const;
    std::string setXYInSVGMonster(std::string content, const std::string x, const std::string y) const;
    std::string filename;
};

#endif