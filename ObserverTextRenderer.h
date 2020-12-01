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
    ObserverTextRenderer() {}
    ObserverTextRenderer(std::ofstream ofs) : TextRenderer(ofs) {}
    virtual void render (const Game&) const override;
};

#endif