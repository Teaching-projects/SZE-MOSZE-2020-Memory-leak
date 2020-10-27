/**
 * \class jsonParser
 * 
 * \brief jsonParser class
 * 
 * Here we do the parse from a json input.
 * 
 * \date 2020/10/27
 * 
*/

#ifndef JSONPARSER_H
#define JSONPARSER_H

#include "HeroFileError.h"

#include <string>
#include <map>
#include <fstream>
#include <iostream>

/**
 * Make a type for parse a json into this. This is a standard map, which have two string parameter.
*/
typedef std::map<std::string, std::string> jsonMap;

class jsonParser
{
private:
    /**
     * \brief This function clean the received json key or value. This remove whitespaces and characters what is unnecessary.
     * \param line This is a piece of parsing line. This contain the key or the value.
     * \return The cleaned json key or value.
    */
    static std::string searchandCleanJsonWord(std::string& line);
    /**
     * \brief This funciton do key and value pairs from the json input.
     * \param line This is a line from json input.
     * \return A jsonMap type map, which contain the data of the hero.
    */
    static jsonMap parsePair(const std::string& line);
public:
    /**
     * \brief This function parse json from file input.
     * \param filename The name of the json file.
     * \return A map, which contain the data of a hero.
    */
    static jsonMap parseFile(const std::string& filename);
    /**
     * \brief This function parse json from string input.
     * \param inputtext This string parameter contain the datas.
     * \return A map, which contain the data of a hero.
    */
    static jsonMap parseString(const std::string& inputtext);
    /**
     * \brief This function parse json from inputstream input.
     * \param inputStream The inputstream of a json file.
     * \return A map, which contain the data of a hero.
    */
    static jsonMap parseStream(std::istream& inputStream);
};

#endif