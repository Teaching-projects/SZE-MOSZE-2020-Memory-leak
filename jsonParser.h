#ifndef JSONPARSER_H
#define JSONPARSER_H

#include "HeroFileError.h"

#include <string>
#include <map>
#include <fstream>
#include <iostream>

typedef std::map<std::string, std::string> jsonMap;

class jsonParser
{
private:
    static std::string searchandCleanJsonWord(std::string& line);
    static jsonMap parsePair(const std::string& line);
public:
    static jsonMap parse(const std::string& input);
    static jsonMap parse(std::istream& inputStream);
};

#endif