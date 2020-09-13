#ifndef HOMEWORK_DOUBLE_H
#define HOMEWORK_DOUBLE_H

#include <iostream>

/**
 * <h1>Use double in nex format</h1>
 */
double number = 1;

/**
 * Function to check element condition, using as element comparator
 * {@code isCondition()}
 * @param element is int which checked
 * @return bool if element corresponds to the value
 */
bool isCondition(double element) {
    return element == 5.;
}

/**
 * Function to convert element in text format
 * {@code toStringInt()}
 * @param element is int which converted to string
 * @return element in text format
 */
std::string toStringInt(int element) {
    return std::to_string(element);
}

#endif
