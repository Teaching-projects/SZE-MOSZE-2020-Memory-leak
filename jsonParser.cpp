#include "jsonParser.h"

std::string jsonParser::searchandCleanJsonWord(std::string& line){
    int firstQoMarkpos = line.find('"');

    if (firstQoMarkpos >= 0)
    {
        int lastQoMarkpos = line.find('"', firstQoMarkpos + 1);
        return line.substr(firstQoMarkpos + 1, lastQoMarkpos - (firstQoMarkpos + 1));

    }
    else
    {
        int findFirstChar = line.find_first_not_of(' ');
        return line.substr(findFirstChar, line.find_last_not_of(' ' | ',' | '}') - findFirstChar + 1);
    }
    
}

jsonMap jsonParser::parsePair(const std::string& line){
    jsonMap dataofHero;

    int currentPos = 1;

    while(currentPos < line.length())
    {
        int colonPos = line.find(':', currentPos);
        int commaPos = line.find(',', currentPos);

        if (commaPos < 0) { commaPos = line.length() - 1; }
        if (colonPos >= 0)
        {
            std::string keyValue = line.substr(currentPos, colonPos - (currentPos + 1));
            std::string valueofKey = line.substr(colonPos + 1, commaPos - (colonPos + 1));

            keyValue = searchandCleanJsonWord(keyValue);
            valueofKey = searchandCleanJsonWord(valueofKey);

            dataofHero[keyValue] = valueofKey;
        }
        currentPos = commaPos + 1;        
    }

    return dataofHero;
}

jsonMap jsonParser::parse(const std::string& input){
    std::ifstream jsonIfs(input);

    if (jsonIfs.fail()){
        if (input.find('{') < 0) { throw HeroFileError("Can't open the json file."); }
        jsonIfs.close();
        return parsePair(input);
    }
    else
    {
        std::string line;
        std::string textFromInput = "";

        while(std::getline(jsonIfs, line)){
            textFromInput += line;
        }

        jsonIfs.close();
        
        return parsePair(textFromInput);
    }
}
    
jsonMap jsonParser::parse(std::istream& inputStream){
    std::string line = "";
    std::string textFromInput = "";
    while (std::getline(inputStream, line)){
        textFromInput += line;
    }

    return parsePair(textFromInput);
}