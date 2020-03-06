#ifndef HOMEWORK_TASK17_H
#define HOMEWORK_TASK17_H

#include <iostream>
#include <vector>

using namespace std;

class Task17 {
private:
    vector<int> circle;
    vector<int> KK;

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

    void writeInCircle(int N) {
        for (int i = 0; i < N; ++i) {
            circle.push_back(i + 1);
        }
    }

    void getKKFromConsole() {
        const string END_STRING = "end.";
        string numberInString;
        for (int i = 0; numberInString != END_STRING; ++i) {
            cout << "Enter KK array and in the end enter \"" + END_STRING + "\":" << endl;
            cout << "#" << i + 1 << ": ";
            cin >> numberInString;
            if (!isInt(numberInString)) {
                cout << "Incorrect string!" << endl;
            } else {
                KK.push_back(stoi(numberInString));
                numberInString = "";
            }
        }
    }

public:
    void run() {
        int N = getMaxNumberFromConsole();
        writeInCircle(N);
        getKKFromConsole();
    }
};

#endif
