#ifndef HOMEWORK_TASK11_H
#define HOMEWORK_TASK11_H

class Task11 {
private:
    vector<int> lst;
    int begin;
    int new_begin;
    int end;

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

    int getNumberFromConsole(string numberDescription) {
        string numberInString;
        do {
            cout << "Enter " + numberDescription + ": ";
            cin >> numberInString;
        } while (!isInt(numberInString));
        return stoi(numberInString);
    }

    void rotate(vector<int> lst, int begin, int new_begin, int end) {
        if (!(begin < new_begin && new_begin < end)) {
            throw invalid_argument("invalid_argument");
        }

        this->lst = vector<int>(lst.size());

        for (int i = 0; i < lst.size(); ++i) {
            if (i < begin) {
                this->lst[i] = lst[i];
            } else if (i < new_begin) {
                this->lst[i] = lst[new_begin + (i - begin)];
            } else if (i <= end) {
                this->lst[i] = lst[begin + (i - new_begin)];
            } else {
                this->lst[i] = lst[i];
            }
        }
    }

    void printLST() {
        cout << "Lst:" << endl;
        for (int i = 0; i < lst.size(); ++i) {
            cout << lst[i] << " ";
        }
        cout << endl;
    }

public:
    void run() {
        lst = getArrayFromConsole();
        begin = getNumberFromConsole("begin");
        new_begin = getNumberFromConsole("new_begin");
        end = getNumberFromConsole("end");
        rotate(lst, begin, new_begin, end);
        printLST();
    }

    void demon() {
        lst.clear();
        for (int i = 0; i < 15; ++i) {
            lst.push_back(i);
        }
        printLST();
        begin = rand() % 4;
        new_begin = rand() % 4 + begin + 1;
        end = rand() % 4 + new_begin + 1;
        cout << "begin = " << begin << endl;
        cout << "new_begin = " << new_begin << endl;
        cout << "end = " << end << endl;
        rotate(lst, begin, new_begin, end);
        printLST();
    }
};

#endif
