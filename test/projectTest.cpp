#include <gtest/gtest.h>
#include "../JSON.h"
#include "../Hero.h"
#include "../Monster.h"

TEST(ParseTest, stringParseTest) {
    std::string testJsonText = "{\"name\": \"Kakarott\",\"health_points\": 30000,\"damage\": 9000, \"attack_cooldown\": 4.2}";

    JSON testing = JSON::parseFromString(testJsonText);

    ASSERT_EQ(testing.get<std::string>("name"), "Kakarott");
    ASSERT_EQ(testing.get<int>("health_points"), 30000);
    ASSERT_EQ(testing.get<int>("damage"), 9000);
    ASSERT_FLOAT_EQ(testing.get<float>("attack_cooldown"), 4.2);
}

TEST(ParseTest, fileParseTest) {
    std::string testfile = "units/kakarott.json";

    JSON testing = JSON::parseFromFile(testfile);

    ASSERT_EQ(testing.get<std::string>("name"), "Kakarott");
    ASSERT_EQ(testing.get<int>("health_points"), 300);
    ASSERT_EQ(testing.get<int>("damage"), 90);
    ASSERT_FLOAT_EQ(testing.get<float>("attack_cooldown"), 4.2);
}

TEST(ParseTest, streamParseTest) {
    std::fstream testStream("units/kakarott.json");

    JSON testing = JSON::parseFromStream(testStream);

    ASSERT_EQ(testing.get<std::string>("name"), "Kakarott");
    ASSERT_EQ(testing.get<int>("health_points"), 300);
    ASSERT_EQ(testing.get<int>("damage"), 90);
    ASSERT_FLOAT_EQ(testing.get<float>("attack_cooldown"), 4.2);
}

TEST(ParseTest, badInputTest) {
    std::string testfile = "units/badunit.json";

    try{
        JSON::parseFromFile(testfile);
        ASSERT_TRUE(true);
    } catch(std::runtime_error& e){
        ASSERT_STREQ(e.what(), "Wrong JSON syntax!");
    }
}

TEST(JSONFileTest, unmatchedQuo) {
    std::string testJsonText = "{\"name\": \"Kakarott,\"hp\": 30000,\"dmg\": 9000}";

    try{
        JSON::parseFromString(testJsonText);
        ASSERT_TRUE(true);
    } catch(std::runtime_error& e){
        ASSERT_STREQ(e.what(), "Wrong JSON syntax!");
    }
}

TEST(JSONFileTest, missingComma) {
    std::string testJsonText = "{\"name\": \"Kakarott\"\"hp\": 30000,\"dmg\": 9000}";

    try{
        JSON::parseFromString(testJsonText);
        ASSERT_TRUE(true);
    } catch(std::runtime_error& e){
        ASSERT_STREQ(e.what(), "Wrong JSON syntax!");
    }
}

TEST(JSONFileTest, missingColon) {
    std::string testJsonText = "{\"name\": \"Kakarott\",\"hp\" 30000,\"dmg\": 9000}";

    try{
        JSON::parseFromString(testJsonText);
        ASSERT_TRUE(true);
    } catch(std::runtime_error& e){
        ASSERT_STREQ(e.what(), "Wrong JSON syntax!");
    }
}

TEST(JSONFileTest, TooMuchWhiteSpace) {
    std::string testJsonText = "{\"name                    \"            :                   \"Kakarott\",\"hp\": 30000,\"dmg\": 9000  , \"attack_cooldown  \" :       4.2  }";
    JSON testing = JSON::parseFromString(testJsonText);

    ASSERT_EQ(testing.get<std::string>("name"), "Kakarott");
    ASSERT_EQ(testing.get<int>("hp"), 30000);
    ASSERT_EQ(testing.get<int>("dmg"), 9000);
    ASSERT_FLOAT_EQ(testing.get<float>("attack_cooldown"), 4.2);
}


TEST(JSONFileTest, switchedKeys) {
    std::string testJsonText = "{\"hp\": 30000, \"name\": \"Kakarott\", \"attack_cooldown\": 4.2, \"dmg\": 9000}";
    JSON testing = JSON::parseFromString(testJsonText);

    ASSERT_EQ(testing.get<std::string>("name"), "Kakarott");
    ASSERT_EQ(testing.get<int>("hp"), 30000);
    ASSERT_EQ(testing.get<int>("dmg"), 9000);
    ASSERT_FLOAT_EQ(testing.get<float>("attack_cooldown"), 4.2);
}

TEST(HeroTest, heroLvlUpTest) {
    Hero testhero ("Testhero", 1000, 50, 250, 120, 20, 0.9, 3.2);
    testhero.incXp(251);
    ASSERT_EQ(1050, testhero.getMaxHealthPoints());
    ASSERT_EQ(140, testhero.getDamage());
    ASSERT_FLOAT_EQ(2.88, testhero.getAttackCoolDown());
}

TEST(HeroTest, multiplyLvlUp) {
    Hero testhero ("Testhero", 1000, 50, 250, 120, 20, 0.9, 3.2);
    testhero.incXp(501);
    ASSERT_EQ(1100, testhero.getMaxHealthPoints());
    ASSERT_EQ(160, testhero.getDamage());
    ASSERT_FLOAT_EQ(2.592, testhero.getAttackCoolDown());
}

TEST(HeroTest, xpDecTest){
    Hero testhero ("Testhero", 1000, 50, 250, 120, 20, 0.9, 3.2);
    testhero.incXp(260);
    ASSERT_EQ(10, testhero.getXp());
}

TEST(HeroTest, xpNotIncTest){
    Hero testhero ("Testhero", 1000, 50, 250, 120, 20, 0.9, 3.2);
    testhero.incXp(249);
    ASSERT_EQ(249, testhero.getXp());
}

TEST(FightTest, heroVsHero){
    Hero testhero ("Testhero1", 1000, 50, 250, 120, 20, 0.9, 3.2);
    Hero testhero2 ("Testhero2", 2000, 200, 100, 500, 20, 0.8, 3.02);

    testhero.fightTilDeath(testhero2);

    ASSERT_TRUE(!testhero.isAlive());
    ASSERT_EQ(testhero2.getHealthPoints(), 4000);
} 

TEST(FightTest, monsterVsHero){
    Monster testmonster ("TestMonster", 5000, 700, 5.8);
    Hero testhero ("Testhero", 2000, 200, 100, 500, 20, 0.8, 3.02);

    testhero.fightTilDeath(testmonster);

    ASSERT_TRUE(!testmonster.isAlive());
    ASSERT_EQ(testhero.getHealthPoints(), 12000);
} 

TEST(FightTest, monsterVsMero){
    Monster testmonster ("TestMonster", 5000, 700, 5.8);
    Monster testmonster2 ("TestMonster2", 7000, 500, 4.1);

    testmonster.fightTilDeath(testmonster2);

    ASSERT_TRUE(!testmonster.isAlive());
    ASSERT_EQ(testmonster2.getHealthPoints(), 2100);
}

int main(int argc, char* argv[]){
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}