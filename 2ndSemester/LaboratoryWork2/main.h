#include <iostream>
#include "ArrayQueue.h"

using namespace std;

void printPosition(Position position) {
    cout << to_string(position.x) << "; " << to_string(position.y) << "; " << to_string(position.z) << endl;
}

int main_Lab_2_2() {
    const int n = 5;

    ArrayQueue aQueue = ArrayQueue();
    aQueue.create_empty(n);

    aQueue.enqueue(Position(1, 40.999999999, 30.555555555));
    aQueue.enqueue(Position(2, 40.999999999, 30.555555555));
    aQueue.enqueue(Position(3, 40.999999999, 30.555555555));
    aQueue.enqueue(Position(4, 40.999999999, 30.555555555));
    aQueue.enqueue(Position(5, 40.999999999, 30.555555555));

    for (int i = 0; i < n; ++i) {
        printPosition(aQueue.dequeue());
    }
}
