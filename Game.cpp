#include "Game.h"

Game::Game(std::string mapfilename): isMapSet(false), isHeroSet(false), isMonsterSet(false), isStarted(false), gameHero() {
    Map gamemap(mapfilename);
    setMap(gamemap);
}

Game::~Game(){
    delete gameHero.name;

    for (auto m: gameMonsters){
        delete m.name;
    }
}


bool Game::isOccupied(int x, int y){
    if (isHeroSet && gameHero.posx == x && gameHero.posy == y) return true;
    else if (isMonsterSet) {
        int cv = 0;
        while(cv < (int)gameMonsters.size() && (gameMonsters[cv].posx != x || gameMonsters[cv].posy != y)) cv++;
        if (cv < (int)gameMonsters.size()) return true;
    }

    return false;
}

void Game::setMap(Map map){
    if (isStarted) throw GameAlreadyStartedExpection("The game is initialized yet!");
    if (isHeroSet || isMonsterSet) throw AlreadyHasUnitsExpection("The map has units, can not change!");

    gameMap = map;
    isMapSet = true;
}

void Game::putHero(Hero hero, int x, int y){
    if (isStarted) throw GameAlreadyStartedExpection("The game is initialized yet!");
    if (!isMapSet) throw Map::WrongIndexException("No map initialized!");
    if (isHeroSet) throw AlreadyHasHeroExpection("The hero is already initialized!");
    if (isOccupied(x,y) || gameMap.get(x,y) == Map::type::Wall) throw OccupiedException("This position is occupied!");

    gameHero.name = new Hero(hero);
    gameHero.posx = x;
    gameHero.posy = y;
    isHeroSet = true;
}

void Game::putMonster(Monster monster, int x, int y){
    if (!isMapSet) throw Map::WrongIndexException("No map initialized!");
    if (isOccupied(x,y) || gameMap.get(x,y) == Map::type::Wall) throw OccupiedException("This position is occupied!");

    gameMonsters.push_back({new Monster(monster), x, y});
    isMonsterSet = true;
}

std::vector<int> Game::getMonsterInThisPos(int x, int y){
    std::vector<int> idx;
    for (int i = 0; i < (int)gameMonsters.size(); i++){
        if (gameMonsters[i].posx == x && gameMonsters[i].posy == y) idx.push_back(i);
    }
    return idx;
}

void Game::draw(){
    int width = gameMap.getMapWidth();
    int heigth = gameMap.getMapHeigth();

    std::cout << "╔";
    for(int i = 0; i < width; i++) std::cout << "══";
    std::cout << "╗";

    for (int i = 0; i < heigth; i++){
        std::cout << "║";
        for (int j = 0; j < width; j++){
            try{
                if (gameMap.get(j, i) == Map::type::Wall) std::cout << "██";
                else if (gameHero.posx == j && gameHero.posy == i) std::cout << "┣┫";
                else{
                    int monstersHere = getMonsterInThisPos(j, i).size();
                    if (monstersHere == 1) std::cout << "M░";
                    else if (monstersHere > 1) std::cout << "MM";
                    else std::cout << "░░";
                }
            }
            catch(Map::WrongIndexException& e) { std::cout << "██"; }
        }
        std::cout << "║\n";
    }
}

void Game::run(){
    if (!isMapSet || !isHeroSet || !isMonsterSet) throw NotInitializedExpection("The map or hero or monster not initialized!");

    isStarted = true;

    draw();
    std::string inputDirection = "";
    bool inputIsWrong = true;

    do{
        std::cin >> inputDirection;
        inputIsWrong = true;
        if (inputDirection == "north" && gameMap.get(gameHero.posx, gameHero.posy - 1) == Map::type::Free){
            gameHero.posy -= 1;
            inputIsWrong = false;
        }
        else if (inputDirection == "south" && gameMap.get(gameHero.posx, gameHero.posy + 1) == Map::type::Free){
            gameHero.posy += 1;
            inputIsWrong = false; 
        }
        else if (inputDirection == "west" && gameMap.get(gameHero.posx - 1, gameHero.posy) == Map::type::Free){
            gameHero.posx -= 1;
            inputIsWrong = false; 
        }
        else if (inputDirection == "east" && gameMap.get(gameHero.posx + 1, gameHero.posy) == Map::type::Free){
            gameHero.posx += 1;
            inputIsWrong = false;
        }

        if(inputIsWrong == false){
            std::vector<int> monstersHere = getMonsterInThisPos(gameHero.posx, gameHero.posy);
            if (monstersHere.size() > 0){
                int cv = 0;
                while(gameHero.name->isAlive() && cv < (int)monstersHere.size()){
                    gameHero.name->fightTilDeath(*gameMonsters[monstersHere[cv]].name);
                    cv++;
                }
                cv--;
                while(cv >= 0){
                    delete gameMonsters[monstersHere[cv]].name;
                    gameMonsters.erase(gameMonsters.begin() + monstersHere[cv]);
                    cv--;
                }
            }
        }

    }while(gameHero.name->isAlive() && gameMonsters.size() > 0);
}