#pragma once

#include "DataInMemory.h"

void saveTrainToMemory(Train train) {
    trainsInMemory.push_back(train);
}

void clearTrainsInMemory() {
    trainsInMemory.clear();
}

string getTrainsFromMemory() {
    string trainsInString = "";
    for (int i = 0; i < trainsInMemory.size(); ++i) {
        trainsInString += trainsInMemory[i].getInText() + "\n";
    }
    return trainsInString;
}
