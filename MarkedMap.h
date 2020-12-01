/**
 * \class MarkedMap
 * 
 * \brief MarkedMap class
 * 
 * \author joostibor, Krisiiii98, Peti96
 * 
 * \version 0.7
 * 
 * Here we make the parse and init the map.
 * 
 * \date 2020/11/30
 * 
*/

#ifndef MARKEDMAP_H
#define MARKEDMAP_H

#include "Map.h"

#include <iostream>
#include <string>
#include <vector>

class MarkedMap : public Map{
public:
    struct mapElement
    {
        char type;
        int xpos;
        int ypos;
    };
    /**
     * \brief This is a constructor for the map class which have a filename input.
     * \param filename input what contains the map
    */
    MarkedMap(std::string filename);
    /**
     * \brief Here happens the query of a map element.
     * \param x the horizontal coordinate.
     * \param y the vertical coordinate. 
     * \return type of the map element which can be free or wall.
    */
    MarkedMap::type get(int x, int y) const;
    /**
     * \brief This fucntion return the position of the hero.
     * \return the mapElement, which contain the hero's data include position.
    */
    mapElement getHeroPosition() const { return hero; }
    /**
     * \brief This function return this type of monster's position(s) in the map.
     * \param c the monster's sign in the map
     * \return the vector, which contain the occurrence position of monster.
    */
    std::vector<mapElement> getMonsterPositions (char c) const;
    /**
     * \brief simply getter for monstersign
     * \return the vector, which contain the monster signs
    */
    std::vector<char> getMonsterSign() const { return monsterSign; }

private:
    mapElement hero;
    std::vector<mapElement> monsters;
    std::vector<char> monsterSign;
};

#endif