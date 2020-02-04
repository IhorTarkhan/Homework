#pragma once

#include "../DataInMemory.h"

int getMaxIDInMemory() {
    return trainsInMemory.size() - 1;
}

void saveTrainInMemory(Train train) {
    trainsInMemory.push_back(train);
}

string getTrainsFromMemory() {
    string trainsInString = "";
    for (int i = 0; i < trainsInMemory.size(); ++i) {
        trainsInString += trainsInMemory[i].getInText() + "\n";
    }
    return trainsInString;
}

void clearTrainsInMemory() {
    trainsInMemory.clear();
}

string getTrainsWithIDFromMemory() {
    string trainsInString = "";
    for (int i = 0; i < trainsInMemory.size(); ++i) {
        trainsInString += ID + to_string(i) + "\n";
        trainsInString += trainsInMemory[i].getInText() + "\n";
    }
    return trainsInString;
}

void changeTrainInMemory(int id, Train train) {
    if (id < 0 || id >= trainsInMemory.size()) {
        throw invalid_argument("incorrect id");
    }
    trainsInMemory[id] = train;
}

void deleteTrainInMemory(int id) {
    if (id < 0 || id >= trainsInMemory.size()) {
        throw invalid_argument("incorrect id");
    }
    vector<Train>::iterator it = trainsInMemory.begin() + id + 1;
    trainsInMemory.erase(it);
}
