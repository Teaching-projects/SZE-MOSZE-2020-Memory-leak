/**
 * \class HeroFileError
 * 
 * \brief HeroFileError class
 * 
 * If we can not reach the file gives back an error message
 * 
 * \date 2020/10/13
 * 
*/

#pragma once

#include <iostream>

class HeroFileError : public std::string
{
private:
	std::string msg;

public:
	HeroFileError(std::string msg) : msg(msg) {}
	~HeroFileError() {}
};