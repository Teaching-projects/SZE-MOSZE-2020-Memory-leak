#include "Map.h"

Map::Map(std::string filename){
    data = readMap(filename);
}

Map::type Map::get(int x, int y) const{
    if (data.size() < 0 || y >= data.size() || x < 0 || y < 0 || x >= data[y].size()) throw WrongIndexException("One of the coordinates out of index!");
    return data[y][x];
}

Map::mapType Map::readMap(std::string filename){
    std::ifstream inputMap(filename);
    if (inputMap.fail()) throw std::runtime_error("Can not open the file!");

    std::vector<std::vector<type>> map;
    std::string line;

    while(std::getline(inputMap, line)){
        std::vector<type> line;
        for (auto ch: line){
            if (ch == '#') line.push_back(type::Wall);
            else if (ch == ' ') line.push_back(type::Free);
        }
        map.push_back(line);
    }

    inputMap.close();
    return map;
}