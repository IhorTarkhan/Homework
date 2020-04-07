#include "iostream"
#include "Tree.h"

using namespace std;

int main_Lab_2_4() {
    Tree tree(new TreeNode(1));
    for (int i = 2; i < 100; ++i) {
        tree.add(tree.root, i, 0.5);
    }
    cout << tree.outputUsingParentheses();
    return 0;
}
