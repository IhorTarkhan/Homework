#include <gtest/gtest.h>

TEST(SuiteName, TestName1) {
    EXPECT_EQ(0, 0);
    std::cout << 1;
}

TEST(SuiteName, TestName2) {
    EXPECT_NE(0, -10);
    std::cout << 2;
}
