#include "JSON.h"
#include <string>

std::string JSON::searchandCleanJsonWord(std::string& line) {
	/**
	 * In this function we search for the first and last index of the necessary value.
	 * After that we cut the input and return the cleaned value.
	*/
	int firstidx = 0;
	int lastidx = line.length() - 1;

	while (firstidx < (int)line.length() && (line[firstidx] == ' ' || line[firstidx] == '\"' ||  line[firstidx] == '{' || line[firstidx] == '\t' || line[firstidx] == '[' || line[firstidx] == ']')) { firstidx++; }
	while (lastidx >= 0 && (line[lastidx] == ' ' || line[lastidx] == '\t' || line[lastidx] == '\"' ||  line[lastidx] == '}' || line[lastidx] == '[' || line[lastidx] == ']')) { lastidx--; }

	line = line.substr(firstidx, lastidx - firstidx + 1);

	return line;
}

JSON JSON::parseFromString(const std::string& inputtext) {
	jsonMap dataOfHero;

	unsigned int currentPos = 1;
	unsigned int colonCount = 0;
	unsigned int commaCount = 0;
	unsigned int dataCount = 0;

	std::string keyvalue = "";
	std::string valueofKey = "";
	std::string monsterList = "";

	while (currentPos < (unsigned int)inputtext.length())
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
			
			keyvalue = inputtext.substr(currentPos + 1, colonPos - currentPos - 1);
			valueofKey = inputtext.substr(colonPos + 1, commaPos - (colonPos + 1));

			int monsterListStart = valueofKey.find('[');
			if (monsterListStart >= 0)
			{
				int monsterListEnd = inputtext.find(']', monsterListStart + 1);

				if (monsterListEnd < 0) throw "Wrong syntax!";

				valueofKey = inputtext.substr(colonPos + monsterListStart + 2, inputtext.find(']', monsterListStart + 1) - (colonPos + monsterListStart + 2));
				keyvalue = searchandCleanJsonWord(keyvalue);
				
				std::string monsterFileList = "";
				unsigned int filenameStartPos = 0;
				while (filenameStartPos < valueofKey.length())
				{
					int nextCommaInList = valueofKey.find(',', filenameStartPos);
					if (nextCommaInList < 0) nextCommaInList = valueofKey.length() - 1;
					std::string filename = valueofKey.substr(filenameStartPos + 1, nextCommaInList - (filenameStartPos + 1));
					filename = searchandCleanJsonWord(filename);
					monsterFileList += filename + ",";
					filenameStartPos = nextCommaInList + 1;
				}

				monsterFileList.erase(monsterFileList.end() - 1);
				dataOfHero[keyvalue] = monsterFileList;
				dataCount++;
				commaPos = monsterListEnd;

				if (monsterFileList.find(',' != std::string::npos)) commaCount--;
			}
			else
			{
				bool valueofKeyIsString = valueofKey.find('\"') != std::string::npos;
				keyvalue = searchandCleanJsonWord(keyvalue);
				valueofKey = searchandCleanJsonWord(valueofKey);
				if (valueofKeyIsString){ dataOfHero[keyvalue] = valueofKey; }
				else if (valueofKey.find('.') != std::string::npos){ dataOfHero[keyvalue] = std::stof(valueofKey); }
				else{ dataOfHero[keyvalue] = std::stoi(valueofKey); }

				dataCount++;
			}
		}	

		currentPos = commaPos + 1;
	}
	return JSON(dataOfHero);
}


JSON JSON::parseFromFile(const std::string& filename) {
	/**
	 * We make an ifstream from the received filename.
	 * If the file is not openable we throw an error message.
	 * If the file is ok, this fuction parses this line by line.
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
	return parseFromString(textFromInput);
}

JSON JSON::parseFromStream(std::istream& inputStream) {
	/**
	 * This function parses the inputstream line by line.
	*/
	std::string line = "";
	std::string textFromInput = "";
	while (std::getline(inputStream, line)) {
		textFromInput += line;
	}

	return parseFromString(textFromInput);
}