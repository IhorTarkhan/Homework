#pragma once

#include <iostream>
#include <fstream>
#include "taskConditions.h"
#include "MemoryDatabase.h"

using namespace std;

class BinaryDatabase {
private:
    constexpr static const char *PATH = "../2ndSemester/LaboratoryWork1/DataBase_bin.bin";
    constexpr static const char *newPATH = "../2ndSemester/LaboratoryWork1/DataBase_bin.bin.new.bin";

public:

    static void refresh_file() {
        ofstream file(PATH);
        file.close();
    }

    static void saveMemoryToIt() {
    }

    static void saveItToMemory() {
    }

    static int getMaxID() {
    }

    static void saveTrain(Train train) {
        ofstream file(BinaryDatabase::PATH, ios_base::app | ios_base::binary);
        size_t size = sizeof(train.number);
        file.write((char *) &train, sizeof(Train));
        cout << train.getInText() << endl;
        file.close();
    }

    static string getTrains() {
        vector<Train> trains;
        ifstream file(BinaryDatabase::PATH, ios_base::binary);
        Train train;
        while (!file.eof()) {
            if (file.eof()) { break; }
            file.read((char *) &train, sizeof(Train));
            if (file.eof()) { break; }
            cout << train.getInText() << endl;
            trains.push_back(train);
        }

        string trainsInString = "";
        for (int i = 0; i < trains.size(); ++i) {
            trainsInString += trains[i].getInText();
        }
        return trainsInString;
    }

    static void clearTrains() {
    }

    static string getTrainsWithID() {
    }

    static void changeTrain(int id, Train train) {
    }

    static void deleteTrain(int id) {
    }

    static vector<Train> task1(string lastFragmentOfName) {
    }

    static vector<Train> task2(Destination destinationRequested, string numberMIN, string numberMAX) {
    }

    static vector<Train> task3(Date departureGet) {
    }
};
