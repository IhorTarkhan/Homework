#ifndef HOMEWORK_TREE_H
#define HOMEWORK_TREE_H

#include <string>
#include <stdexcept>
#include "vector"

using namespace std;

class Tree {
public:
    int value;
    vector<Tree *> posterity;

    explicit Tree(int value) {
        this->value = value;
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

    void add(Tree *newNode, double p) {
        if (p < 0 || p > 1) {
            throw invalid_argument("Incorrect random value p.");
        }

        double randValue = (double) rand() / RAND_MAX;
        if (randValue <= p || posterity.empty()) {
            posterity.push_back(newNode);
        } else {
            int randomElementIndex = rand() % posterity.size();
            posterity[randomElementIndex]->add(newNode, p);
        }
    }

    void deleteNode(int value, double p) {
        if (posterity.empty()) {
            return;
        }
        for (int i = 0; i < posterity.size(); ++i) {
            if (posterity[i]->value == value) {
                vector<Tree *> reservePosterity = posterity[i]->posterity;
                posterity.erase(posterity.begin() + i);

                for (int j = 0; j < reservePosterity.size(); ++j) {
                    add(reservePosterity[j], p);
                }
                deleteNode(value, p);
            }
            posterity[i]->deleteNode(value, p);
        }
    }
};

#endif
