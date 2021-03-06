#include <iostream>
#include <map>
#include <string>
#include <filesystem>
#include <sstream>
#include <algorithm>
#include <iterator>
#include <list>

#include "JSON.h"
#include "Hero.h"
#include "Monster.h"
#include "Game.h"
#include "Map.h"
#include "MarkedMap.h"
#include "PreparedGame.h"
#include "Renderer.h"
#include "ObserverSVGRenderer.h"
#include "HeroSVGRenderer.h"

const std::map<int,std::string> error_messages = {
    { 1 , "Bad number of arguments. Only a single scenario file should be provided." },
    { 2 , "The provided scenario file is not accessible." },
    { 3 , "The provided scenario file is invalid." },
    { 4 , "JSON parsing error." }
};

void bad_exit(int exitcode){
    std::cerr 
        << (error_messages.count(exitcode) ? error_messages.at(exitcode) : "Unknown error")
        << std::endl;
    exit(exitcode);
}

int main(int argc, char** argv){
    if (argc != 2) bad_exit(1);

    try {
        PreparedGame game(argv[1]);
        game.registerRenderer(new HeroTextRenderer());
        game.registerRenderer(new ObserverTextRenderer(std::ofstream("log.txt")));
        game.registerRenderer(new HeroSVGRenderer("pretty.svg"));
        game.registerRenderer(new ObserverSVGRenderer("pretty2.svg"));
        game.run();
    }
    catch (const JSON::ParseException& e) {bad_exit(4);}

    return 0;
}