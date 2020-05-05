#ifndef HOMEWORK_MAIN_H
#define HOMEWORK_MAIN_H

#include "src/DataStructure.h"
#include "src/OrderedLists/LinkedList.h"
#include "src/OrderedLists/VectorList.h"
#include "src/OrderedLists/NotBalancedBinaryTree.h"
#include "src/OrderedLists/AVL_Tree.h"

int main_Lab_2_6() {
    AVL_Tree linkedList = AVL_Tree::createRandomListWithSize(5);
    linkedList.append(DataStructure(10, 15, 20));
    linkedList.append(DataStructure(10, 15, 20));
    linkedList.append(DataStructure(10, 15, 20));
    cout << linkedList.toString();

    linkedList.removeAll(DataStructure(10, 15, 20));

    cout << endl;
    cout << linkedList.toString();
//    cout << endl;
//    vector<DataStructure> result = linkedList.search(40, 100);
//    for (int i = 0; i < result.size(); ++i) {
//        cout << result[i].toString() << endl;
//    }
    return 0;
}

#endif
