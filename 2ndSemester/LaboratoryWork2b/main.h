#include <iostream>
#include "Task9.h"
#include "Task11.h"
#include "Task17.h"

using namespace std;

int main_Lab_2_2b() {
    const int task9Int = 9;
    const int task11Int = 11;
    const int task17Int = 17;
    const int task9DemoInt = -9;
    const int task11DemoInt = -11;
    const int task17DemoInt = -17;
    Task9 task9;
    Task11 task11;
    Task17 task17;
    while (true) {
        cout << endl << endl;
        cout << "My tasks: #" << task9Int << ", #" << task11Int << ", #" << task17Int << endl;
        cout << "My demons: #" << task9DemoInt << ", #" << task11DemoInt << ", #" << task17DemoInt << endl;
        cout << "Choice one: ";
        int task;
        cin >> task;
        switch (task) {
            case task9Int:
                task9.run();
                break;
            case task11Int:
                task11.run();
                break;
            case task17Int:
                task17.run();
                break;

            case task9DemoInt:
                task9.demon();
                break;
            case task11DemoInt:
                task11.demon();
                break;
            case task17DemoInt:
                task17.demon();
                break;

            default:
                cout << "Incorrect choice!" << endl;
        }
    }
}