#ifndef HOMEWORK_DATABASE_H
#define HOMEWORK_DATABASE_H

#include <iostream>
#include <fstream>
#include "../dadaStructures/Train.h"
#include "../dadaStructures/SaveToFileCONSTANTS.h"

static int maxID = 0;

void addToFile(string path, Train train) {
    ofstream file(path);
    file << ID << maxID++ << " ";
    file << NUMBER << train.number << " ";
    file << OPTIONAL_NAME << train.optionalName << " ";
    file << DESTINATION<< train.destination << " ";
    file << ARRIVE << train.arrive.toString() << " ";
    file << DEPARTURE << train.departure.toString() << " ";
    file << RATE << train.rate << " ";
    file.close();
}

#endif