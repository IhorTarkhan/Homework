#pragma once

#include "../../../databases/text/functions/Standard.h"
#include "../generalFunctions/Standard.h"

void saveFromMemoryToText() {
    saveMemoryToText();
}

void saveFromTextToMemory() {
    saveTextToMemory();
}

void saveToText() {
    saveTo__(saveTrainInText);
}

void printText() {
    print__(getTrainsFromText);
}

void clearText() {
    clear__(clearTrainsInText);
}

void changeInText() {
    changeIn__(getTrainsWithIDFromText, changeInText);
}

void deleteInText() {
    deleteIn__(getTrainsWithIDFromText, deleteInText);
}
