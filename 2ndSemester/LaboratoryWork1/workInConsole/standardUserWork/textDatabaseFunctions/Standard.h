#pragma once

#include "../generalFunctions/Standard.h"
#include "../GetTrain.h"
#include "../../../databases/TextDatabase.h"

void saveFromMemoryToText() {
    TextDatabase::saveMemoryToText();
}

void saveFromTextToMemory() {
    TextDatabase::saveTextToMemory();
}

void saveToText() {
    saveTo__(TextDatabase::addTrain, getTrainFromConsole());
}

void printText() {
    print__(TextDatabase::getTrains);
}

void clearText() {
    clear__(TextDatabase::clear);
}

void changeInText() {
    changeIn__(TextDatabase::getTrainsWithID, TextDatabase::change, getTrainFromConsole());
}

void deleteInText() {
    deleteIn__(TextDatabase::getTrainsWithID, TextDatabase::deleteTrain);
}
