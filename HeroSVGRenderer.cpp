#include "HeroTextRenderer.h"
#include "Game.h"

void HeroTextRenderer::render (const Game& game) const{
    Game::hero gameHero = game.getHero();
    Map gameMap = game.getMap();
    int radius = gameHero.name->getLightRadius();
    int mapWidth = gameMap.getMapWidth();
    int mapHeight = gameMap.getMapHeigth();
    int svgx = 0;
    int svgy = 10;
    std::ofstream result("result.svg");

    for (int i = gameHero.posy - radius; i <= gameHero.posy + radius; i++){
        if (i >= 0 && i < mapHeight){   
            for (int j = gameHero.posx - radius; j <= gameHero.posx + radius; j++){ 
                if (j >= 0 && j < mapWidth){
                    if (gameMap.get(j, i) == Map::type::Wall) outWriter << "██";
                    else if (gameHero.posx == j && gameHero.posy == i) outWriter << "┣┫";
                    else{
                        int monstersHere = game.getMonsterInThisPos(j, i).size();
                        if (monstersHere == 1) outWriter << "M░";
                        else if (monstersHere > 1) outWriter << "MM";
                        else outWriter << "░░";
                    
                    }
                }
            }
        }
    }
}