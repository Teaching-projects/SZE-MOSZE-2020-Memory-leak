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

    for(auto segment: input){
        //ASSERT_EQ(expected[0], segment.first);
        ASSERT_EQ(expected.at(segment.first), segment.second);
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

    for(auto segment: input){
        //ASSERT_EQ(expected[0], segment.first);
        ASSERT_EQ(expected.at(segment.first), segment.second);
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

    for(auto& segment: input){
        ASSERT_EQ(expected[0], segment.first);
        ASSERT_EQ(expected.at(segment.first), segment.second);
    }
}

int main(int argc, char* argv[]){
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}