#pragma once

#include <iostream>
#include <fstream>
#include <map>
#include "taskConditions.h"
#include "MemoryDatabase.h"

using namespace std;

class BinaryDatabase {
private:
    constexpr static const char *PATH = "../2ndSemester/LaboratoryWork1/DataBase_bin.bin";
    constexpr static const char *newPATH = "../2ndSemester/LaboratoryWork1/DataBase_bin.bin.new.bin";

    static void saveToFileTrainWithID(ofstream &fileNew, const Train &train, int trainID) {
        fileNew.write((char *) &(trainID), sizeof(trainID));

        size_t numberSize = train.number.size();
        fileNew.write((char *) &numberSize, sizeof(numberSize));
        const char *numberBuffer = train.number.c_str();
        fileNew.write(numberBuffer, numberSize);

        size_t nameSize = train.optionalName.size();
        fileNew.write((char *) &nameSize, sizeof(nameSize));
        const char *nameBuffer = train.optionalName.c_str();
        fileNew.write(nameBuffer, nameSize);

        fileNew.write((char *) &(train.destination), sizeof(train.destination));


        fileNew.write((char *) &(train.arrive.hour), sizeof(train.arrive.hour));
        fileNew.write((char *) &(train.arrive.minute), sizeof(train.arrive.minute));
        fileNew.write((char *) &(train.arrive.day), sizeof(train.arrive.day));
        fileNew.write((char *) &(train.arrive.month), sizeof(train.arrive.month));
        fileNew.write((char *) &(train.arrive.year), sizeof(train.arrive.year));

        fileNew.write((char *) &(train.departure.hour), sizeof(train.departure.hour));
        fileNew.write((char *) &(train.departure.minute), sizeof(train.departure.minute));
        fileNew.write((char *) &(train.departure.day), sizeof(train.departure.day));
        fileNew.write((char *) &(train.departure.month), sizeof(train.departure.month));
        fileNew.write((char *) &(train.departure.year), sizeof(train.departure.year));


        fileNew.write((char *) &(train.rate), sizeof(train.rate));
    }

    static int extractID(ifstream &file) {
        int trainID;
        file.read((char *) &(trainID), sizeof(trainID));
        return trainID;
    }

    static Train extractTrain(ifstream &file) {
        Train iterTrain;
        size_t numberSize;
        file.read((char *) &numberSize, sizeof(numberSize));
        char *numberBuffer = new char[numberSize + 1];
        file.read(numberBuffer, numberSize);
        numberBuffer[numberSize] = '\0';
        iterTrain.number = numberBuffer;

        size_t nameSize;
        file.read((char *) &nameSize, sizeof(nameSize));
        char *nameBuffer = new char[nameSize + 1];
        file.read(nameBuffer, nameSize);
        nameBuffer[nameSize] = '\0';
        iterTrain.optionalName = nameBuffer;

        file.read((char *) &(iterTrain.destination), sizeof(iterTrain.destination));


        file.read((char *) &(iterTrain.arrive.hour), sizeof(iterTrain.arrive.hour));
        file.read((char *) &(iterTrain.arrive.minute), sizeof(iterTrain.arrive.minute));
        file.read((char *) &(iterTrain.arrive.day), sizeof(iterTrain.arrive.day));
        file.read((char *) &(iterTrain.arrive.month), sizeof(iterTrain.arrive.month));
        file.read((char *) &(iterTrain.arrive.year), sizeof(iterTrain.arrive.year));

        file.read((char *) &(iterTrain.departure.hour), sizeof(iterTrain.departure.hour));
        file.read((char *) &(iterTrain.departure.minute), sizeof(iterTrain.departure.minute));
        file.read((char *) &(iterTrain.departure.day), sizeof(iterTrain.departure.day));
        file.read((char *) &(iterTrain.departure.month), sizeof(iterTrain.departure.month));
        file.read((char *) &(iterTrain.departure.year), sizeof(iterTrain.departure.year));


        file.read((char *) &(iterTrain.rate), sizeof(iterTrain.rate));
        return iterTrain;
    }

public:
    static void saveMemoryToIt() {
        clearTrains();
        for (int i = 0; i < trainsInMemory.size(); i++) {
            saveTrain(trainsInMemory[i]);
        }
    }

    static void saveItToMemory() {
        MemoryDatabase::clearTrains();

        ifstream file(BinaryDatabase::PATH, ios_base::binary);

        while (!file.eof()) {
            int trainID = extractID(file);
            if (file.eof()) { break; }
            Train iterTrain = extractTrain(file);

            trainsInMemory.push_back(iterTrain);
        }
        file.close();
    }

