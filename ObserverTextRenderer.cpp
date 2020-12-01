#include "ObserverTextRenderer.h"
#include "Game.h"

void ObserverTextRenderer::render (const Game& game) const{
    Game::hero gameHero = game.getHero();
    Map gameMap = game.getMap();
    int mapWidth = gameMap.getMapWidth();
    int mapHeight = gameMap.getMapHeigth();

    outWriter << "╔";
    for(int i = 0; i < mapWidth; i++){
        outWriter << "══";
    }
    outWriter << "╗" << std::endl;

    for (int i = 0; i < mapHeight; i++){
        outWriter << "║";    
        for (int j = 0; j < mapWidth; j++){ 
            if (gameMap.get(j, i) == Map::type::Wall) outWriter << "██";
            else if (gameHero.posx == j && gameHero.posy == i) outWriter << "┣┫";
            else{
                int monstersHere = game.getMonsterInThisPos(j, i).size();
                if (monstersHere == 1) outWriter << "M░";
                else if (monstersHere > 1) outWriter << "MM";
                else outWriter << "░░";
            
            }
        }
        outWriter << "║\n";
    }

    outWriter << "╚";
    for(int i = 0; i < mapWidth; i++){
        outWriter << "══";
    }
    outWriter << "╝" << std::endl;
}