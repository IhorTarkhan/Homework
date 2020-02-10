#include "workInConsole/standardUserWork/ConsoleInterface.h"
#include "workInConsole/demoWork/demon.h"
#include "workInConsole/benchmarkWork/bench.h"

int main_Lab_2_1() {
    while (true) {
        cout << "I can propose to you next options:" << endl;
        cout << "0.0. Demo - Memory" << endl;
        cout << "0.1. Demo - Text" << endl;
        cout << "0.2. Demo - Binary" << endl;
        cout << endl;
        cout << "1.0. Memory - save Train" << endl;
        cout << "1.1. Memory - show" << endl;
        cout << "1.2. Memory - clear" << endl;
        cout << "1.3. Memory - delete" << endl;
        cout << "1.4. Memory - change" << endl;
        cout << "1.5. Memory - task1" << endl;
        cout << "1.6. Memory - task2" << endl;
        cout << "1.7. Memory - task3" << endl;
        cout << endl;
        cout << "2.0. Text - save Train" << endl;
        cout << "2.1. Text - show" << endl;
        cout << "2.2. Text - clear" << endl;
        cout << "2.3. Text - delete" << endl;
        cout << "2.4. Text - change" << endl;
        cout << "2.5. Text - task1" << endl;
        cout << "2.6. Text - task2" << endl;
        cout << "2.7. Text - task3" << endl;
        cout << "2.8. Text - save TO memory" << endl;
        cout << "2.9. Text - get FROM memory" << endl;
        cout << endl;
        cout << "3.0. Binary - save Train" << endl;
        cout << "3.1. Binary - show" << endl;
        cout << "3.2. Binary - clear" << endl;
        cout << "3.3. Binary - delete" << endl;
        cout << "3.4. Binary - change" << endl;
        cout << "3.5. Binary - task1" << endl;
        cout << "3.6. Binary - task2" << endl;
        cout << "3.7. Binary - task3" << endl;
        cout << "3.8. Binary - save TO memory" << endl;
        cout << "3.9. Binary - get FROM memory" << endl;
        cout << endl;
        cout << "4.0. Benchmark - Memory" << endl;
        cout << "4.1. Benchmark - Text" << endl;
        cout << "4.2. Benchmark - Binary" << endl;

        int n1;
        int n2;
        cin >> n1;
        switch (n1) {
            case 0:
                cin >> n2;
                switch (n2) {
                    case 0:
                        demon<MemoryDatabase>();
                        break;
                    case 1:
                        demon<TextDatabase>();
                        break;
                    case 2:
                        demon<BinaryDatabase>();
                        break;
                    default:
                        cout << "\u001B[31m" << "INCORRECT OPTION" << "\u001B[0m" << endl;
                }
                break;
            case 1:
                cin >> n2;
                switch (n2) {
                    case 0:
                        saveTrain<MemoryDatabase>();
                        break;
                    case 1:
                        printTrains<MemoryDatabase>();
                        break;
                    case 2:
                        clearTrains<MemoryDatabase>();
                        break;
                    case 3:
                        deleteTrain<MemoryDatabase>();
                        break;
                    case 4:
                        changeTrain<MemoryDatabase>();
                        break;
                    case 5:
                        task1<MemoryDatabase>();
                        break;
                    case 6:
                        task2<MemoryDatabase>();
                        break;
                    case 7:
                        task3<MemoryDatabase>();
                        break;
                    default:
                        cout << "\u001B[31m" << "INCORRECT OPTION" << "\u001B[0m" << endl;
                }
                break;
            case 2:
                cin >> n2;
                switch (n2) {
                    case 0:
                        saveTrain<TextDatabase>();
                        break;
                    case 1:
                        printTrains<TextDatabase>();
                        break;
                    case 2:
                        clearTrains<TextDatabase>();
                        break;
                    case 3:
                        deleteTrain<TextDatabase>();
                        break;
                    case 4:
                        changeTrain<TextDatabase>();
                        break;
                    case 5:
                        task1<TextDatabase>();
                        break;
                    case 6:
                        task2<TextDatabase>();
                        break;
                    case 7:
                        task3<TextDatabase>();
                        break;
                    case 8:
                        TextDatabase::saveItToMemory();
                        break;
                    case 9:
                        TextDatabase::saveMemoryToIt();
                        break;
                    default:
                        cout << "\u001B[31m" << "INCORRECT OPTION" << "\u001B[0m" << endl;
                }
                break;
            case 3:
                cin >> n2;
                switch (n2) {
                    case 0:
                        saveTrain<BinaryDatabase>();
                        break;
                    case 1:
                        printTrains<BinaryDatabase>();
                        break;
                    case 2:
                        clearTrains<BinaryDatabase>();
                        break;
                    case 3:
                        deleteTrain<BinaryDatabase>();
                        break;
                    case 4:
                        changeTrain<BinaryDatabase>();
                        break;
                    case 5:
                        task1<BinaryDatabase>();
                        break;
                    case 6:
                        task2<BinaryDatabase>();
                        break;
                    case 7:
                        task3<BinaryDatabase>();
                        break;
                    case 8:
                        BinaryDatabase::saveItToMemory();
                        break;
                    case 9:
                        BinaryDatabase::saveMemoryToIt();
                        break;
                    default:
                        cout << "\u001B[31m" << "INCORRECT OPTION" << "\u001B[0m" << endl;
                }
                break;
            case 4:
                cin >> n2;
                switch (n2) {
                    case 0:
                        bench<MemoryDatabase>();
                        break;
                    case 1:
                        bench<TextDatabase>();
                        break;
                    case 2:
                        bench<BinaryDatabase>();
                        break;
                    default:
                        cout << "\u001B[31m" << "INCORRECT OPTION" << "\u001B[0m" << endl;
                }
                break;
            default:
                cout << "\u001B[31m" << "INCORRECT OPTION" << "\u001B[0m" << endl;
        }
    }
}
