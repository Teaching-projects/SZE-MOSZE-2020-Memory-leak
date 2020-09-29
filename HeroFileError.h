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