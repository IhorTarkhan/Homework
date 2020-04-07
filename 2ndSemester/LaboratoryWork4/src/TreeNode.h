#ifndef HOMEWORK_TREENODE_H
#define HOMEWORK_TREENODE_H

#include "vector"

using namespace std;

class TreeNode {
private:
    int value;
public:
    vector<TreeNode *> posterity;

    explicit TreeNode(int value) {
        this->value = value;
    }

    int getValue() const {
        return value;
    }

    string getOutputUsingParentheses() {
        string outputData = to_string(value);
        if (!posterity.empty()) {
            outputData += "(";
            for (int i = 0; i < posterity.size(); ++i) {
                outputData += posterity[i]->getOutputUsingParentheses();
                if (i != posterity.size() - 1) {
                    outputData += ", ";
                }
            }
            outputData += ")";
        }
        return outputData;
    }
};

#endif
