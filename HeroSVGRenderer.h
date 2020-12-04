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
    HeroSVGRenderer(std::string outfile) : SVGRenderer(outfile), filename(outfile) {}
    virtual void render (const Game&) const override;

private:
    std::string getSVGContent(const std::string filename, const Game& game) const;
    std::string setXYInSVG(std::string content, const std::string x, const std::string y) const;
    std::string setXYInSVGMonster(std::string content, const std::string x, const std::string y) const;
    std::string filename;
};

#endif