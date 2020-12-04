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
    /**
     * Default construktor for the class
    */
    TextRenderer() {}
    /**
     * \brief construktor for the class, which init the output stream
     * \param ofs the output stream where we will render out
    */
    TextRenderer(std::ofstream& ofs) : outWriter(ofs) {}

    void setOutputStream (std::ostream& ofs) { 
        ofs.copyfmt(outWriter); 
    }
    /**
     * \brief Virtual function which will declarate in children classes
     * \param game the game what wi will render out
    */
    virtual void render(const Game&) const = 0;

protected:
    std::ostream& outWriter = std::cout;
};

#endif