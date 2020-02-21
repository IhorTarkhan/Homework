#include <iostream>
#include "QueueImplementations/ArrayQueue.h"
#include "QueueImplementations/VectorQueue.h"
#include "QueueImplementations/LinkedQueue.h"
#include "ConsoleWork/demo.h"
#include "ConsoleWork/interactive.h"

using namespace std;

void printPosition(Position position) {
    cout << to_string(position.x) << "; " << to_string(position.y) << "; " << to_string(position.z) << endl;
}

int main_Lab_2_2() {
    const int n = 5;

    VirtualQueue *aQueue = new LinkedQueue();
    aQueue->create_empty(n);
    cout << aQueue->is_empty() << endl;

    aQueue->enqueue(Position(1, 40.999999999, 30.555555555));
    cout << aQueue->is_empty() << endl;
    aQueue->enqueue(Position(2, 40.999999999, 30.555555555));
    cout << aQueue->is_empty() << endl;
    aQueue->enqueue(Position(3, 40.999999999, 30.555555555));
    cout << aQueue->is_empty() << endl;
    aQueue->enqueue(Position(4, 40.999999999, 30.555555555));
    cout << aQueue->is_empty() << endl;
    aQueue->enqueue(Position(5, 40.999999999, 30.555555555));
    cout << aQueue->is_empty() << endl;

    for (int i = 0; i < n; ++i) {
        printPosition(aQueue->dequeue());
        cout << aQueue->is_empty() << endl;
    }
}
