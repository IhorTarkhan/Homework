#pragma once

#include "../../databases/text/functions/Standard.h"
#include "../GetTrain.h"

void saveFromMemoryToText() {
    saveMemoryToText();
}

void saveFromTextToMemory() {
    saveTextToMemory();
}

void saveToText() {
    Train train = getTrainFromConsole();
    saveTrainInText(train);
}

void printText() {
    cout << getTrainsFromText();
}

void clearText() {
    clearTrainsInText();
}

void changeInText() {
    int id = 0;
    cout << getTrainsWithIDFromText();
    cout << "Witch id change?" << endl << "id = ";
    cin >> id;
    Train train = getTrainFromConsole();
    changeInText(id, train);
}

void deleteInText() {
    int id = 0;
    cout << getTrainsWithIDFromText();
    cout << "Witch id delete?" << endl << "id = ";
    cin >> id;
    deleteInText(id);
}
