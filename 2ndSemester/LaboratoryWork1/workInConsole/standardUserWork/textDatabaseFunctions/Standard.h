#pragma once

#include "../../../databases/text/functions/Standard.h"
#include "../generalFunctions/Standard.h"
#include "../GetTrain.h"

void saveFromMemoryToText() {
    saveMemoryToText();
}

void saveFromTextToMemory() {
    saveTextToMemory();
}

void saveToText() {
    saveTo__(saveTrainInText, getTrainFromConsole());
}

void printText() {
    print__(getTrainsFromText);
}

void clearText() {
    clear__(clearTrainsInText);
}

void changeInText() {
    changeIn__(getTrainsWithIDFromText, changeInText, getTrainFromConsole());
}

void deleteInText() {
    deleteIn__(getTrainsWithIDFromText, deleteInText);
}
