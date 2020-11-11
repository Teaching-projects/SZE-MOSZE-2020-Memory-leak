/**
 * \class JSON
 * 
 * \brief JSON class
 * 
 * \author joostibor, Krisiiii98, Peti96
 * 
 * \version 0.4
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
#include <variant>
#include <list>

/**
 * Make a type for parse a json into this. This is a standard map, which have two parameter, a string and a variant parameter what contain string, int and float.
*/
typedef std::map<std::string, std::variant<std::string, int, float>> jsonMap;

class JSON
{
private:
    /**
     * \brief This function clean the received json key or value. This remove whitespaces and characters what is unnecessary.
     * \param line This is a piece of parsing line. This contain the key or the value.
     * \return The cleaned json key or value.
    */
    static std::string searchandCleanJsonWord(std::string& line);
    jsonMap inputdatas; ///< This cotain the input datas.
public:
    /**
     * \brief Simple construktor for JSON class.
     * \param inputdatas The jsonMap type argument, what contain hero's data.
    */
    JSON(jsonMap _inputdatas) : inputdatas(_inputdatas) {}

    typedef std::list<std::variant<std::string, int, float>> list;
    /**
     * \brief getter for the parser
     * \param key the JSON element's key
     * \return T template, with a JSON data-key pair.
    */
    template <typename T>
    inline typename std::enable_if<!std::is_same<T, JSON::list>::value, T>::type get(const std::string& key)
    {
        if (inputdatas.find(key) == inputdatas.end()) throw "Wrong JSON key!";
        try{
            return std::get<T>(inputdatas[key]);
        }
        catch(const std::exception& e) {
            throw ParseException("Wrong JSON type!");
        }
    }

    template <typename T>
    inline typename std::enable_if<std::is_same<T, JSON::list>::value, JSON::list>::type get(const std::string& key)
    {
        if(!inputdatas.count(key)) throw "Missing JSON key! The key is: " + key;

        JSON::list monsters;

        std::string inputList = std::get<std::string>(inputdatas[key]);
        std::string listValue;

        unsigned int actPos = 0;

        while (actPos < inputList.length())
        {
            int commaPos = inputList.find(',', actPos);
            if (commaPos < 0) commaPos = inputList.length();

            listValue = inputList.substr(actPos, commaPos-actPos);
            monsters.push_back(listValue);

            actPos = commaPos + 1;
        }

        return monsters;
    }
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
     * \author Krisiiii98, Peti96, joostibor
     * 
     * \version 0.9
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