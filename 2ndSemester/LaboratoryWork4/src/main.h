#include "iostream"
#include "BinaryTree.h"
#include "Tree.h"

using namespace std;

int main_Lab_2_4() {
    /*
    Tree *root = new Tree(0);
    for (int i = 1; i < 20; ++i) {
        root->add(new Tree(i), 0.9999999);
    }
    Tree *tree5_1 = new Tree(5);
    tree5_1->add(new Tree(6), 0.9999999);
    tree5_1->add(new Tree(5), 0.9999999);
    tree5_1->add(new Tree(7), 0.9999999);
    tree5_1->add(new Tree(6), 0.9999999);
    Tree *tree5_2 = new Tree(2);
    Tree *tree5_3 = new Tree(2);
    Tree *tree5_4 = new Tree(4);
    Tree *tree5_5 = new Tree(6);
    Tree *tree5_6 = new Tree(7);
    Tree *tree5_7 = new Tree(8);
    Tree *tree5_55 = new Tree(5);
    root->add(tree5_1, 0.9999999);
    root->add(tree5_2, 0.9999999);
    root->add(tree5_3, 0.9999999);
    root->add(tree5_4, 0.9999999);
    root->add(tree5_5, 0.9999999);
    root->add(tree5_6, 0.9999999);
    root->add(tree5_7, 0.9999999);
    root->add(tree5_55, 0.9999999);

    cout << root->getOutputUsingParentheses() << endl;
    root->deleteNode(5, 0.99999999999);
    cout << root->getOutputUsingParentheses() << endl;*/

    BinaryTree *root = new BinaryTree(5);
    for (int i = 1; i < 20; ++i) {
        root->add(new BinaryTree(rand() % 10));
    }
    cout << root->getOutputUsingParentheses() << endl;
    return 0;
}
