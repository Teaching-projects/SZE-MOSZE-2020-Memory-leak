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