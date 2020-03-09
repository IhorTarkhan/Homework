#ifndef HOMEWORK_TASK9_H
#define HOMEWORK_TASK9_H

#include <iostream>
#include <vector>

using namespace std;

enum ZIP_OPTIONS {
    REJECT_TO_SHORT_LENGTH,
    USE_LONGER_AND_REJECT_LAST_IF_ODD_LEFT,
    USE_LONGER_AND_ADD_TO_END_IF_ODD_LEFT,
    USE_LONGER_AND_USE_VALUE_INSTEAD_SHORTER
};

class Task9 {
private:
    vector<int> arr1;
    vector<int> arr2;
    ZIP_OPTIONS option;
    int constValue;

    vector<pair<int, int>> pairs;

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

    vector<int> getMaxLists(vector<int> x, const vector<int> y) {
        if (min(x.size(), y.size()) == x.size()) {
            return x;
        } else {
            return y;
        }
    }

    vector<pair<int, int>> zipWithReject(vector<int> x, vector<int> y) {
        vector<pair<int, int>> pairs;
        int length = min(x.size(), y.size());
        for (int i = 0; i < length; ++i) {
            pairs.emplace_back(x[i], y[i]);
        }
        return pairs;
    }

    void appendToZipUseLongerAndRejectLastIfOddLeft(vector<pair<int, int>> &pairs, vector<int> x, vector<int> y) {
        int minLength = min(x.size(), y.size());
        int maxLength = max(x.size(), y.size());
        vector<int> maxList = getMaxLists(x, y);
        for (int i = minLength; i < maxLength - 1; i += 2) {
            if (i == maxLength - 1) {
                break;
            }
            pairs.emplace_back(maxList[i], maxList[i + 1]);
        }
    }

    void appendToZipUseLongerAndAddToEndIfOddLeft(vector<pair<int, int>> &pairs, vector<int> x, vector<int> y,
                                                  int constantValue) {
        int minLength = min(x.size(), y.size());
        int maxLength = max(x.size(), y.size());
        vector<int> maxList = getMaxLists(x, y);
        for (int i = minLength; i < maxLength - 1; i += 2) {
            if (i == maxLength - 1) {
                pairs.emplace_back(maxList[i], constantValue);
                break;
            }
            pairs.emplace_back(maxList[i], maxList[i + 1]);
        }
    }

    void appendToZipUseValueInsteadShorter(vector<pair<int, int>> &pairs, vector<int> x, vector<int> y,
                                           int constantValue) {
        int minLength = min(x.size(), y.size());
        int maxLength = max(x.size(), y.size());
        vector<int> maxList = getMaxLists(x, y);
        for (int i = minLength; i < maxLength; ++i) {
            pairs.emplace_back(maxList[i], constantValue);
        }
    }

    vector<pair<int, int>> zipWithOptions(vector<int> x, vector<int> y, ZIP_OPTIONS zipOptions, int constantValue) {
        vector<pair<int, int>> pairs = zipWithReject(x, y);
        switch (zipOptions) {
            case REJECT_TO_SHORT_LENGTH:
                return pairs;
            case USE_LONGER_AND_REJECT_LAST_IF_ODD_LEFT:
                appendToZipUseLongerAndRejectLastIfOddLeft(pairs, x, y);
                return pairs;
            case USE_LONGER_AND_ADD_TO_END_IF_ODD_LEFT:
                appendToZipUseLongerAndAddToEndIfOddLeft(pairs, x, y, constantValue);
                return pairs;
            case USE_LONGER_AND_USE_VALUE_INSTEAD_SHORTER:
                appendToZipUseValueInsteadShorter(pairs, x, y, constantValue);
                return pairs;
            default:
                break;
        }
        return pairs;
    }

    vector<int> getArrayFromConsole() {
        vector<int> arr;
        const string END_STRING = "end.";
        string numberInString;
        int i = 0;
        while (numberInString != END_STRING) {
            cout << "Enter array and in the end enter \"" + END_STRING + "\":" << endl;
            cout << "#" << i + 1 << ": ";
            cin >> numberInString;
            if (!isInt(numberInString)) {
                cout << "Incorrect string!" << endl;
            } else {
                arr.push_back(stoi(numberInString));
                numberInString = "";
                ++i;
            }
        }
        return arr;
    }

    ZIP_OPTIONS getOptionFromConsole() {
        string numberInString;
        while (true) {
            cout << "Next options are available: " << endl;
            cout << "1 - REJECT_TO_SHORT_LENGTH," << endl;
            cout << "2 - USE_LONGER_AND_REJECT_LAST_IF_ODD_LEFT," << endl;
            cout << "3 - USE_LONGER_AND_ADD_TO_END_IF_ODD_LEFT," << endl;
            cout << "4 - USE_LONGER_AND_USE_VALUE_INSTEAD_SHORTER." << endl;
            cout << "Select number: ";
            cin >> numberInString;
            switch (stoi(numberInString)) {
                case 1:
                    return REJECT_TO_SHORT_LENGTH;
                case 2:
                    return USE_LONGER_AND_REJECT_LAST_IF_ODD_LEFT;
                case 3:
                    return USE_LONGER_AND_ADD_TO_END_IF_ODD_LEFT;
                case 4:
                    return USE_LONGER_AND_USE_VALUE_INSTEAD_SHORTER;
                default:
                    cout << "Incorrect number selected!" << endl;
                    break;
            }
        }
    }

    int getConstValueFromConsole() {
        string numberInString;
        do {
            cout << "Enter number: ";
            cin >> numberInString;

        } while (!isInt(numberInString));
        return stoi(numberInString);
    }

    void printPairs(vector<pair<int, int>> pairs) {
        for (int i = 0; i < pairs.size(); ++i) {
            cout << pairs[i].first << ", " << pairs[i].second << endl;
        }
    }

public:
    void run() {
        cout << "Enter array 1" << endl;
        arr1 = getArrayFromConsole();
        cout << "Enter array 2" << endl;
        arr2 = getArrayFromConsole();
        cout << "Enter option" << endl;
        option = getOptionFromConsole();
        cout << "Enter const value" << endl;
        cout << "(if your option does not imply const value," << endl;
        cout << "please enter something)" << endl;
        constValue = getConstValueFromConsole();

        pairs = zipWithOptions(arr1, arr2, option, constValue);
        cout << "Printing pairs:" << endl;
        printPairs(pairs);
    }

    void demon() {}
};

#endif
