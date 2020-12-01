/**
 * \class TextRenderer
 * 
 * \brief TextRenderer class
 * 
 * \author joostibor, Krisiiii98, Peti96
 * 
 * \version 0.7
 * 
 * Here we init the text renderer.
 * 
 * \date 2020/12/01
 * 
*/

#ifndef TEXTRENDERER_H
#define TEXTRENDERER_H

#include "Renderer.h"
#include <fstream>

class TextRenderer : public Renderer{
public:
    TextRenderer() {}
    std::ostream& outWriter = std::cout;
    TextRenderer(std::ofstream& ofs) : outWriter(ofs) {}

    void setOutputStream (std::ostream& ofs) { ofs.copyfmt(outWriter); }
    virtual void render(const Game&) const = 0;
};

#endif