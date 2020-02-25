#include <iostream>
#include "QueueImplementations/ArrayQueue.h"
#include "QueueImplementations/VectorQueue.h"
#include "QueueImplementations/LinkedQueue.h"
#include "ConsoleWork/autonomous.h"
#include "ConsoleWork/interactive.h"

using namespace std;

int main_Lab_2_2a() {
    Interactive interactive;
    Autonomous autonomous;
    const string STANDARD_CONSOLE = "\u001B[38m";
    const string EXCEPTION_IN_CONSOLE = "\u001B[31m";
    while (true) {
        cout << STANDARD_CONSOLE;
        cout << "Enter operating, witch you want to use:" << endl;
        cout << "1 - interactive;" << endl;
        cout << "2 - demo;" << endl;
        cout << "3 - benchmark." << endl;
        cout << "Your choice: ";

        int choiceValue;
        cin >> choiceValue;
        switch (choiceValue) {
            case 1:
                try {
                    interactive.run();
                } catch (const char *msg) {
                    cout << EXCEPTION_IN_CONSOLE;
                    cout << msg << endl;
                    cout << STANDARD_CONSOLE;
                }
                break;
            case 2:
                autonomous.demon();
                break;
            case 3:
                autonomous.bench();
                break;
            default:
                cout << "Incorrect option selected!" << endl;
        }
    }
}