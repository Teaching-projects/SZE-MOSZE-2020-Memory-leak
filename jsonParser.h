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
    static jsonMap parseString(const std::string input);
    static jsonMap parseIstream(std::istream& inputStream);
public:
    static void searchJsonWord(std::string& line);
};

#endif