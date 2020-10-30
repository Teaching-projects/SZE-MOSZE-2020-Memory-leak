/**
 * \class JSON
 * 
 * \brief JSON class
 * 
 * \author joostibor
 * 
 * \version 0.04
 * 
 * Here we do the parse from a json input.
 * 
 * \date 2020/10/27
 * 
*/

#ifndef JSON_H
#define JSON_H

#include <string>
#include <map>
#include <fstream>
#include <iostream>
#include <any>

/**
 * Make a type for parse a json into this. This is a standard map, which have two string parameter.
*/
typedef std::map<std::string, std::any> jsonMap;

class JSON
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
    jsonMap inputdatas; ///< This cotain the input datas.
public:
    template <typename T>
    T get(const std::string& key)
    {
        return std::any_cast<T>(inputdatas[key]);
    }
    /**
     * \brief Simple construktor for JSON class.
     * \param inputdatas The jsonMap type argument, what contain hero's data.
    */
    JSON(jsonMap inputdatas) : inputdatas(inputdatas) {}
    /**
     * \brief This function parse json from file input.
     * \param filename The name of the json file.
     * \return A map, which contain the data of a hero.
    */
    static JSON parseFromFile(const std::string& filename);
    /**
     * \brief This function parse json from string input.
     * \param inputtext This string parameter contain the datas.
     * \return A map, which contain the data of a hero.
    */
    static JSON parseFromString(const std::string& inputtext);
    /**
     * \brief This function parse json from inputstream input.
     * \param inputStream The inputstream of a json file.
     * \return A map, which contain the data of a hero.
    */
    static JSON parseFromStream(std::istream& inputStream);
    /**
     * \brief This function return count of the jsonMap.
     * \param key The name of key
     * \return The count of jsonMap.
    */
    bool count(std::string key) { return inputdatas.count(key); }

    /**
     * \class HeroFileError
     * 
     * \brief HeroFileError class
     * 
     * \author Krisiiii98
     * 
     * \version 0.04
     * 
     * If we can not reach the file gives back an error message
     * 
     * \date 2020/10/13
     * 
    */

    class ParseException : public std::string
    {
    private:
        std::string msg;

    public:
        ParseException(std::string msg) : msg(msg) {}
        ~ParseException() {}
    };
};

#endif