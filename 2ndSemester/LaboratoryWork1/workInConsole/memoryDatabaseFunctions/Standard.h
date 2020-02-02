#pragma once

#include "../../databases/memory/functions/Standard.h"
#include "../GetTrain.h"

void saveToMemory() {
    Train train = getTrainFromConsole();
    saveTrainToMemory(train);
}

void printMemory() {
    cout << getTrainsFromMemory();
}

void clearMemory() {
    clearTrainsInMemory();
}

void changeInMemory() {
    int id = 0;
    cout << getTrainsWithIDFromMemory();
    cout << "Witch id change?" << endl << "id = ";
    cin >> id;
    Train train = getTrainFromConsole();
    changeTrainInMemory(id, train);
}

void deleteInMemory() {
    int id = 0;
    cout << getTrainsWithIDFromMemory();
    cout << "Witch id delete?" << endl << "id = ";
    cin >> id;
    deleteTrainInMemory(id);
}
