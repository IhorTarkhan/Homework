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

string getTrainsWithIDFromMemory() {
    string trainsInString = "";
    for (int i = 0; i < trainsInMemory.size(); ++i) {
        trainsInString += ID + to_string(i);
        trainsInString += trainsInMemory[i].getInText() + "\n";
    }
    return trainsInString;
}

void changeInMemory(int id, Train train) {
    if (id < 0 || id >=trainsInMemory.size()){
        throw invalid_argument("incorrect id");
    }
    trainsInMemory[id] = train;
}