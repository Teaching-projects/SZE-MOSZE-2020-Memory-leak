#include "MarkedMap.h"

MarkedMap::MarkedMap (const std::string filename){
    std::ifstream inputMap(filename);
    if (inputMap.fail()) throw std::runtime_error("Can't open the file!");

    mapType map;
    std::string line;
    int y = 0;

    while(std::getline(inputMap, line)){
        std::vector<type> lineofMap;
        int x = 0;
        for(auto ch: line){
            if (ch == '#') lineofMap.push_back(type::Wall);
            else if (ch == ' ') lineofMap.push_back(type::Free);
            else if (ch == 'H'){
                hero.type = 'H';
                hero.xpos = x;
                hero.ypos = y;
                lineofMap.push_back(type::Free);
            }
            else{
                monsters.push_back({ch,x,y});
                int i = 0;
                while (i < (int)monsterSign.size() && monsterSign[i] != ch) i++;
                if (i >= (int)monsterSign.size()) monsterSign.push_back(ch);
                lineofMap.push_back(type::Free);
            }
            x++;
        }
        map.push_back(lineofMap);
        y++;
    }

    inputMap.close();
    data = map;
}

std::vector<MarkedMap::mapElement> MarkedMap::getMonsterPositions (char c) const{
    std::vector<mapElement> monstersWithThisSign;
    for (auto m: monsters){
        if (m.type == c) monstersWithThisSign.push_back(m);
    }
    return monstersWithThisSign;
}