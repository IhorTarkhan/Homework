#include <iostream>
#include "Task17.h"

using namespace std;

int main_Lab_2_2b() {
    const int task17Int = 17;
    Task17 task17;
    while (true) {
        cout << "My tasks: #" << task17Int << endl;
        cout << "Choice one: ";
        int task;
        cin >> task;
        switch (task) {
            case task17Int:
                task17.run();
                cout << "Done!" << endl;
                break;
            default:
                cout << "Incorrect choice!" << endl;

        }
    }
}