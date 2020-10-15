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

    input = jsonParser::parse(testJsonText);

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

    input = jsonParser::parse(filename);
    
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

    input = jsonParser::parse(parsingfile);
    
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