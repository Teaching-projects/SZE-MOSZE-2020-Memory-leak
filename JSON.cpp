#include "JSON.h"
#include <string>

std::string JSON::searchandCleanJsonWord(std::string& line) {
	/**
	 * In this function we search the first and last index of the necessary value.
	 * After that we cut the input and return the cleaned value.
	*/
	int firstidx = 0;
	int lastidx = line.length() - 1;

	while (firstidx < (int)line.length() && (line[firstidx] == ' ' || line[firstidx] == '\"' ||  line[firstidx] == '{' || line[firstidx] == '\t')) { firstidx++; }
	while (lastidx >= 0 && (line[lastidx] == ' ' || line[lastidx] == '\t' || line[lastidx] == '\"' ||  line[lastidx] == '}')) { lastidx--; }

	line = line.substr(firstidx, lastidx - firstidx + 1);

	return line;
}

jsonMap JSON::parsePair(const std::string& line) {
	/**
	 * We go along the input line and find the key and data value.
	 * If we found it, clean it and save to the map.
	 * At the end, we return the map with the datas.
	*/
	jsonMap dataofHero;
	std::string keyValue = "";
	std::string valueofKey = "";

	int currentPos = 1;

	while (currentPos < (int)line.length())
	{
		int colonPos = line.find(':', currentPos);
		int commaPos = line.find(',', currentPos);

		if (commaPos < 0) { commaPos = line.length() - 1; }
		if (colonPos >= 0)
		{
			keyValue = line.substr(currentPos, colonPos - (currentPos + 1));
			valueofKey = line.substr(colonPos + 1, commaPos - (colonPos + 1));

			keyValue = searchandCleanJsonWord(keyValue);
			if (valueofKey.find('\"') != std::string::npos){
				valueofKey = searchandCleanJsonWord(valueofKey);
				dataofHero[keyValue] = valueofKey;
			}
			else if (valueofKey.find('.') != std::string::npos){
				valueofKey = searchandCleanJsonWord(valueofKey);
				dataofHero[keyValue] = std::stof(valueofKey);
			}
			else{
				valueofKey = searchandCleanJsonWord(valueofKey);
				dataofHero[keyValue] = std::stoi(valueofKey);
			}
		}
		currentPos = commaPos + 1;
	}

	return dataofHero;
}

JSON JSON::parseFromFile(const std::string& filename) {
	/**
	 * We make an ifstream from received filename.
	 * If the file not openable we throw an error message.
	 * If the file is ok, this fuction parse this line by line.
	*/
	std::ifstream jsonIfs(filename);

	if (jsonIfs.fail()) {
		throw ParseException("Can't open the json file.");
	}

	std::string line;
	std::string textFromInput = "";

	while (std::getline(jsonIfs, line)) {
		textFromInput += line;
	}

	jsonIfs.close();
	jsonMap datas = parsePair(textFromInput);
	return JSON(datas);
}

JSON JSON::parseFromString(const std::string& inputtext) {
	jsonMap dataOfHero;

	int currentPos = 1;
	int colonCount = 0;
	int commaCount = 0;
	int dataCount = 0;

	std::string keyvalue = "";
	std::string valueofKey = "";

	while (currentPos < (int)inputtext.length())
	{
		bool posisgood = true;
		int colonPos = inputtext.find(':', currentPos);
		int commaPos = currentPos;

		while (commaPos < (int)inputtext.length() && (!posisgood || inputtext[commaPos] != ',')) {
			if (inputtext[commaPos] == '\"') posisgood = !posisgood;
			++commaPos;
		}

		if (inputtext[commaPos]==',') commaCount++;

		if (commaPos < 0) commaPos = inputtext.length();

		if (colonPos >= 0) {
			colonCount++;

			keyvalue = inputtext.substr(currentPos, colonPos - (currentPos + 1));
			valueofKey = inputtext.substr(colonPos + 1, commaPos - (colonPos + 1));

			bool valueofKeyIsString = valueofKey.find('\"') != std::string::npos;
			keyvalue = searchandCleanJsonWord(keyvalue);
			valueofKey = searchandCleanJsonWord(valueofKey);			
			if (valueofKeyIsString){ dataOfHero[keyvalue] = valueofKey; }
			else if (valueofKey.find('.') != std::string::npos){ dataOfHero[keyvalue] = std::stof(valueofKey); }
			else{ dataOfHero[keyvalue] = std::stoi(valueofKey); }

			dataCount++;
		}

		currentPos = commaPos + 1;
	}

	if(dataCount != colonCount || commaCount != colonCount - 1){
		throw ParseException("Wrong JSON syntax!");
	}
	return JSON(dataOfHero);
}

JSON JSON::parseFromStream(std::istream& inputStream) {
	/**
	 * This fucntion parse the inputstream line by line.
	*/
	std::string line = "";
	std::string textFromInput = "";
	while (std::getline(inputStream, line)) {
		textFromInput += line;
	}

	jsonMap datas = parsePair(textFromInput);
	return JSON(datas);
}