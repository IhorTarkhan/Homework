#include "iostream"
#include "Tree.h"

using namespace std;

int main_Lab_2_4() {
    Tree tree(new TreeNode(0));
    for (int i = 1; i < 20; ++i) {
        tree.add(tree.root, i, 0.5);
    }
    cout << tree.outputUsingParentheses();
    return 0;
}
