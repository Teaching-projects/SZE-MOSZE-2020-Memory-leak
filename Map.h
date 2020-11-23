/**
 * \class Map
 * 
 * \brief Map class
 * 
 * \author joostibor, Krisiiii98, Peti96
 * 
 * \version 0.7
 * 
 * Here we do the parse and init the map.
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
    enum type {
        Wall,
        Free
    };

    typedef std::vector<std::vector<type>> mapType;

    Map() {}
    Map(std::string filename);
    
    Map::type get(int x, int y) const;
    int getMapHeigth() const { return data.size(); }
    int getMapWidth() const {
        int maxlen = 0;
        for (auto element: data){
            if ((int)element.size() > maxlen) maxlen = element.size();
        }
        return maxlen;
    }

    class WrongIndexException : public std::runtime_error{
        public:
            WrongIndexException(const std::string& msg) : std::runtime_error(msg) {}
    };

private:
    std::vector<std::vector<type>> data;
    static mapType readMap (std::string filename);
};

#endif