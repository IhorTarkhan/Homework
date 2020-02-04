#pragma once

#include "../DataInMemory.h"
#include "../../taskConditions.h"

//template <typename Params>
vector<Train> task1InMemory(string lastFragmentOfName) {
    vector<Train> res;
    for (int i = 0; i < trainsInMemory.size(); ++i) {
        string iTrainName = trainsInMemory[i].optionalName;
        if (task1Boolean(trainsInMemory[i], lastFragmentOfName)) {
            res.push_back(trainsInMemory[i]);
        }
    }
    return res;
}

vector<Train> task2InMemory(Destination destinationRequested, string numberMIN, string numberMAX) {
    vector<Train> res;
    for (int i = 0; i < trainsInMemory.size(); ++i) {
        string iTrainName = trainsInMemory[i].optionalName;
        if (task2Boolean(trainsInMemory[i], destinationRequested, numberMIN, numberMAX)) {
            res.push_back(trainsInMemory[i]);
        }
    }
    return res;
}

vector<Train> task3InMemory(Date departureGet) {
    vector<Train> res;
    for (int i = 0; i < trainsInMemory.size(); ++i) {
        string iTrainName = trainsInMemory[i].optionalName;
        if (task3Boolean(trainsInMemory[i], departureGet)) {
            res.push_back(trainsInMemory[i]);
        }
    }
    return res;
}
