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
    ASSERT_THROW(list->get(0), std::exception);
    ASSERT_THROW(list->get(-1), std::exception);
}

std::string toStringInt(int i) {
    return std::to_string(i);
}

TEST(ArryList, toStringTest) {
    List<int> *list = new ArrayList<int>(compareInt);
    ASSERT_EQ("[]", list->toString(toStringInt));
    list->add(1);
    ASSERT_EQ("[1]", list->toString(toStringInt));
    list->add(2);
    ASSERT_EQ("[1, 2]", list->toString(toStringInt));
}
