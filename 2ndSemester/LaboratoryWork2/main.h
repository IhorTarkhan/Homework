#include <iostream>
#include "ArrayQueue.h"
#include "VectorQueue.h"
#include "LinkedQueue.h"

using namespace std;

void printPosition(Position position) {
    cout << to_string(position.x) << "; " << to_string(position.y) << "; " << to_string(position.z) << endl;
}

int main_Lab_2_2() {
    const int n = 5;

    LinkedQueue aQueue = LinkedQueue();
    aQueue.create_empty();
    cout << aQueue.is_empty() << endl;

    aQueue.enqueue(Position(1, 40.999999999, 30.555555555));
    cout << aQueue.is_empty() << endl;
    aQueue.enqueue(Position(2, 40.999999999, 30.555555555));
    cout << aQueue.is_empty() << endl;
    aQueue.enqueue(Position(3, 40.999999999, 30.555555555));
    cout << aQueue.is_empty() << endl;
    aQueue.enqueue(Position(4, 40.999999999, 30.555555555));
    cout << aQueue.is_empty() << endl;
    aQueue.enqueue(Position(5, 40.999999999, 30.555555555));
    cout << aQueue.is_empty() << endl;

    for (int i = 0; i < n; ++i) {
        printPosition(aQueue.dequeue());
        cout << aQueue.is_empty() << endl;
    }
}
