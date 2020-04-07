#ifndef HOMEWORK_INTERFACE_H
#define HOMEWORK_INTERFACE_H

#include "iostream"
#include "BinaryTree.h"
#include "Tree.h"

using namespace std;

class Interface {
public:
    static void dialog(Tree *root, BinaryTree *binaryRoot) {
        int n0 = 0;
        cout << "Available options:" << endl;
        cout << "Block  0 : create new root of tree and work with it" << endl;
        cout << "Block  1 : add to the root new node" << endl;
        cout << "Block  2 : output the tree starting from root" << endl;
        cout << "Block  3 : delete all nodes by their value" << endl;
        cout << "Block  4 : create new root of BINARY tree and work with it" << endl;
        cout << "Block -1 : add to the BINARY root new node" << endl;
        cout << "Block  5 : view BINARY tree" << endl;
        cout << "Block -2 : view BINARY tree as simple Tree (by parentheses)" << endl;
        int n;
        double p;
        cin >> n;
        switch (n) {
            case 0:
                cout << "\t" << "Enter value: ";
                cin >> n;
                root = new Tree(n);
                break;
            case 1:
                cout << "\t" << "Enter value: ";
                cin >> n;
                cout << "\t" << "Enter p [0.0, 1.0]: ";
                cin >> p;
                root->add(new Tree(n), p);
                break;
            case 2:
                cout << root->getOutputUsingParentheses();
                break;
            case 3:
                cout << "\t" << "Enter value: ";
                cin >> n;
                cout << "\t" << "Enter p [0.0, 1.0]: ";
                cin >> p;
                root->deleteNode(n, p);
                break;
            case 4:
                cout << "\t" << "Enter value: ";
                cin >> n;
                binaryRoot = new BinaryTree(n);
                break;
            case -1:
                cout << "\t" << "Enter value: ";
                cin >> n;
                binaryRoot->add(new BinaryTree(n));
                break;
            case 5:
                cout << binaryRoot->consistentPresentation(n0);
                break;
            case -2:
                cout << binaryRoot->getOutputUsingParentheses();
                break;
            default:
                cout << "Error case" << endl;
        }
    }

    static void demon() {

    }
};

#endif
