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
    for (int i = 0; i < 10; ++i) {
        optionalName += (rand() % ('z' - 'a') + ((rand() % 2) ? 'a' : 'A'));
    }
    Train train = Train(number, optionalName, destination, arrive, departure, rate);
    return train;
}

void demon() {
    const string RedInConsole = "\u001B[31m";
    const string BlueInConsole = "\u001B[34m";
    const string PurpleInConsole = "\u001B[35m";

    const string YellowInConsole = "\u001B[33m";
    const string StandardConsole = "\u001B[0m";

    Train randomTrain = createRandomTrain();

    cout << RedInConsole + "Save random train in memory ..." + StandardConsole << endl;
    saveTrainInMemory(randomTrain);
    cout << RedInConsole + "Saved" + StandardConsole << endl << endl;

    cout << RedInConsole + "Print from memory ..." + StandardConsole << endl;
    cout << getTrainsFromMemory();
    cout << RedInConsole + "Printed" + StandardConsole << endl << endl;

    cout << RedInConsole + "Deleting from memory ..." + StandardConsole << endl;
    clearTrainsInMemory();
    cout << RedInConsole + "Deleted" + StandardConsole << endl << endl;

    cout << RedInConsole + "Save 5 random trains in memory ..." + StandardConsole << endl;
    randomTrain = createRandomTrain();
    saveTrainInMemory(randomTrain);
    randomTrain = createRandomTrain();
    saveTrainInMemory(randomTrain);
    randomTrain = createRandomTrain();
    saveTrainInMemory(randomTrain);
    randomTrain = createRandomTrain();
    saveTrainInMemory(randomTrain);
    randomTrain = createRandomTrain();
    saveTrainInMemory(randomTrain);
    cout << RedInConsole + "Saved" + StandardConsole << endl << endl;

    cout << RedInConsole + "Print from memory ..." + StandardConsole << endl;
    cout << getTrainsFromMemory();
    cout << RedInConsole + "Printed" + StandardConsole << endl << endl;

    cout << RedInConsole + "Print from memory with ID..." + StandardConsole << endl;
    cout << getTrainsWithIDFromMemory();
    cout << RedInConsole + "Printed with ID" + StandardConsole << endl << endl;


}
