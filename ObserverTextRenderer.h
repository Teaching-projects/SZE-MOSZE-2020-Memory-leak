/**
 * \class ObserverTextRenderer
 * 
 * \brief ObserverTextRenderer class
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

#ifndef OBSERVERTEXTRENDERER_H
#define OBSERVERTEXTRENDERER_H

#include "TextRenderer.h"

class ObserverTextRenderer : public TextRenderer{
public:
    /**
     * Default construktor for the class
    */
    ObserverTextRenderer() {}
    /**
     * \brief construkor for the class
     * \param ofs the outputstream what we want to initialize
    */
    ObserverTextRenderer(std::ofstream ofs) : TextRenderer(ofs) {}
    /**
     * \brief this function render the actual state of the game
     * \param game the game what we want to render 
    */
    virtual void render (const Game& game) const override;
};

#endif