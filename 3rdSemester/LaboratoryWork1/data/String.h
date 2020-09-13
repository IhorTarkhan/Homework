#ifndef HOMEWORK_STRING_H
#define HOMEWORK_STRING_H

#include <iostream>

/**
 * <h1>Use string in nex format</h1>
 */
std::string text = "your text";

/**
 * Function to check element condition, using as element comparator
 * {@code isCondition()}
 * @param element is string which checked
 * @return bool if element corresponds to the value
 */
bool isCondition(std::string element) {
    return element.compare("your text") == 0;
}

/**
 * Function to convert element in text format
 * {@code toStringInt()}
 * @param element is string which converted to string
 * @return element in text format
 */
std::string toStringInt(std::string element) {
    return element;
}

#endif
