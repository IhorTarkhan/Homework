#pragma once

#include "../../../databases/memory/functions/Standard.h"
#include "../generalFunctions/Standard.h"

void saveToMemory() {
    saveTo__(saveTrainInMemory);
}

void printMemory() {
    print__(getTrainsFromMemory);
}

void clearMemory() {
    clear__(clearTrainsInMemory);
}

void changeInMemory() {
    changeIn__(getTrainsWithIDFromMemory, changeTrainInMemory);
}

void deleteInMemory() {
    deleteIn__(getTrainsWithIDFromMemory, deleteTrainInMemory);
}
