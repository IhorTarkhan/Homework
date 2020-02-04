#pragma once

#include "../standardUserWork/memoryDatabaseFunctions/Standard.h"
#include "../standardUserWork/memoryDatabaseFunctions/Standard.h"

#include "../standardUserWork/textDatabaseFunctions/Tasks.h"
#include "../standardUserWork/textDatabaseFunctions/Tasks.h"

Train createRandomTrain() {
    string number = to_string(rand() % 10) + to_string(rand() % 10) + to_string(rand() % 10) + to_string(rand() % 10);
    string optionalName = "";
    for (int i = 0; i < 10; ++i) {
        optionalName += (rand() % ('z' - 'a') + ((rand() % 2) ? 'a' : 'A'));
    }
    Destination destination = DestinationList[rand() % 4];
    Date arrive = Date(rand() % 24, rand() % 60, rand() % 31 + 1, rand() % 12 + 1, rand() % 1000 + 1500);
    Date departure = Date(rand() % 24, rand() % 60, rand() % 31 + 1, rand() % 12 + 1, rand() % 1000 + 1500);
    double rate = (rand() % 2000000) / 1000000.0;
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
    vector<Train> taskResults;

    cout << RedInConsole + "Saving random train in memory ..." + StandardConsole << endl;
    saveTrainInMemory(randomTrain);
    cout << RedInConsole + "Saved" + StandardConsole << endl << endl;

    cout << RedInConsole + "Printing from memory ..." + StandardConsole << endl;
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

    cout << RedInConsole + "Printing from memory ..." + StandardConsole << endl;
    cout << getTrainsFromMemory();
    cout << RedInConsole + "Printed" + StandardConsole << endl << endl;

    cout << RedInConsole + "Print from memory with ID..." + StandardConsole << endl;
    cout << getTrainsWithIDFromMemory();
    cout << RedInConsole + "Printed with ID" + StandardConsole << endl << endl;

    cout << RedInConsole + "Deleting Train with ID = " + to_string(getMaxIDInMemory() - 2) + " in memory ..." +
            StandardConsole << endl;
    deleteTrainInMemory(getMaxIDInMemory() - 2);
    cout << RedInConsole + "Deleted" + StandardConsole << endl << endl;

    cout << RedInConsole + "Print from memory with ID..." + StandardConsole << endl;
    cout << getTrainsWithIDFromMemory();
    cout << RedInConsole + "Printed with ID" + StandardConsole << endl << endl;

    cout << RedInConsole + "Changing Train name with ID = " + to_string(getMaxIDInMemory() - 2) + " in memory ..." +
            StandardConsole << endl;
    randomTrain.optionalName = "normalName";
    changeTrainInMemory(getMaxIDInMemory() - 2, randomTrain);
    cout << RedInConsole + "Changed" + StandardConsole << endl << endl;

    cout << RedInConsole + "Print from memory with ID..." + StandardConsole << endl;
    cout << getTrainsWithIDFromMemory();
    cout << RedInConsole + "Printed with ID" + StandardConsole << endl << endl;


    cout << RedInConsole + "Making Task_1: ..." << endl;
    cout << "Last fragment of name = \"ame\"" << endl << "..." << StandardConsole << endl;
    taskResults = task1InMemory("ame");
    cout << RedInConsole + "Results:" + StandardConsole << endl;
    for (int i = 0; i < taskResults.size(); ++i) {
        cout << taskResults[i].getInText() << endl;
    }
    cout << RedInConsole + "Made Task_1" + StandardConsole << endl << endl;


    cout << RedInConsole + "Preparing to Task_2:" << endl;
    cout << "Train (ID = " << to_string(getMaxIDInMemory()) << ") set Destination = \"FAST\" and number = \"6666\""
         << StandardConsole << endl;
    randomTrain.destination = FAST;
    randomTrain.number = "6666";
    changeTrainInMemory(getMaxIDInMemory(), randomTrain);
    cout << RedInConsole + "Result:" + StandardConsole << endl;
    cout << getTrainsWithIDFromMemory();
    cout << RedInConsole + "Prepared to Task_2:" + StandardConsole << endl;

    cout << RedInConsole + "Making Task_2: ..." << endl;
    cout << "Destination = \"FAST\" and number range = 6000 - 7000" << endl << "..." << StandardConsole << endl;
    taskResults = task2InMemory(FAST, "6000", "7000");
    cout << RedInConsole + "Results:" + StandardConsole << endl;
    for (int i = 0; i < taskResults.size(); ++i) {
        cout << taskResults[i].getInText() << endl;
    }
    cout << RedInConsole + "Made Task_2" + StandardConsole << endl << endl;


    cout << RedInConsole + "Preparing to Task_3:" << endl;
    cout << "Train (ID = " << to_string(getMaxIDInMemory()) << ") set Departure = \"20:50 20/6/2000\""
         << StandardConsole << endl;
    randomTrain.departure = Date(20, 50, 20, 6, 2000);
    changeTrainInMemory(getMaxIDInMemory(), randomTrain);
    cout << RedInConsole + "Result:" + StandardConsole << endl;
    cout << getTrainsWithIDFromMemory();
    cout << RedInConsole + "Prepared to Task_3:" + StandardConsole << endl;

    cout << RedInConsole + "Making Task_2: ..." << endl;
    cout << "Departure = \"21:51 21/7/1999\"" << endl << "..." << StandardConsole << endl;
    Date testDate = Date(21, 51, 21, 7, 1999);
    taskResults = task3InMemory(testDate);
    cout << RedInConsole + "Results:" + StandardConsole << endl;
    for (int i = 0; i < taskResults.size(); ++i) {
        cout << taskResults[i].getInText() << endl;
    }
    cout << RedInConsole + "Made Task_3" + StandardConsole << endl << endl;
}
