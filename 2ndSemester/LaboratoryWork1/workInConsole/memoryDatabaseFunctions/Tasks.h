#pragma once

#include <iostream>
#include "../../databases/memory/functions/Tasks.h"

void task1InMemory() {
    string lastFragmentOfName;
    cout << "Last fragment of name: ";
    cin >> lastFragmentOfName;
    vector<Train> task1Result = task1InMemory(lastFragmentOfName);
    for (int i = 0; i < task1Result.size(); ++i) {
        cout << trainsInMemory[i].getInText() << endl;
    }
}
