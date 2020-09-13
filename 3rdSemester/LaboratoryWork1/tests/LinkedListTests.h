#include <gtest/gtest.h>
#include <climits>

#include "../list_implementation/LinkedList.h"

TEST(LinkedList, sizeZeroTest) {
    List<int> *list = new LinkedList<int>();
    ASSERT_EQ(0, list->size());
}

TEST(LinkedList, addTest) {
    List<int> *list = new LinkedList<int>();
    list->add(0);
    list->add(1);
    list->add(-1);
    list->add(INT_MIN);
    list->add(INT_MAX);
}

TEST(LinkedList, sizeTest) {
    List<int> *list = new LinkedList<int>();
    for (int i = 1; i < 10; ++i) {
        list->add(i);
        ASSERT_EQ(i, list->size());
    }
}

TEST(LinkedList, addWithResizeTest) {
    List<int> *list = new LinkedList<int>();
    for (int i = 1; i < 100; ++i) {
        list->add(i);
        ASSERT_EQ(i, list->size());
    }
}

TEST(LinkedList, getByIndexTest) {
    List<int> *list = new LinkedList<int>();
    for (int i = 0; i < 10; ++i) {
        list->add(i);
        ASSERT_EQ(i, list->get(i));
    }
}

TEST(LinkedList, getByNotExistingIndexTest) {
    List<int> *list = new LinkedList<int>();
    ASSERT_THROW(list->get(100), std::exception);
    ASSERT_THROW(list->get(0), std::exception);
    list->add(99);
    ASSERT_THROW(list->get(1), std::exception);
    ASSERT_THROW(list->get(-1), std::exception);
}

TEST(LinkedList, getIndexWhereConditionTest) {
    List<int> *list = new LinkedList<int>();
    list->add(1);
    ASSERT_THROW(list->getIndexWhereCondition(equalsFive), std::exception);
    list->add(5);
    ASSERT_EQ(1, list->getIndexWhereCondition(equalsFive));
}

TEST(LinkedList, toStringTest) {
    List<int> *list = new LinkedList<int>();
    ASSERT_EQ("[]", list->toString(toStringInt));
    list->add(1);
    ASSERT_EQ("[1]", list->toString(toStringInt));
    list->add(2);
    ASSERT_EQ("[1, 2]", list->toString(toStringInt));
}
