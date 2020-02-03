#pragma once

#include "../standardUserWork/memoryDatabaseFunctions/Standard.h"
#include "../standardUserWork/memoryDatabaseFunctions/Standard.h"

#include "../standardUserWork/textDatabaseFunctions/Tasks.h"
#include "../standardUserWork/textDatabaseFunctions/Tasks.h"

Train createRandomTrain() {
    string number = to_string(rand() % 10) + to_string(rand() % 10) + to_string(rand() % 10) + to_string(rand() % 10);
    string optionalName = "";
    Destination destination = DestinationList[rand() % 4];
    Date arrive = Date(rand() % 24, rand() % 60, rand() % 31 + 1, rand() % 12 + 1, rand() % 1000 + 1500);
    Date departure = Date(rand() % 24, rand() % 60, rand() % 31 + 1, rand() % 12 + 1, rand() % 1000 + 1500);
    double rate = (rand() % 2000000) / 1000000.0;
    int nameLength = rand() % 10 + 1;
    for (int i = 0; i < nameLength; ++i) {
        optionalName += (rand() % ('z' - 'a') + 'a');
    }
    Train train = Train(number, optionalName, destination, arrive, departure, rate);
    return train;
}

void demo() {

}