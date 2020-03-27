#include <iostream>
#include "OperatingModes.h"

using namespace std;

int main_Lab_2_3a() {
    while (true) {
        cout << "Menu:" << endl;
        cout << "1 - demo;" << endl;
        cout << "2 - benchmark." << endl;
        cout << "Your choice: ";
        int choiceValue;
        cin >> choiceValue;
        switch (choiceValue) {
            case 1:
                int n;
                do {
                    cout << "\t" << "Enter size: ";
                    cin >> n;
                    if (n <= 0) {
                        cout << "\t" << "Incorrect size" << endl;
                    }
                } while (n <= 0);
                OperatingModes::demon(n);
                break;
            case 2:
                OperatingModes::benchmark();
                break;
            default:
                cout << "Incorrect option selected!" << endl;
        }
    }
}
