#include <hw05.h>
#include <vector>
#include <string>
#include <gtest/gtest.h>

TEST(Hw05Tests, Test1) {
    const vector<string> input = {"madam", "radar", "anagram", "rotor"};
    const vector<string> expected = {"madam", "radar", "rotor"};
    EXPECT_EQ(expected, hw05(input));
}

TEST(Hw05Tests, Test2) {
    const vector<string> input = {"Madam, in Eden, I'm Adam"};
    const vector<string> expected = {"Madam, in Eden, I'm Adam"};
    EXPECT_EQ(expected, hw05(input));
}

TEST(Hw05Tests, Test3) {
    const vector<string> input = {"A man, a plan, a canal, Panama!", "SIMPLETEXT"};
    const vector<string> expected = {"A man, a plan, a canal, Panama!"};
    EXPECT_EQ(expected, hw05(input));
}

TEST(Hw05Tests, Test4) {
    const vector<string> input = {"", "!@#$%^&*()"};
    const vector<string> expected = {"", "!@#$%^&*()"};
    EXPECT_EQ(expected, hw05(input));
}

TEST(Hw05Tests, Test5) {
    const vector<string> input = {"RaceCar", "12321", "hello"};
    const vector<string> expected = {"RaceCar", "12321"};
    EXPECT_EQ(expected, hw05(input));
}

int main(int argc, char** argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}