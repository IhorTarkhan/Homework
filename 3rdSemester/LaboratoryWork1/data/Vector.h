#ifndef HOMEWORK_VECTOR_H
#define HOMEWORK_VECTOR_H

#include <iostream>

/**
 * <h1>Use vector<...></h1>
 */
#include <vector>

/**
 * <h2>As example using int vector</h2>
 */
std::vector<int> list;

/**
 * Function to check vector condition, using as element comparator
 * now as example checking only vector's size
 * {@code isCondition()}
 * @param element is int which checked
 * @return bool if vector corresponds to the value
 * in this case is vector size equal 5
 */
bool isCondition(std::vector<int> element) {
    return element.size() == 5;
}

/**
 * Function to convert vector in text format
 * {@code toStringInt()}
 * @param element is vector which converted to string
 * @return vector in text format
 */
std::string toString(std::vector<int> element) {
    std::string result = "[";
    for (int i = 0; i < element.size(); ++i) {
        result += std::to_string(element[i]) + ", ";
    }
    if (element.size() != 0) {
        result = result.substr(0, result.size() - 2);
    }
    result += "]";
    return result;
}

#endif
