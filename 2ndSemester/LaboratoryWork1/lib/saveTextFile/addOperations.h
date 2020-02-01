#ifndef HOMEWORK_ADDOPERATIONS_H
#define HOMEWORK_ADDOPERATIONS_H

#include <fstream>
#include "../../dadaStructures/Train.h"
#include "../../dadaStructures/SaveToFileCONSTANTS.h"

int getMaxID(string path) {
    int maxID = 0;
    string line;
    ifstream file(path);
    while (getline(file, line)) {
        if (line.substr(0, ID.length()) == ID) {
            if (stoi(line.substr(ID.length())) > maxID)
                maxID = stoi(line.substr(ID.length()));
        }
    }
    return maxID;
}

void addToFile(string path, Train train) {
    int maxID = getMaxID(path);
    ofstream file(path, ios_base::app);
    string textToSave = ID + to_string(++maxID) + "\n" + train.getTextToSave() + "\n";
    file << textToSave;
    file.close();
}

void addVectorToFile(string path, vector<Train> trains) {
    int maxID = getMaxID(path);
    ofstream file(path, ios_base::app);
    for (int i = 0; i < trains.size(); i++) {
        string textToSave = ID + to_string(++maxID) + "\n" + trains[i].getTextToSave() + "\n";
        file << textToSave;
    }
    file.close();
}

#endif