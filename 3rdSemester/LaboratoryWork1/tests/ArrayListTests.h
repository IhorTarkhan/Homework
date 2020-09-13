#include <gtest/gtest.h>
#include <climits>

#include "../List.h"
#include "../ArrayList.h"

int compareInt(int a, int b) {
    return a - b;
}

TEST(ArryList, sizeZeroTest) {
    List<int> *list = new ArrayList<int>(compareInt);
    ASSERT_EQ(0, list->size());
}

TEST(ArryList, addTest) {
    List<int> *list = new ArrayList<int>(compareInt);
    list->add(0);
    list->add(1);
    list->add(-1);
    list->add(INT_MIN);
    list->add(INT_MAX);
}

TEST(ArryList, sizeTest) {
    List<int> *list = new ArrayList<int>(compareInt);
    for (int i = 1; i < 10; ++i) {
        list->add(i);
        ASSERT_EQ(i, list->size());
    }
}

TEST(ArryList, addWithResizeTest) {
    List<int> *list = new ArrayList<int>(compareInt);
    for (int i = 1; i < 50; ++i) {
        list->add(i);
        ASSERT_EQ(i, list->size());
    }
}

TEST(ArryList, getByIndexTest) {
    List<int> *list = new ArrayList<int>(compareInt);
    for (int i = 0; i < 10; ++i) {
        list->add(i);
        ASSERT_EQ(i, list->get(i));
    }
}
TEST(ArryList, getByNotExistingIndexTest) {
    List<int> *list = new ArrayList<int>(compareInt);
    ASSERT_THROW(list->get(100), std::exception);
}

TEST(SuiteName, TestName2) {
    ASSERT_NE(0, -10);
    std::cout << 2;
}
