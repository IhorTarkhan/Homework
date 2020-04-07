#ifndef HOMEWORK_BINARYTREE_H
#define HOMEWORK_BINARYTREE_H

#include <string>
#include <stdexcept>
#include "vector"

using namespace std;

class BinaryTree {
public:
    int value;
    BinaryTree *left;
    BinaryTree *right;

    explicit BinaryTree(int value) {
        this->value = value;
        left = nullptr;
        right = nullptr;
    }

    void add(BinaryTree *binTree) {
        if (binTree->value < this->value) {
            if (left == nullptr) {
                left = binTree;
            } else {
                left->add(binTree);
            }
        } else {
            if (right == nullptr) {
                right = binTree;
            } else {
                right->add(binTree);
            }
        }
    }

    string getOutputUsingParentheses() {
        string outputData = to_string(value);
        if (left == nullptr && right == nullptr) {
            return outputData;
        }
        outputData += "(";
        if (left == nullptr) {
            outputData += "-";
        } else {
            outputData += left->getOutputUsingParentheses();
        }
        outputData += ", ";
        if (right == nullptr) {
            outputData += "-";
        } else {
            outputData += right->getOutputUsingParentheses();
        }
        outputData += ")";
        return outputData;
    }
};


#endif
