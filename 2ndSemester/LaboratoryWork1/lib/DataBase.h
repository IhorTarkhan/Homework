#ifndef HOMEWORK_DATABASE_H
#define HOMEWORK_DATABASE_H

#include <fstream>
#include "../dadaStructures/Train.h"
#include "../dadaStructures/SaveToFileCONSTANTS.h"

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
    file << ID << ++maxID << endl;
    file << NUMBER << train.number << endl;
    file << OPTIONAL_NAME << train.optionalName << endl;
    file << DESTINATION << train.destination << endl;
    file << ARRIVE << train.arrive.toString() << endl;
    file << DEPARTURE << train.departure.toString() << endl;
    file << RATE << train.rate << endl;
    file << endl;
    file.close();
}

void addVectorToFile(string path, vector<Train> trains) {
    for (int i = 0; i < trains.size(); i++) {
        addToFile(path, trains[i]);
    }
}

#endif