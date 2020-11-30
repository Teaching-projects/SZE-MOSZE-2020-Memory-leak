#include "Map.h"

Map::Map(std::string filename){
    data = readMap(filename);
}

Map::type Map::get(int x, int y) const{
    if ((int)data.size() < 0 || y >= (int)data.size() || x < 0 || y < 0 || x >= (int)data[y].size()) WrongIndexException("One of the coordinates out of index!");
    return data[y][x];
}

Map::mapType Map::readMap(const std::string filename){
    std::ifstream inputMap(filename);
    if (inputMap.fail()) throw std::runtime_error("Can not open the file!");

    mapType map;
    std::string line;

    while(std::getline(inputMap, line)){
        std::vector<type> lineofMap;
        for (auto ch: line){
            if (ch == '#') lineofMap.push_back(type::Wall);
            else if (ch == ' ') lineofMap.push_back(type::Free);
        }
        
        map.push_back(lineofMap);
    }
    inputMap.close();
    return map;
}