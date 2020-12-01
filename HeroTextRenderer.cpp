#include "HeroTextRenderer.h"
#include "Game.h"

void HeroTextRenderer::render (const Game& game) const{
    Game::hero gameHero = game.getHero();
    Map gameMap = game.getMap();
    int radius = gameHero.name->getLightRadius();
    int mapWidth = gameMap.getMapWidth();
    int mapHeight = gameMap.getMapHeigth();

    std::cout << "╔";
    for(int i = gameHero.posx - radius; i <= gameHero.posx + radius; i++){
        if(i >= 0 && i < mapWidth) std::cout << "══";
    }
    std::cout << "╗" << std::endl;

    for (int i = gameHero.posy - radius; i <= gameHero.posy + radius; i++){
        if (i >= 0 && i < mapHeight){
            std::cout << "║";    
            for (int j = gameHero.posx - radius; j <= gameHero.posx + radius; j++){ 
                if (j >= 0 && j < mapWidth){
                    if (gameMap.get(j, i) == Map::type::Wall) std::cout << "██";
                    else if (gameHero.posx == j && gameHero.posy == i) std::cout << "┣┫";
                    else{
                        int monstersHere = game.getMonsterInThisPos(j, i).size();
                        if (monstersHere == 1) std::cout << "M░";
                        else if (monstersHere > 1) std::cout << "MM";
                        else std::cout << "░░";
                    
                    }
                }
            }
            std::cout << "║\n";
        }
    }

    std::cout << "╚";
    for(int i = gameHero.posx - radius; i <= gameHero.posx + radius; i++){
        if(i >= 0 && i < mapWidth) std::cout << "══";
    }
    std::cout << "╝" << std::endl;
}