#ifndef HOMEWORK_TREENODE_H
#define HOMEWORK_TREENODE_H

#include "vector"

using namespace std;

class TreeNode {
public:
    int value;
    vector<TreeNode *> posterity;

    explicit TreeNode(int value) {
        this->value = value;
    }

    string outputUsingParentheses() {
        string outputData = to_string(value);
        if (!posterity.empty()) {
            outputData += "(";
            for (int i = 0; i < posterity.size(); ++i) {
                outputData += posterity[i]->outputUsingParentheses();
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
