#pragma once

#include "../../../databases/memory/functions/Standard.h"
#include "../generalFunctions/Standard.h"
#include "../GetTrain.h"

void saveToMemory() {
    saveTo__(saveTrainInMemory, getTrainFromConsole());
}

void printMemory() {
    print__(getTrainsFromMemory);
}

void clearMemory() {
    clear__(clearTrainsInMemory);
}

void changeInMemory() {
    changeIn__(getTrainsWithIDFromMemory, changeTrainInMemory, getTrainFromConsole());
}

void deleteInMemory() {
    deleteIn__(getTrainsWithIDFromMemory, deleteTrainInMemory);
}
