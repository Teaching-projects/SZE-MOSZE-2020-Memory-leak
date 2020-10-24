#include <gtest/gtest.h>
#include "../jsonParser.h"

TEST(ParseTest, stringParseTest) {
    std::string testJsonText = "{\"name\": \"Kakarott\",\"hp\": 30000,\"dmg\": 9000}";
    std::map<std::string, std::string> input;
    std::map<std::string, std::string> expected{
        {"name", "Kakarott"},
        {"hp", "30000"},
        {"dmg", "9000"}
    };

    input = jsonParser::parseString(testJsonText);

    ASSERT_EQ(expected.size(), input.size());

    std::map<std::string, std::string>::iterator itinput = input.begin();
    std::map<std::string, std::string>::iterator itexpected = expected.begin();

    while (itexpected != expected.end() && itinput != input.end())
    {
        ASSERT_EQ(itexpected->first, itinput->first);
        ASSERT_EQ(itexpected->second, itinput->second);
        itexpected++;
        itinput++;
    }
}

TEST(ParseTest, fileParseTest) {
    std::string filename = "units/kakarott.json";
    std::map<std::string, std::string> input;
    std::map<std::string, std::string> expected{
        {"name", "Kakarott"},
        {"hp", "30000"},
        {"dmg", "9000"}
    };

    input = jsonParser::parseFile(filename);
    
    ASSERT_EQ(expected.size(), input.size());

    std::map<std::string, std::string>::iterator itinput = input.begin();
    std::map<std::string, std::string>::iterator itexpected = expected.begin();

    while (itexpected != expected.end() && itinput != input.end())
    {
        ASSERT_EQ(itexpected->first, itinput->first);
        ASSERT_EQ(itexpected->second, itinput->second);
        itexpected++;
        itinput++;
    }
}

TEST(ParseTest, streamParseTest) {
    std::fstream parsingfile("units/kakarott.json");
    std::map<std::string, std::string> input;
    std::map<std::string, std::string> expected{
        {"name", "Kakarott"},
        {"hp", "30000"},
        {"dmg", "9000"}
    };

    input = jsonParser::parseStream(parsingfile);
    
    ASSERT_EQ(expected.size(), input.size());

    std::map<std::string, std::string>::iterator itinput = input.begin();
    std::map<std::string, std::string>::iterator itexpected = expected.begin();

    while (itexpected != expected.end() && itinput != input.end())
    {
        ASSERT_EQ(itexpected->first, itinput->first);
        ASSERT_EQ(itexpected->second, itinput->second);
        itexpected++;
        itinput++;
    }
}

TEST(JSONFileTest, unmatchedQuo) {
    std::string testJsonText = "{\"name\": \"Kakarott\",\"hp\": 30000,\"dmg\": 9000}";

    int sumqou = 0;
    for (int i = 0; i < testJsonText.size(); i++){
        if (testJsonText[i] == '\"') sumqou++;
    }
    EXPECT_EQ(8, sumqou);
}

TEST(JSONFileTest, commaCount) {
    std::string testJsonText = "{\"name\": \"Kakarott\",\"hp\": 30000,\"dmg\": 9000}";

    int sumcomma = 0;
    for (int i = 0; i < testJsonText.size(); i++){
        if (testJsonText[i] == ',') sumcomma++;
    }
    ASSERT_EQ(2, sumcomma);
}

TEST(JSONFileTest, rowCount) {
    int rowcount = 0;
    std::string filename = "units/kakarott.json";
    std::ifstream jsonIfs(filename);    
    std::string line;

    while (std::getline(jsonIfs, line)) {
		rowcount++;
	}

    EXPECT_EQ(5, rowcount);
}

TEST(JSONFileTest, columnCount) {
    int expectedLength [5] = {1,22,15,14,1};
    int resultLength [5];

    std::string filename = "units/kakarott.json";
    std::ifstream jsonIfs(filename);    
    std::string line;
    int i = 0;

    while (std::getline(jsonIfs, line)) {
		resultLength[i] = line.length();
	}

    for (int j = 0; j < 5; j++)
    {
        EXPECT_EQ(expectedLength[i], resultLength[i]);
    }
}

TEST(JSONFileTest, switchedKeys) {
    std::string testJsonText = "{\"hp\": 30000, \"name\": \"Kakarott\", \"dmg\": 9000}";
    std::map<std::string, std::string> input;
    std::map<std::string, std::string> expected{
        {"name", "Kakarott"},
        {"hp", "30000"},
        {"dmg", "9000"}
    };

    input = jsonParser::parseString(testJsonText);

    ASSERT_EQ(expected.size(), input.size());

    std::map<std::string, std::string>::iterator itinput = input.begin();
    std::map<std::string, std::string>::iterator itexpected = expected.begin();

    while (itexpected != expected.end() && itinput != input.end())
    {
        ASSERT_EQ(itexpected->first, itinput->first);
        itexpected++;
        itinput++;
    }
}

TEST(ParseTest, BadInputTest) {
    std::string filename = "units/badunit.json";
    std::map<std::string, std::string> input;
    std::map<std::string, std::string> expected{
        {"name", "Bad"},
        {"hp", "35000"},
        {"dmg", "8000"}
    };

    input = jsonParser::parseFile(filename);

    ASSERT_EQ(expected.size(), input.size());

    std::map<std::string, std::string>::iterator itinput = input.begin();
    std::map<std::string, std::string>::iterator itexpected = expected.begin();

    while (itexpected != expected.end() && itinput != input.end())
    {
        ASSERT_EQ(itexpected->first, itinput->first);
        ASSERT_EQ(itexpected->second, itinput->second);
        itexpected++;
        itinput++;
    }
}

int main(int argc, char* argv[]){
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}