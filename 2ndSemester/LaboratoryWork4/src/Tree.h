#ifndef HOMEWORK_TREE_H
#define HOMEWORK_TREE_H

#include "TreeNode.h"

class Tree {
public:
    TreeNode *root;

    explicit Tree(TreeNode *root) {
        this->root = root;
    }

    void add(TreeNode *node, int value, double p) {
        if (p < 0 || p > 1) {
            throw invalid_argument("Incorrect random value p.");
        }

        double randValue = ((double) rand() / RAND_MAX);
        if (randValue <= p || node->posterity.empty()) {
            node->posterity.push_back(new TreeNode(value));
        } else {
            int randomElementIndex = rand() % node->posterity.size();
            add(node->posterity[randomElementIndex], value, p);
        }
    }

    string outputUsingParentheses() {
        return root->getOutputUsingParentheses();
    }
};

#endif