    static int getMaxID() {
        int maxID = 0;
        ifstream file(BinaryDatabase::PATH, ios_base::binary);

        while (!file.eof()) {
            int trainID = extractID(file);
            if (file.eof()) { break; }
            Train iterTrain = extractTrain(file);

            if (trainID > maxID) {
                maxID = trainID;
            }
        }
        file.close();
        return maxID;
    }

    static void saveTrain(Train train) {
        int maxID = getMaxID();
        ofstream file(BinaryDatabase::PATH, ios_base::app | ios_base::binary);
        saveToFileTrainWithID(file, train, ++maxID);
        file.close();
    }

    static string getTrains() {
        vector<Train> trains;
        ifstream file(BinaryDatabase::PATH, ios_base::binary);
        string trainsInString = "";

        while (!file.eof()) {
            int trainID = extractID(file);
            if (file.eof()) { break; }
            Train iterTrain = extractTrain(file);

            trains.push_back(iterTrain);
            trainsInString += iterTrain.getInText() + "\n";
        }
        file.close();
        return trainsInString;
    }

    static void clearTrains() {
        ofstream file(PATH);
        file.close();
    }

    static string getTrainsWithID() {
        map<int, Train> trains;
        ifstream file(BinaryDatabase::PATH, ios_base::binary);
        string trainsInString = "";

        while (!file.eof()) {
            int trainID = extractID(file);
            if (file.eof()) { break; }
            Train iterTrain = extractTrain(file);

            trains.insert(pair<int, Train>(trainID, iterTrain));
            trainsInString += ID + to_string(trainID) + "\n";
            trainsInString += iterTrain.getInText() + "\n";
        }
        file.close();
        return trainsInString;
    }

    static void changeTrain(int id, Train train) {
        ifstream file(BinaryDatabase::PATH, ios_base::binary);
        ofstream fileNew(BinaryDatabase::newPATH, ios_base::app | ios_base::binary);

        while (!file.eof()) {
            int trainID = extractID(file);
            if (file.eof()) { break; }
            Train iterTrain = extractTrain(file);

            if (trainID == id) {
                saveToFileTrainWithID(fileNew, train, trainID);
            } else {
                saveToFileTrainWithID(fileNew, iterTrain, trainID);
            }
        }

        file.close();
        fileNew.close();
        remove(BinaryDatabase::PATH);
        rename(BinaryDatabase::newPATH, BinaryDatabase::PATH);
    }

    static void deleteTrain(int id) {
        ifstream file(BinaryDatabase::PATH, ios_base::binary);
        ofstream fileNew(BinaryDatabase::newPATH, ios_base::app | ios_base::binary);

        while (!file.eof()) {
            int trainID = extractID(file);
            if (file.eof()) { break; }
            Train iterTrain = extractTrain(file);

            if (trainID != id) {
                saveToFileTrainWithID(fileNew, iterTrain, trainID);
            }
        }

        file.close();
        fileNew.close();
        remove(BinaryDatabase::PATH);
        rename(BinaryDatabase::newPATH, BinaryDatabase::PATH);
    }

    static size_t getSize() {
        ifstream in(BinaryDatabase::PATH, std::ifstream::ate | std::ifstream::binary);
        size_t size = in.tellg();
        in.close();
        return size;
    }

    static vector<Train> task1(string lastFragmentOfName) {
        vector<Train> result;
        ifstream file(BinaryDatabase::PATH, ios_base::binary);

        while (!file.eof()) {
            int trainID = extractID(file);
            if (file.eof()) { break; }
            Train iterTrain = extractTrain(file);

            if (task1Boolean(iterTrain, lastFragmentOfName)) {
                result.push_back(iterTrain);
            }
        }
        file.close();
        return result;
    }

    static vector<Train> task2(Destination destinationRequested, string numberMIN, string numberMAX) {
        vector<Train> result;
        ifstream file(BinaryDatabase::PATH, ios_base::binary);

        while (!file.eof()) {
            int trainID = extractID(file);
            if (file.eof()) { break; }
            Train iterTrain = extractTrain(file);

            if (task2Boolean(iterTrain, destinationRequested, numberMIN, numberMAX)) {
                result.push_back(iterTrain);
            }
        }
        file.close();
        return result;
    }

    static vector<Train> task3(Date departureGet) {
        vector<Train> result;
        ifstream file(BinaryDatabase::PATH, ios_base::binary);

        while (!file.eof()) {
            int trainID = extractID(file);
            if (file.eof()) { break; }
            Train iterTrain = extractTrain(file);

            if (task3Boolean(iterTrain, departureGet)) {
                result.push_back(iterTrain);
            }
        }
        file.close();
        return result;
    }
};
