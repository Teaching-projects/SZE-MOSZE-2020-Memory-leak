#include "HeroSVGRenderer.h"
#include "Game.h"

std::string HeroSVGRenderer::getSVGContent(std::string filename, const Game& game) const{
    std::ifstream svgfile(filename);

    if (svgfile.fail()){
        JSON gameData = JSON::parseFromFile(game.getGameJSON());
        return gameData.get<std::string>("wall_texture");
    }
    
    std::string line;
    std::string text = "";

    while(std::getline(svgfile, line)) text += line;

    svgfile.close();
    return text;    
}

std::string HeroSVGRenderer::setXYInSVG(std::string content, const std::string x, const std::string y) const{
    int xpos = content.find("x=\"");
    int endx = content.find("\"", xpos);
    int xlen = endx - xpos - 1;
    content.replace(xpos + 3, xlen, x);
    int ypos = content.find("y=\"");
    int endy = content.find("\"", ypos);
    int ylen = endy - ypos - 1;
    content.replace(ypos + 3, ylen, y);
    
    return content;
}

std::string HeroSVGRenderer::setXYInSVGMonster(std::string content, const std::string x, const std::string y) const{
    int xpos = content.find("x=\"");
    int endx = content.find("\"", xpos);
    int xlen = endx - xpos - 1;
    content.replace(xpos + 3, xlen, x);
    int ypos = content.find("y=\"");
    int endy = content.find("\"", ypos);
    int ylen = endy - ypos - 1;
    content.replace(ypos + 3, ylen, y);
    
    return content;
}

void HeroSVGRenderer::render(const Game& game) const{
    Game::hero gameHero = game.getHero();
    Map gameMap = game.getMap();
    int radius = gameHero.name->getLightRadius();
    int mapWidth = gameMap.getMapWidth();
    int mapHeight = gameMap.getMapHeigth();
    std::ofstream output (filename);
    JSON gameData = JSON::parseFromFile(game.getGameJSON());
    int x = 0;
    int y = 0;

    output << "<svg ViewBox=\"0 0 " << (radius * 2 + 1) * 10 << " " << (radius * 2 + 1) * 10 << " \">\n";
    output << "\t<style>\n\t\t.monster {font: 10px;}\n\t</style>\n\n\n";

    for (int i = gameHero.posy - radius; i <= gameHero.posy + radius; i++){
        if (i >= 0 && i < mapHeight){
            x = 0;
            for (int j = gameHero.posx - radius; j <= gameHero.posx + radius; j++){
                if (j >= 0 && j < mapWidth){
                    std::string content = "";
                    std::string file;
                    if (gameMap.get(j,i) == Map::type::Wall){
                        content = getSVGContent(gameData.get<std::string>("wall_texture"), game);
                        content = setXYInSVG(content, std::to_string(x), std::to_string(y));
                        output << "\t" << content << "\n";
                    }
                    else if (gameHero.posx == j && gameHero.posy == i){
                        content = getSVGContent(gameHero.name->getTexture(), game);
                        content = setXYInSVGMonster(content, std::to_string(x), std::to_string(10 + y));
                        output << "\t" << content << "\n";
                    }
                    else{
                        int monstersHere = game.getMonsterInThisPos(j, i).size();
                        if (monstersHere == 1){
                            Game::monster m = game.getMonster(j, i);
                            content = getSVGContent(m.name->getTexture(), game);
                            content = setXYInSVGMonster(content, std::to_string(x), std::to_string(10 + y));
                            output << "\t" << content << "\n";
                        }
                        else
                        {
                            content = getSVGContent(gameData.get<std::string>("free_texture"), game);
                            content = setXYInSVG(content, std::to_string(x), std::to_string(y));
                            output << "\t" << content << "\n";
                        }
                        
                    }
                    x += 10;
                }
            }
        }
        y += 10;
    }
    output << "</svg>";
    output.close();
}