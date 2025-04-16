#include <hw04.h>
#include <cstddef>
#include <gtest/gtest.h>

extern int hw04(const int* input_array, std::size_t elem_count);

TEST(Hw04Tests, Test1) {
    const int input[] = {11, 0, -22, 33, -1};
    const std::size_t size = sizeof(input) / sizeof(input[0]);
    const int expected = 11;
    EXPECT_EQ(expected, hw04(input, size));
}

TEST(Hw04Tests, Test2) {
    const int input[] = {1, 2, 3, -1};
    const std::size_t size = sizeof(input) / sizeof(input[0]);
    const int expected = 6;
    EXPECT_EQ(expected, hw04(input, size));
}

TEST(Hw04Tests, Test3) {
    const int input[] = {'A', -1, 'B', 'C', 'T'};
    const std::size_t size = sizeof(input) / sizeof(input[0]);
    const int expected = 65;
    EXPECT_EQ(expected, hw04(input, size));
}

TEST(Hw04Tests, AllPositive) {
    const int input[] = {5, 3, 2};
    const std::size_t size = sizeof(input) / sizeof(input[0]);
    const int expected = 5 + 3 + 2;
    EXPECT_EQ(expected, hw04(input, size));
}

TEST(Hw04Tests, FirstElementNegative) {
    const int input[] = {-5, 3, 2};
    const std::size_t size = sizeof(input) / sizeof(input[0]);
    const int expected = 0;
    EXPECT_EQ(expected, hw04(input, size));
}

TEST(Hw04Tests, ZerosBeforeNegative) {
    const int input[] = {0, 0, -5};
    const std::size_t size = sizeof(input) / sizeof(input[0]);
    const int expected = 0;
    EXPECT_EQ(expected, hw04(input, size));
}

TEST(Hw04Tests, EmptyArray) {
    const int* input = nullptr;
    const std::size_t size = 0;
    const int expected = 0;
    EXPECT_EQ(expected, hw04(input, size));
}

TEST(Hw04Tests, MultipleReallocations) {
    const int input[] = {1, 2, 3, 4};
    const std::size_t size = sizeof(input) / sizeof(input[0]);
    const int expected = 1 + 2 + 3 + 4;
    EXPECT_EQ(expected, hw04(input, size));
}

int main(int argc, char** argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}