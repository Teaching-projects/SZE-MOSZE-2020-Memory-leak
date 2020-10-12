#include "jsonParser.h"

void jsonParser::searchandCleanJsonWord(std::string& line){
    std::string cleanText;
    int firstQoMarkpos = line.find('"');

    if (firstQoMarkpos >= 0)
    {
        int lastQoMarkpos = line.find('"', firstQoMarkpos + 1);
        cleanText = line.substr(firstQoMarkpos + 1, lastQoMarkpos - (firstQoMarkpos + 1));
    }
    else
    {
        int findFirstChar = line.find_first_not_of(' ');
        cleanText = line.substr(findFirstChar, line.find_last_not_of(' ' | ',' | '}') - findFirstChar + 1);
    }
    
}

jsonMap jsonParser::parsePair(const std::string& line){
    jsonMap dataofHero;

    int currentPos = 0;

    while(currentPos < line.length())
    {
        int colonPos = line.find(':', currentPos);
        int commaPos = line.find(',', currentPos);

        if (commaPos < 0) { commaPos = line.length(); }
        else if (commaPos >= 0)
        {
            std::string keyValue = line.substr(currentPos, colonPos - (currentPos + 1));
            std::string valueofKey = line.substr(colonPos + 1, commaPos - (colonPos + 1));

            dataofHero[keyValue] = valueofKey;

            searchandCleanJsonWord(keyValue);
            searchandCleanJsonWord(valueofKey);
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
        std::string textFromInput;

        while(std::getline(jsonIfs, line)){
            textFromInput += line;
        }

        jsonIfs.close();
        
        return parsePair(textFromInput);
    }
}
    
jsonMap jsonParser::parse(std::istream& inputStream){
    std::string textFromInput;
    std::getline(inputStream, textFromInput);

    return parsePair(textFromInput);
}