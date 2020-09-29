#ifndef HOMEWORK_INT_H
#define HOMEWORK_INT_H

#include <iostream>

/**
 * <h1>Use int in nex format</h1>
 */
int number = 1;

/**
 * Function to check int condition, using as element comparator
 * {@code isCondition()}
 * @param element is int which checked
 * @return bool if int corresponds to the value
 */
bool isCondition(int element) {
    return element == 5;
}

/**
 * Function to convert int in text format
 * {@code toStringInt()}
 * @param element is int which converted to string
 * @return int in text format
 */
std::string toStringInt(int element) {
    return std::to_string(element);
}

#endif
