#pragma once

#include "../generalFunctions/Standard.h"
#include "../GetTrain.h"
#include "../../../databases/MemoryDatabase.h"

void saveToMemory() {
    saveTo__(MemoryDatabase::saveTrainInMemory, getTrainFromConsole());
}

void printMemory() {
    print__(MemoryDatabase::getTrainsFromMemory);
}

void clearMemory() {
    clear__(MemoryDatabase::clearTrainsInMemory);
}

void changeInMemory() {
    changeIn__(MemoryDatabase::getTrainsWithIDFromMemory, MemoryDatabase::changeTrainInMemory, getTrainFromConsole());
}

void deleteInMemory() {
    deleteIn__(MemoryDatabase::getTrainsWithIDFromMemory, MemoryDatabase::deleteTrainInMemory);
}
