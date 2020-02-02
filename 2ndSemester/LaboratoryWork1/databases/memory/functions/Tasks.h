#pragma once

#include "../DataInMemory.h"

vector<Train> task1InMemory(string lastFragmentOfName) {
    vector<Train> res;
    for (int i = 0; i < trainsInMemory.size(); ++i) {
        string iTrainName = trainsInMemory[i].optionalName;
        if (iTrainName.substr(iTrainName.length() - lastFragmentOfName.length()) == lastFragmentOfName) {
            res.push_back(trainsInMemory[i]);
        }
    }
    return res;
}