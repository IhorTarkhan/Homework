#ifndef HOMEWORK_MAIN_H
#define HOMEWORK_MAIN_H

#include "src/Interface_lab_6.h"

int main_Lab_2_6() {
    Interface_lab_6 interface;
    while (true) {
        cout << "Menu:" << endl;
        cout << "1" << " - dialog;" << endl;
        cout << "2" << " - demon;" << endl;
        cout << "3" << " - benchmark." << endl;
        cout << "Your choice: ";
        int choiceValue;
        cin >> choiceValue;
        switch (choiceValue) {
            case 1:
                interface.dialog();
                break;
            case 2:
                cout << interface.demon();
                break;
            case 3:
                interface.benchmark();
                break;
            default:
                cout << "Incorrect option selected!" << endl;
        }
    }
    return 0;
}

#endif
