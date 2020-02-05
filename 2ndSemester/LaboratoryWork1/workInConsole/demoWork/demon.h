#pragma once

#include "../../databases/MemoryDatabase.h"
#include "../../databases/TextDatabase.h"
#include "../../databases/BinaryDatabase.h"
#include "../../dataStructures/Train.h"

void pauseDemon() {
    const string YellowInConsole = "\u001B[33m";
    const string StandardConsole = "\u001B[0m";
    cout << YellowInConsole;
    cout << "PAUSE";
    cin.get();
    cout << StandardConsole;
}

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

template<typename Database>
void demon() {
    const string RedInConsole = "\u001B[31m";
    const string BlueInConsole = "\u001B[34m";
    const string PurpleInConsole = "\u001B[35m";

    const string StandardConsole = "\u001B[0m";
    string DatabaseInConsole = "";

    string textDatabase = "";
    if (typeid(Database) == typeid(MemoryDatabase)) {
        textDatabase = "Memory";
        DatabaseInConsole = RedInConsole;
        MemoryDatabase::clearTrains();
    }
    if (typeid(Database) == typeid(TextDatabase)) {
        textDatabase = "Text";
        DatabaseInConsole = BlueInConsole;
        MemoryDatabase::clearTrains();
        Database::clearTrains();
    }
    if (typeid(Database) == typeid(BinaryDatabase)) {
        textDatabase = "Binary";
        DatabaseInConsole = PurpleInConsole;
        MemoryDatabase::clearTrains();
        Database::clearTrains();
    }
    if (typeid(Database) != typeid(MemoryDatabase)) {
        cout << DatabaseInConsole + "Clearing and Saving 4 random trains in Memory ..." + StandardConsole << endl;
        MemoryDatabase::saveTrain(createRandomTrain());
        MemoryDatabase::saveTrain(createRandomTrain());
        MemoryDatabase::saveTrain(createRandomTrain());
        MemoryDatabase::saveTrain(createRandomTrain());
        cout << DatabaseInConsole + "Saved" + StandardConsole << endl << endl;

        //pauseDemon();
        cout << DatabaseInConsole + "Printing from Memory ..." + StandardConsole << endl;
        cout << MemoryDatabase::getTrains();
        cout << DatabaseInConsole + "Printed" + StandardConsole << endl << endl;

        //pauseDemon();
        cout << DatabaseInConsole + "Saving from Memory to " + textDatabase + " ..." + StandardConsole << endl;
        if (typeid(Database) == typeid(TextDatabase)) {
            TextDatabase::saveMemoryToIt();
        }
        if (typeid(Database) == typeid(BinaryDatabase)) {
            // --- BinaryDatabase::saveMemoryToIt();
        }
        cout << DatabaseInConsole + "Saved" + StandardConsole << endl << endl;

        //pauseDemon();
        cout << DatabaseInConsole + "Printing from " + textDatabase + " ..." + StandardConsole << endl;
        cout << Database::getTrains();
        cout << DatabaseInConsole + "Printed" + StandardConsole << endl << endl;
    }

    Train randomTrain = createRandomTrain();
    vector<Train> taskResults;

    //pauseDemon();
    cout << DatabaseInConsole + "Saving random train in " + textDatabase + " ..." + StandardConsole << endl;
    Database::saveTrain(randomTrain);
    cout << DatabaseInConsole + "Saved" + StandardConsole << endl << endl;

    //pauseDemon();
    cout << DatabaseInConsole + "Printing from " + textDatabase + " ..." + StandardConsole << endl;
    cout << Database::getTrains();
    cout << DatabaseInConsole + "Printed" + StandardConsole << endl << endl;

    //pauseDemon();
    cout << DatabaseInConsole + "Deleting from " + textDatabase + " ..." + StandardConsole << endl;
    Database::clearTrains();
    cout << DatabaseInConsole + "Deleted" + StandardConsole << endl << endl;

    //pauseDemon();
    cout << DatabaseInConsole + "Printing from " + textDatabase + " ..." + StandardConsole << endl;
    cout << Database::getTrains();
    cout << DatabaseInConsole + "Printed" + StandardConsole << endl << endl;

    //pauseDemon();
    cout << DatabaseInConsole + "Save 5 random trains in " + textDatabase + " ..." + StandardConsole << endl;
    randomTrain = createRandomTrain();
    Database::saveTrain(randomTrain);
    randomTrain = createRandomTrain();
    Database::saveTrain(randomTrain);
    randomTrain = createRandomTrain();
    Database::saveTrain(randomTrain);
    randomTrain = createRandomTrain();
    Database::saveTrain(randomTrain);
    randomTrain = createRandomTrain();
    Database::saveTrain(randomTrain);
    cout << DatabaseInConsole + "Saved" + StandardConsole << endl << endl;

    //pauseDemon();
    cout << DatabaseInConsole + "Printing from " + textDatabase + " ..." + StandardConsole << endl;
    cout << Database::getTrains();
    cout << DatabaseInConsole + "Printed" + StandardConsole << endl << endl;

    //pauseDemon();
    cout << DatabaseInConsole + "Print from " + textDatabase + " with ID..." + StandardConsole << endl;
    cout << Database::getTrainsWithID();
    cout << DatabaseInConsole + "Printed with ID" + StandardConsole << endl << endl;

    //pauseDemon();
    cout << DatabaseInConsole + "Deleting Train with ID = " + to_string(Database::getMaxID() - 2) + " in " +
            textDatabase + " ..." +
            StandardConsole << endl;
    Database::deleteTrain(Database::getMaxID() - 2);
    cout << DatabaseInConsole + "Deleted" + StandardConsole << endl << endl;

    //pauseDemon();
    cout << DatabaseInConsole + "Print from " + textDatabase + " with ID..." + StandardConsole << endl;
    cout << Database::getTrainsWithID();
    cout << DatabaseInConsole + "Printed with ID" + StandardConsole << endl << endl;

    //pauseDemon();
    cout << DatabaseInConsole + "Changing Train name with ID = " + to_string(Database::getMaxID() - 3) +
            " in " + textDatabase + " ..." +
            StandardConsole << endl;
    randomTrain.optionalName = "normalName";
    Database::changeTrain(Database::getMaxID() - 3, randomTrain);
    cout << DatabaseInConsole + "Changed" + StandardConsole << endl << endl;

    //pauseDemon();
    cout << DatabaseInConsole + "Print from " + textDatabase + " with ID..." + StandardConsole << endl;
    cout << Database::getTrainsWithID();
    cout << DatabaseInConsole + "Printed with ID" + StandardConsole << endl << endl;


    //pauseDemon();
    cout << DatabaseInConsole + "Making Task_1: ..." << endl;
    cout << "Last fragment of name = \"ame\"" << endl << "..." << StandardConsole << endl;
    taskResults = Database::task1("ame");
    cout << DatabaseInConsole + "Results:" + StandardConsole << endl;
    for (int i = 0; i < taskResults.size(); ++i) {
        cout << taskResults[i].getInText() << endl;
    }
    cout << DatabaseInConsole + "Made Task_1" + StandardConsole << endl << endl;


    //pauseDemon();
    cout << DatabaseInConsole + "Preparing to Task_2:" << endl;
    cout << "Train (ID = " << to_string(Database::getMaxID()) << ") set Destination = \"FAST\" and number = \"6666\""
         << StandardConsole << endl;
    randomTrain.destination = FAST;
    randomTrain.number = "6666";
    Database::changeTrain(Database::getMaxID(), randomTrain);
    cout << DatabaseInConsole + "Result:" + StandardConsole << endl;
    cout << Database::getTrainsWithID();
    cout << DatabaseInConsole + "Prepared to Task_2" + StandardConsole << endl << endl;

    //pauseDemon();
    cout << DatabaseInConsole + "Making Task_2: ..." << endl;
    cout << "Destination = \"FAST\" and number range = 6000 - 7000" << endl << "..." << StandardConsole << endl;
    taskResults = Database::task2(FAST, "6000", "7000");
    cout << DatabaseInConsole + "Results:" + StandardConsole << endl;
    for (int i = 0; i < taskResults.size(); ++i) {
        cout << taskResults[i].getInText() << endl;
    }
    cout << DatabaseInConsole + "Made Task_2" + StandardConsole << endl << endl;


    //pauseDemon();
    cout << DatabaseInConsole + "Preparing to Task_3:" << endl;
    cout << "Train (ID = " << to_string(Database::getMaxID()) << ") set Departure = \"20:50 20/6/2000\""
         << StandardConsole << endl;
    randomTrain.departure = Date(20, 50, 20, 6, 2000);
    Database::changeTrain(Database::getMaxID(), randomTrain);
    cout << DatabaseInConsole + "Result:" + StandardConsole << endl;
    cout << Database::getTrainsWithID();
    cout << DatabaseInConsole + "Prepared to Task_3" + StandardConsole << endl << endl;

    //pauseDemon();
    cout << DatabaseInConsole + "Making Task_3: ..." << endl;
    cout << "Departure = \"21:51 21/7/1999\"" << endl << "..." << StandardConsole << endl;
    Date testDate = Date(21, 51, 21, 7, 1999);
    taskResults = Database::task3(testDate);
    cout << DatabaseInConsole + "Results:" + StandardConsole << endl;
    for (int i = 0; i < taskResults.size(); ++i) {
        cout << taskResults[i].getInText() << endl;
    }
    cout << DatabaseInConsole + "Made Task_3" + StandardConsole << endl << endl;

    if (typeid(Database) != typeid(MemoryDatabase)) {
        //pauseDemon();
        cout << DatabaseInConsole + "Clearing Memory ..." + StandardConsole << endl;
        MemoryDatabase::clearTrains();
        cout << DatabaseInConsole + "Cleared" + StandardConsole << endl << endl;

        //pauseDemon();
        cout << DatabaseInConsole + "Printing from Memory ..." + StandardConsole << endl;
        cout << MemoryDatabase::getTrains();
        cout << DatabaseInConsole + "Printed" + StandardConsole << endl << endl;

        //pauseDemon();
        cout << DatabaseInConsole + "Saving from " + textDatabase + " to Memory ..." + StandardConsole << endl;
        if (typeid(Database) == typeid(TextDatabase)) {
            TextDatabase::saveItToMemory();
        }
        if (typeid(Database) == typeid(BinaryDatabase)) {
            // --- BinaryDatabase::saveItToMemory();
        }
        cout << DatabaseInConsole + "Saved" + StandardConsole << endl << endl;

        //pauseDemon();
        cout << DatabaseInConsole + "Printing from Memory ..." + StandardConsole << endl;
        cout << MemoryDatabase::getTrains();
        cout << DatabaseInConsole + "Printed" + StandardConsole << endl;
    }
    cout << DatabaseInConsole + "-----------------------------------------------------------" + StandardConsole << endl;
}
