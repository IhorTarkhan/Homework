#ifndef HOMEWORK_MAIN_H
#define HOMEWORK_MAIN_H

#include "src/DataStructure.h"
#include "src/OrderedLists/LinkedList.h"

int main_Lab_2_6() {
    LinkedList linkedList = LinkedList::createRandomListWithSize(5);
    linkedList.append(DataStructure(10, 15, 20));
    linkedList.append(DataStructure(10, 15, 20));
    linkedList.append(DataStructure(10, 15, 20));
    linkedList.append(DataStructure(10, 15, 20));
    cout << linkedList.toString();

    cout << endl;
    vector<DataStructure> result = linkedList.search(64.315969, 1.0);
    for (int i = 0; i < result.size(); ++i) {
        cout << result[i].toString() << endl;
    }
    return 0;
}

#endif
