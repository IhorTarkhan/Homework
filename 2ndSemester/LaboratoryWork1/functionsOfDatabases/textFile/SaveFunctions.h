#pragma once

#include <fstream>
#include "../../dadaStructures/Train.h"
#include "../memory/DataInMemory.h"
#include "Constants.h"

int getMaxID() {
    int maxID = 0;
    string line;
    ifstream file(PATH);
    while (getline(file, line)) {
        if (line.substr(0, ID.length()) == ID) {
            if (stoi(line.substr(ID.length())) > maxID)
                maxID = stoi(line.substr(ID.length()));
        }
    }
    return maxID;
}

void saveTrainToText(Train train) {
    int maxID = getMaxID();
    ofstream file(PATH, ios_base::app);
    string textToSave = "";
    textToSave += ID + to_string(++maxID) + "\n" + train.getInText() + "\n";
    file << textToSave;
    file.close();
}

void saveMemoryToText() {
    int maxID = getMaxID();
    string textToSave = "";
    ofstream file(PATH, ios_base::app);
    for (int i = 0; i < trainsInMemory.size(); i++) {
        textToSave += ID + to_string(++maxID) + "\n" + trainsInMemory[i].getInText() + "\n";
    }
    file << textToSave;
    file.close();
}
