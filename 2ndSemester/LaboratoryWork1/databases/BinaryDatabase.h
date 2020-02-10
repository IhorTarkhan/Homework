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

    static void saveMemoryToIt() {
        clearTrains();
        for (int i = 0; i < trainsInMemory.size(); i++) {
            saveTrain(trainsInMemory[i]);
        }
    }

    static void saveItToMemory() {
        MemoryDatabase::clearTrains();
    }

    static int getMaxID() {
        int maxID = 0;
        ifstream file(BinaryDatabase::PATH, ios_base::binary);

        while (!file.eof()) {
            int trainID;
            Train train;

            file.read((char *) &(trainID), sizeof(trainID));
            if (file.eof()) { break; }

            size_t numberSize;
            file.read((char *) &numberSize, sizeof(numberSize));
            char *numberBuffer = new char[numberSize + 1];
            file.read(numberBuffer, numberSize);
            numberBuffer[numberSize] = '\0';
            train.number = numberBuffer;

            size_t nameSize;
            file.read((char *) &nameSize, sizeof(nameSize));
            char *nameBuffer = new char[nameSize + 1];
            file.read(nameBuffer, nameSize);
            nameBuffer[nameSize] = '\0';
            train.optionalName = nameBuffer;

            file.read((char *) &(train.destination), sizeof(train.destination));


            file.read((char *) &(train.arrive.hour), sizeof(train.arrive.hour));
            file.read((char *) &(train.arrive.minute), sizeof(train.arrive.minute));
            file.read((char *) &(train.arrive.day), sizeof(train.arrive.day));
            file.read((char *) &(train.arrive.month), sizeof(train.arrive.month));
            file.read((char *) &(train.arrive.year), sizeof(train.arrive.year));

            file.read((char *) &(train.departure.hour), sizeof(train.departure.hour));
            file.read((char *) &(train.departure.minute), sizeof(train.departure.minute));
            file.read((char *) &(train.departure.day), sizeof(train.departure.day));
            file.read((char *) &(train.departure.month), sizeof(train.departure.month));
            file.read((char *) &(train.departure.year), sizeof(train.departure.year));


            file.read((char *) &(train.rate), sizeof(train.rate));

            if (trainID > maxID) {
                maxID = trainID;
            }
        }
        file.close();
        return maxID;
    }

    static void saveTrain(Train train) {
        int maxID = getMaxID() + 1;
        ofstream file(BinaryDatabase::PATH, ios_base::app | ios_base::binary);

        file.write((char *) &(maxID), sizeof(maxID));

        size_t numberSize = train.number.size();
        file.write((char *) &numberSize, sizeof(numberSize));
        const char *numberBuffer = train.number.c_str();
        file.write(numberBuffer, numberSize);

        size_t nameSize = train.optionalName.size();
        file.write((char *) &nameSize, sizeof(nameSize));
        const char *nameBuffer = train.optionalName.c_str();
        file.write(nameBuffer, nameSize);

        file.write((char *) &(train.destination), sizeof(train.destination));


        file.write((char *) &(train.arrive.hour), sizeof(train.arrive.hour));
        file.write((char *) &(train.arrive.minute), sizeof(train.arrive.minute));
        file.write((char *) &(train.arrive.day), sizeof(train.arrive.day));
        file.write((char *) &(train.arrive.month), sizeof(train.arrive.month));
        file.write((char *) &(train.arrive.year), sizeof(train.arrive.year));

        file.write((char *) &(train.departure.hour), sizeof(train.departure.hour));
        file.write((char *) &(train.departure.minute), sizeof(train.departure.minute));
        file.write((char *) &(train.departure.day), sizeof(train.departure.day));
        file.write((char *) &(train.departure.month), sizeof(train.departure.month));
        file.write((char *) &(train.departure.year), sizeof(train.departure.year));


        file.write((char *) &(train.rate), sizeof(train.rate));

        file.close();
    }

    static string getTrains() {
        vector<Train> trains;
        ifstream file(BinaryDatabase::PATH, ios_base::binary);
        string trainsInString = "";

        while (!file.eof()) {
            int trainID;
            Train train;

            file.read((char *) &(trainID), sizeof(trainID));
            if (file.eof()) { break; }

            size_t numberSize;
            file.read((char *) &numberSize, sizeof(numberSize));
            char *numberBuffer = new char[numberSize + 1];
            file.read(numberBuffer, numberSize);
            numberBuffer[numberSize] = '\0';
            train.number = numberBuffer;

            size_t nameSize;
            file.read((char *) &nameSize, sizeof(nameSize));
            char *nameBuffer = new char[nameSize + 1];
            file.read(nameBuffer, nameSize);
            nameBuffer[nameSize] = '\0';
            train.optionalName = nameBuffer;

            file.read((char *) &(train.destination), sizeof(train.destination));


            file.read((char *) &(train.arrive.hour), sizeof(train.arrive.hour));
            file.read((char *) &(train.arrive.minute), sizeof(train.arrive.minute));
            file.read((char *) &(train.arrive.day), sizeof(train.arrive.day));
            file.read((char *) &(train.arrive.month), sizeof(train.arrive.month));
            file.read((char *) &(train.arrive.year), sizeof(train.arrive.year));

            file.read((char *) &(train.departure.hour), sizeof(train.departure.hour));
            file.read((char *) &(train.departure.minute), sizeof(train.departure.minute));
            file.read((char *) &(train.departure.day), sizeof(train.departure.day));
            file.read((char *) &(train.departure.month), sizeof(train.departure.month));
            file.read((char *) &(train.departure.year), sizeof(train.departure.year));


            file.read((char *) &(train.rate), sizeof(train.rate));

            trains.push_back(train);
            trainsInString += train.getInText() + "\n";
        }
        file.close();
        return trainsInString;
    }

    static void clearTrains() {
        ofstream file(PATH);
        file.close();
    }

    static string getTrainsWithID() {
        vector<Train> trains;
        ifstream file(BinaryDatabase::PATH, ios_base::binary);
        string trainsInString = "";

        while (!file.eof()) {
            int trainID;
            Train train;

            file.read((char *) &(trainID), sizeof(trainID));
            if (file.eof()) { break; }

            size_t numberSize;
            file.read((char *) &numberSize, sizeof(numberSize));
            char *numberBuffer = new char[numberSize + 1];
            file.read(numberBuffer, numberSize);
            numberBuffer[numberSize] = '\0';
            train.number = numberBuffer;

            size_t nameSize;
            file.read((char *) &nameSize, sizeof(nameSize));
            char *nameBuffer = new char[nameSize + 1];
            file.read(nameBuffer, nameSize);
            nameBuffer[nameSize] = '\0';
            train.optionalName = nameBuffer;

            file.read((char *) &(train.destination), sizeof(train.destination));


            file.read((char *) &(train.arrive.hour), sizeof(train.arrive.hour));
            file.read((char *) &(train.arrive.minute), sizeof(train.arrive.minute));
            file.read((char *) &(train.arrive.day), sizeof(train.arrive.day));
            file.read((char *) &(train.arrive.month), sizeof(train.arrive.month));
            file.read((char *) &(train.arrive.year), sizeof(train.arrive.year));

            file.read((char *) &(train.departure.hour), sizeof(train.departure.hour));
            file.read((char *) &(train.departure.minute), sizeof(train.departure.minute));
            file.read((char *) &(train.departure.day), sizeof(train.departure.day));
            file.read((char *) &(train.departure.month), sizeof(train.departure.month));
            file.read((char *) &(train.departure.year), sizeof(train.departure.year));


            file.read((char *) &(train.rate), sizeof(train.rate));

            trains.push_back(train);
            trainsInString += ID + to_string(trainID) + "\n";
            trainsInString += train.getInText() + "\n";
        }
        file.close();
        return trainsInString;
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
