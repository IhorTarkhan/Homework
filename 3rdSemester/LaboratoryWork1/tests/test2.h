#include <gtest/gtest.h>

TEST(SuiteName, TestName3) {
    EXPECT_EQ(0, 0);
    std::cout << 3;
}

TEST(SuiteName, TestName4) {
    EXPECT_NE(0, -10);
    std::cout << 4;
}
