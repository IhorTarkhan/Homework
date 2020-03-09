#ifndef HOMEWORK_TASK17_H
#define HOMEWORK_TASK17_H

#include <iostream>
#include <vector>

using namespace std;

class Task17 {
private:
    vector<int> circle;
    vector<int> KK;
    vector<int> deleted;
    int givenNumber;
    int givenStepFromLastStep;

    bool isInt(string nString) {    // TODO correct checking IsInt
        int n;
        try {
            n = stoi(nString);
        }
        catch (invalid_argument) {
            return false;
        }
        return to_string(n) == nString;
    }

    void getNumberFromConsole() {
        string numberInString;
        do {
            cout << "Enter number: ";
            cin >> numberInString;

        } while (!isInt(numberInString));
        givenNumber = stoi(numberInString);
    }

    void getStepFromConsole() {
        string numberInString;
        do {
            cout << "Enter step: ";
            cin >> numberInString;

        } while (!isInt(numberInString));
        givenStepFromLastStep = stoi(numberInString);
    }

    int getMaxNumberFromConsole() {
        string numberInString;
        while (!isInt(numberInString)) {
            cout << "Maximum number in circle: ";
            cin >> numberInString;
            if (!isInt(numberInString)) {
                cout << "Incorrect string!" << endl;
            } else {
                break;
            }
        }
        int N;
        N = stoi(numberInString);
        return N;
    }

    void fillInCircle(int N) {
        for (int i = 0; i < N; ++i) {
            circle.push_back(i + 1);
        }
    }

    void getKKFromConsole() {
        const string END_STRING = "end.";
        string numberInString;
        int i = 0;
        while (numberInString != END_STRING) {
            cout << "Enter KK array and in the end enter \"" + END_STRING + "\":" << endl;
            cout << "#" << i + 1 << ": ";
            cin >> numberInString;
            if (!isInt(numberInString)) {
                cout << "Incorrect string!" << endl;
            } else {
                KK.push_back(stoi(numberInString));
                numberInString = "";
                ++i;
            }
        }
    }

    void deleting(int elementKK, int elementCircle) {
        while (circle.size() != 0) {
            elementKK %= KK.size();
            elementCircle = (elementCircle + KK[elementKK]) % circle.size();
            deleted.push_back(circle[elementCircle]);
            circle.erase(circle.begin() + elementCircle);
            deleting(elementKK + 1, elementCircle);
        }
    }

    void printDeletingSteps() {
        cout << "Deleted steps: " << endl;
        for (int i = 0; i < deleted.size(); ++i) {
            cout << "step " << i + 1 << ": " << deleted[i] << endl;
        }
    }

    void printGivenNumberDeleting() {
        for (int i = 0; i < deleted.size(); ++i) {
            if (deleted[i] == givenNumber) {
                cout << givenNumber << " was deleted on " << i + 1 << " step" << endl;
                break;
            }
        }
    }

    void printGivenStepDeleting() {
        cout << "On step " << givenStepFromLastStep << " from last step was deleted number "
             << deleted[deleted.size() - 1 - givenStepFromLastStep] << endl;
    }

public:
    void run() {
        int N = getMaxNumberFromConsole();
        fillInCircle(N);
        getKKFromConsole();
        getNumberFromConsole();
        getStepFromConsole();

        deleting(0, 0);

        printDeletingSteps();
        printGivenNumberDeleting();
        printGivenStepDeleting();
    }

    void demon() {
        fillInCircle(10);
        cout << "Circle: ";
        for (int i = 0; i < circle.size(); ++i) {
            cout << circle[i] << " ";
        }
        cout << endl;

        KK = {rand() % 10, rand() % 10};
        cout << "KK: ";
        for (int i = 0; i < KK.size(); ++i) {
            cout << KK[i] << " ";
        }
        cout << endl;

        givenNumber = rand() % 10;
        cout << "Given number: " << givenNumber << endl;

        givenStepFromLastStep = rand() % 10;
        cout << "Given step from last step: " << givenStepFromLastStep << endl;

        deleting(0, 0);
        printDeletingSteps();
        printGivenNumberDeleting();
        printGivenStepDeleting();
    }
};

#endif
