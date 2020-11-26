/**
 * \class Map
 * 
 * \brief Map class
 * 
 * \author joostibor, Krisiiii98, Peti96
 * 
 * \version 0.7
 * 
 * Here we make the parse and init the map.
 * 
 * \date 2020/11/23
 * 
*/

#ifndef MAP_H
#define MAP_H

#include <string>
#include <iostream>
#include <fstream>
#include <vector>

class Map {
public:
    /**
    * This enum is giving back if the current area is a wall or free cell.
    */ 
    enum type {
        Wall,
        Free
    };
    /**
     * This is a type definition for storing the map. This is a two dimensional vector what has type typed elements.
    */
    typedef std::vector<std::vector<type>> mapType;
    /**
     *\brief This is a constructor for the map class which does not have any input.
    */
    Map() {}
    /**
     * \brief This is a constructor for the map class which have a filename input.
     * \param filename input what contains the map
    */
    Map(std::string filename);
    /**
     * \brief Here happens the query of a map element.
     * \param x the horizontal coordinate.
     * \param y the vertical coordinate. 
     * \return type of the map element which can be free or wall.
    */
    Map::type get(int x, int y) const;
    /**
     * \brief Getter for the map heigth.
     * \return the heigth of  the map.
    */
    int getMapHeigth() const { return data.size(); }
    /**
     * \brief Getter for the map width.
     * \return the width of  the map.
    */
    int getMapWidth() const {
        int maxlen = 0;
        for (auto element: data){
            if ((int)element.size() > maxlen) maxlen = element.size();
        }
        return maxlen;
    }
    
    /**
     * If the index is wrong it gives back an error message.
    */
    class WrongIndexException : public std::runtime_error{
        public:
            WrongIndexException(const std::string& msg) : std::runtime_error(msg) {}
    };

private:
    static mapType readMap (std::string filename);
    std::vector<std::vector<type>> data;
};

#endif