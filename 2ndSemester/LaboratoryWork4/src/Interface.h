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
        cout << "Your choice: ";
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
        const string BlueInConsole = "\u001B[34m";
        const string YellowInConsole = "\u001B[33m";
        const string StandardConsole = "\u001B[0m";
        int n_0 = 0;

        Tree *root;
        BinaryTree *binaryRoot;

        cout << BlueInConsole << "TREE" << StandardConsole << endl;

        cout << "Block  0 : Create new root, with value = 0" << endl;
        root = new Tree(0);
        cout << YellowInConsole << "Done" << StandardConsole << endl << endl;

        cout << "Block  1 : add to the root new nodes: from 1 to 20, with p = 0.5" << endl;
        for (int i = 1; i <= 20; ++i) {
            root->add(new Tree(i), 0.5);
        }
        cout << YellowInConsole << "Done" << StandardConsole << endl << endl;

        cout << "Block  2 : output the tree starting from root:" << endl;
        cout << root->getOutputUsingParentheses() << endl;
        cout << YellowInConsole << "Done" << StandardConsole << endl << endl;

        cout << "Block  3 : delete all nodes with value = 5" << endl;
        root->deleteNode(5, 1);
        cout << YellowInConsole << "Done" << StandardConsole << endl << endl;

        cout << "Block  2 : output the tree starting from root:" << endl;
        cout << root->getOutputUsingParentheses() << endl;
        cout << YellowInConsole << "Done" << StandardConsole << endl << endl;

        cout << "Block  0 : Create new root, with value = -1" << endl;
        root = new Tree(-1);
        cout << YellowInConsole << "Done" << StandardConsole << endl << endl;

        cout << "Block  1 : add to the root new nodes: from 1 to 10 and ten times 5, with p = 0.5" << endl;
        for (int i = 1; i <= 10; ++i) {
            root->add(new Tree(i), 0.5);
            root->add(new Tree(5), 0.5);
        }
        cout << YellowInConsole << "Done" << StandardConsole << endl << endl;

        cout << "Block  3 : delete all nodes with value = 5" << endl;
        root->deleteNode(5, 1);
        cout << YellowInConsole << "Done" << StandardConsole << endl << endl;

        cout << "Block  2 : output the tree starting from root:" << endl;
        cout << root->getOutputUsingParentheses() << endl;
        cout << YellowInConsole << "Done" << StandardConsole << endl << endl;


        cout << "Block  0 : Create new root, with value = 0" << endl;
        root = new Tree(0);
        cout << YellowInConsole << "Done" << StandardConsole << endl << endl;

        cout << "Block  1 : add to the root new nodes: from 1 to 20, with p = 0.1" << endl;
        for (int i = 1; i <= 20; ++i) {
            root->add(new Tree(i), 0.1);
        }
        cout << YellowInConsole << "Done" << StandardConsole << endl << endl;

        cout << "Block  2 : output the tree starting from root:" << endl;
        cout << root->getOutputUsingParentheses() << endl;
        cout << YellowInConsole << "Done" << StandardConsole << endl << endl;


        cout << "Block  0 : Create new root, with value = 0" << endl;
        root = new Tree(0);
        cout << YellowInConsole << "Done" << StandardConsole << endl << endl;

        cout << "Block  1 : add to the root new nodes: from 1 to 20, with p = 0.9" << endl;
        for (int i = 1; i <= 20; ++i) {
            root->add(new Tree(i), 0.9);
        }
        cout << YellowInConsole << "Done" << StandardConsole << endl << endl;

        cout << "Block  2 : output the tree starting from root:" << endl;
        cout << root->getOutputUsingParentheses() << endl;
        cout << YellowInConsole << "Done" << StandardConsole << endl << endl;

        cout << endl;


        cout << BlueInConsole << "BINARY-TREE" << StandardConsole << endl;

        cout << "Block  4 : Create new BINARY root, with value = 10" << endl;
        binaryRoot = new BinaryTree(10);
        cout << YellowInConsole << "Done" << StandardConsole << endl << endl;

        cout << "Block 4.1: add to the BINARY root new nodes: from 1 to 20" << endl;
        for (int i = 1; i <= 20; ++i) {
            binaryRoot->add(new BinaryTree(i));
        }
        cout << YellowInConsole << "Done" << StandardConsole << endl << endl;

        cout << "Block 5.0: view BINARY tree as simple Tree (by parentheses)" << endl;
        cout << binaryRoot->getOutputUsingParentheses() << endl;
        cout << YellowInConsole << "Done" << StandardConsole << endl << endl;

        cout << "Block  5 : view BINARY tree" << endl;
        cout << "/// Format of Presentation: ('value', 'rightIndex', 'isLeft')" << endl;
        cout << binaryRoot->consistentPresentation(n_0) << endl;
        n_0 = 0;
        cout << YellowInConsole << "Done" << StandardConsole << endl << endl;

        cout << "Block  4 : Create new BINARY root, with value = 10" << endl;
        binaryRoot = new BinaryTree(10);
        cout << YellowInConsole << "Done" << StandardConsole << endl << endl;

        cout << "Block 4.1: add to the BINARY root 20 new nodes: random between 1 and 20" << endl;
        for (int i = 1; i <= 20; ++i) {
            binaryRoot->add(new BinaryTree(rand() % 20 + 1));
        }
        cout << YellowInConsole << "Done" << StandardConsole << endl << endl;

        cout << "Block 5.0: view BINARY tree as simple Tree (by parentheses)" << endl;
        cout << binaryRoot->getOutputUsingParentheses() << endl;
        cout << YellowInConsole << "Done" << StandardConsole << endl << endl;

        cout << "Block  5 : view BINARY tree" << endl;
        cout << "/// Format of Presentation: ('value', 'rightIndex', 'isLeft')" << endl;
        cout << binaryRoot->consistentPresentation(n_0) << endl;
        n_0 = 0;
        cout << YellowInConsole << "Done" << StandardConsole << endl << endl;

        cout << endl;
    }
};

#endif
