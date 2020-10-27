#include <gtest/gtest.h>
#include "../jsonParser.h"
#include "../Hero.h"

TEST(ParseTest, stringParseTest) {
    std::string testJsonText = "{\"name\": \"Kakarott\",\"hp\": 30000,\"dmg\": 9000, \"attackCooldown\": 4.2}";
    std::map<std::string, std::string> input;
    std::map<std::string, std::string> expected{
        {"name", "Kakarott"},
        {"hp", "30000"},
        {"dmg", "9000"},
        {"attackCooldown", "4.2"}
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
        {"hp", "300"},
        {"dmg", "90"},
        {"attackCooldown", "4.2"}
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
        {"hp", "300"},
        {"dmg", "90"},
        {"attackCooldown", "4.2"}
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

TEST(ParseTest, BadInputTest) {
    std::string filename = "units/badunit.json";
    std::map<std::string, std::string> input;
    std::map<std::string, std::string> expected{
        {"name", "Bad"},
        {"hp", "35000"},
        {"dmg", "8000"}, 
        {"attackCooldown", "4.2"}
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

TEST(ParseTest, unmatchedQuo) {
    std::string testJsonText = "{\"name\": \"Kakarott,\"hp\": 30000,\"dmg\": 9000}";

    try{
        jsonParser::parseString(testJsonText);
    } catch(std::runtime_error& e){
        ASSERT_STREQ(e.what(), "Wrong JSON syntax!");
    }
}

TEST(ParseTest, missingComma) {
    std::string testJsonText = "{\"name\": \"Kakarott\"\"hp\": 30000,\"dmg\": 9000}";

    try{
        jsonParser::parseString(testJsonText);
    } catch(std::runtime_error& e){
        ASSERT_STREQ(e.what(), "Wrong JSON syntax!");
    }
}

TEST(ParseTest, missingColon) {
    std::string testJsonText = "{\"name\": \"Kakarott\",\"hp\" 30000,\"dmg\": 9000}";

    try{
        jsonParser::parseString(testJsonText);
    } catch(std::runtime_error& e){
        ASSERT_STREQ(e.what(), "Wrong JSON syntax!");
    }
}

TEST(ParseTest, TooMuchWhiteSpace) {
    std::string testJsonText = "{\"name                    \"            :                   \"Kakarott\",\"hp\": 30000,\"dmg\": 9000    }";
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

TEST(HeroTest, heroLvlUpTest) {
    Hero testhero ("Testhero", 1000, 120, 3.2);
    testhero.incXp(101);
    ASSERT_EQ(1100, testhero.getMaxHp());
    ASSERT_EQ(132, testhero.getDmg());
    ASSERT_FLOAT_EQ(2.88, testhero.getAtkspeed());
}

TEST(HeroTest, getAttackTest){
    Hero attacker ("Attacker", 1000, 80, 3.2);
    Hero attacked ("Attacked", 1000, 70, 3.2);
    attacked.getAttack(attacker);
    ASSERT_EQ(920, attacked.getActHp());
    attacker.getAttack(attacked);
    ASSERT_EQ(930, attacker.getActHp());
}

TEST(HeroTest, multiplyLvlUpTest){
    Hero testhero ("Testhero", 1000, 120, 3.2);
    testhero.incXp(301);
    ASSERT_EQ(1331, testhero.getMaxHp());
    ASSERT_EQ(160, testhero.getDmg());
    ASSERT_FLOAT_EQ(2.3328, testhero.getAtkspeed());
}

TEST(HeroTest, goodWinnerTest){
    Hero h1 = Hero::parseUnit("units/kakarott.json");
    Hero h2 = Hero::parseUnit("units/kikarott.json");

    h1.fight(h2);

    ASSERT_EQ(0, h1.getActHp());
} 

TEST(HeroTest, actHpBeMaxHpTest){
    Hero testhero ("Testhero", 1000, 120, 3.2);
    testhero.incXp(101);
    ASSERT_EQ(testhero.getActHp(), testhero.getMaxHp());
}

TEST(HeroTest, xpDecTest){
    Hero testhero ("Testhero", 1000, 120, 3.2);
    testhero.incXp(150);
    ASSERT_EQ(50, testhero.getXp());
}

TEST(HeroTest, xpIncTest){
    Hero testhero ("Testhero", 1000, 120, 3.2);
    testhero.incXp(99);
    ASSERT_EQ(99, testhero.getXp());
}

int main(int argc, char* argv[]){
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}