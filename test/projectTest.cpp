#include <gtest/gtest.h>
#include "../JSON.h"
#include "../Hero.h"
#include "../Monster.h"
#include "../Map.h"
#include "../Game.h"

TEST(ParseTest, stringParseTest) {
    std::string testJsonText = "{\"name\": \"Zombie\",\"health_points\": 10,\"physical_damage\": 3, \"magical_damage\": 1, \"attack_cooldown\": 2.8, \"defense\": 0}";

    JSON test = JSON::parseFromString(testJsonText);

    ASSERT_EQ(test.get<std::string>("name"), "Zombie");
    ASSERT_EQ(test.get<int>("health_points"), 10);
    ASSERT_EQ(test.get<int>("physical_damage"), 3);
    ASSERT_EQ(test.get<int>("magical_damage"), 1);
    ASSERT_EQ(test.get<int>("defense"), 0);
    ASSERT_FLOAT_EQ(test.get<float>("attack_cooldown"), 2.8);
}

TEST(ParseTest, fileParseTest) {
    std::string testfile = "../Zombie.json";

    JSON test = JSON::parseFromFile(testfile);

    ASSERT_EQ(test.get<std::string>("name"), "Zombie");
    ASSERT_EQ(test.get<int>("health_points"), 10);
    ASSERT_EQ(test.get<int>("physical_damage"), 3);
    ASSERT_EQ(test.get<int>("magical_damage"), 1);
    ASSERT_EQ(test.get<int>("defense"), 0);
    ASSERT_FLOAT_EQ(test.get<float>("attack_cooldown"), 2.8);
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
    Hero testhero ("Testhero", 1000, 50, 250, 100, 50, 50, 50, 0.9, 3.2, 5, 5, 2, 1);
    testhero.incXp(251);
    ASSERT_EQ(1050, testhero.getMaxHealthPoints());
    ASSERT_EQ(150, testhero.getPhysicalDamage());
    ASSERT_EQ(100, testhero.getMagicalDamage());
    ASSERT_EQ(10, testhero.getDefense());
    ASSERT_FLOAT_EQ(2.88, testhero.getAttackCoolDown());
    ASSERT_EQ(3, testhero.getLightRadius());
}

TEST(HeroTest, multiplyLvlUp) {
    Hero testhero ("Testhero", 1000, 50, 250, 100, 50, 50, 50, 0.9, 3.2, 5, 5, 2, 1);
    testhero.incXp(501);
    ASSERT_EQ(1100, testhero.getMaxHealthPoints());
    ASSERT_EQ(200, testhero.getPhysicalDamage());
    ASSERT_EQ(150, testhero.getMagicalDamage());
    ASSERT_EQ(15, testhero.getDefense());
    ASSERT_FLOAT_EQ(2.592, testhero.getAttackCoolDown());
    ASSERT_EQ(4, testhero.getLightRadius());
}

TEST(HeroTest, xpDecTest){
    Hero testhero ("Testhero", 1000, 50, 250, 100, 50, 50, 50, 0.9, 3.2, 5, 5, 2, 1);
    testhero.incXp(260);
    ASSERT_EQ(10, testhero.getXp());
}

TEST(HeroTest, xpNotIncTest){
   Hero testhero ("Testhero", 1000, 50, 250, 100, 50, 50, 50, 0.9, 3.2, 5, 5, 2, 1);
    testhero.incXp(249);
    ASSERT_EQ(249, testhero.getXp());
}

TEST(FightTest, heroVsHero){
    Hero testhero ("Testhero", 1000, 50, 250, 100, 50, 50, 50, 0.9, 3.2, 5, 5, 2, 1);
    Hero testhero2 ("Testhero2", 1500, 106, 250, 100, 50, 50, 50, 0.9, 3.0, 5, 15, 2, 1);

    testhero.fightTilDeath(testhero2);

    ASSERT_TRUE(!testhero.isAlive());
    ASSERT_EQ(testhero2.getHealthPoints(), 2454);
} 

TEST(FightTest, monsterVsHero){
    Monster testmonster ("TestMonster", 5000, 500, 250, 50, 5.8);
    Hero testhero ("Testhero", 1000, 50, 250, 100, 50, 50, 50, 0.9, 3.2, 5, 5, 2, 1);

    testhero.fightTilDeath(testmonster);

    ASSERT_TRUE(!testmonster.isAlive());
    ASSERT_EQ(testhero.getHealthPoints(), 2000);
} 

TEST(FightTest, monsterVsMonster){
    Monster testmonster ("TestMonster", 5000, 500, 250, 50, 5.8);
    Monster testmonster2 ("TestMonster", 10000, 500, 250, 50, 5.9);

    testmonster.fightTilDeath(testmonster2);

    ASSERT_TRUE(!testmonster.isAlive());
    ASSERT_EQ(testmonster2.getHealthPoints(), 4400);
}

int main(int argc, char* argv[]){
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}