#include "Modes.h"

int getPositiveNFromConsole() {
    int n;
    do {
        cout << "\t" << "Enter size: ";
        cin >> n;
        if (n <= 0) {
            cout << "\t" << "Incorrect size" << endl;
        }
    } while (n <= 0);
    return n;
}

int main_Lab_2_3b() {
    int n;
    while (true) {
        cout << "Menu:" << endl;
        cout << "1 - demo;" << endl;
        cout << "2 - benchmark." << endl;
        cout << "Your choice: ";
        int choiceValue;
        cin >> choiceValue;
        switch (choiceValue) {
            case 1:
                n = getPositiveNFromConsole();
                Modes::demon(n);
                break;
            case 2:
                n = getPositiveNFromConsole();
                Modes::benchmark(n);
                break;
            default:
                cout << "Incorrect option selected!" << endl;
        }
    }
//    Comparator::setFields(destination, number);
//    CompareSortsMemoryTrains::mergeSort(Comparator::twoFieldCompare);
    NonCompareSortsMemoryTrains::radixSort();

    for (int i = 0; i < n; ++i) {
        cout << trainsInMemory[i].getInText() << endl;
    }
    return 0;
}
