#pragma once

#include <iostream>
#include <fstream>
#include "taskConditions.h"
#include "MemoryDatabase.h"

using namespace std;

class TextDatabase {
private:
    constexpr static const char *PATH = "../2ndSemester/LaboratoryWork1/DataBase_txt.txt";
    constexpr static const char *newPATH = "../2ndSemester/LaboratoryWork1/DataBase_txt.txt.new.txt";

    static void extractTrain(Train &train, string line) {
        if (line.substr(0, NUMBER.length()) == NUMBER) {
            line = line.substr(NUMBER.length());
            train.number = line;
        }
        if (line.substr(0, OPTIONAL_NAME.length()) == OPTIONAL_NAME) {
            line = line.substr(OPTIONAL_NAME.length());
            train.optionalName = line;
        }
        if (line.substr(0, DESTINATION.length()) == DESTINATION) {
            line = line.substr(DESTINATION.length());
            for (int i = 0; i < DestinationMap.size(); ++i) {
                if (line == DestinationMap[i]) {
                    train.destination = DestinationList[i];
                    break;
                }
            }
        }
        if (line.substr(0, ARRIVE.length()) == ARRIVE) {
            line = line.substr(ARRIVE.length());
            train.arrive.hour = stoi(line.substr(0, line.find_first_of(":")));
            line = line.substr(line.find_first_of(":") + 1);

            train.arrive.minute = stoi(line.substr(0, line.find_first_of(" ")));
            line = line.substr(line.find_first_of(" ") + 1);

            train.arrive.day = stoi(line.substr(0, line.find_first_of("/")));
            line = line.substr(line.find_first_of("/") + 1);

            train.arrive.month = stoi(line.substr(0, line.find_first_of("/")));
            line = line.substr(line.find_first_of("/") + 1);

            train.arrive.year = stoi(line);

        }
        if (line.substr(0, DEPARTURE.length()) == DEPARTURE) {
            line = line.substr(DEPARTURE.length());
            train.departure.hour = stoi(line.substr(0, line.find_first_of(":")));
            line = line.substr(line.find_first_of(":") + 1);

            train.departure.minute = stoi(line.substr(0, line.find_first_of(" ")));
            line = line.substr(line.find_first_of(" ") + 1);

            train.departure.day = stoi(line.substr(0, line.find_first_of("/")));
            line = line.substr(line.find_first_of("/") + 1);

            train.departure.month = stoi(line.substr(0, line.find_first_of("/")));
            line = line.substr(line.find_first_of("/") + 1);

            train.departure.year = stoi(line);
        }
        if (line.substr(0, RATE.length()) == RATE) {
            line = line.substr(RATE.length());
            train.rate = stod(line);
        }
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
        vector<Train> res;

        Train train;
        ifstream file(TextDatabase::PATH);
        string line;
        while (getline(file, line)) {
            extractTrain(train, line);
            if (line.substr(0, RATE.length()) == RATE) {
                trainsInMemory.push_back(train);
            }
        }
        file.close();
    }

    static int getMaxID() {
        int maxID = 0;
        string line;
        ifstream file(TextDatabase::PATH);
        while (getline(file, line)) {
            if (line.substr(0, ID.length()) == ID) {
                if (stoi(line.substr(ID.length())) > maxID)
                    maxID = stoi(line.substr(ID.length()));
            }
        }
        return maxID;
    }

    static void saveTrain(Train train) {
        int maxID = getMaxID();
        ofstream file(TextDatabase::PATH, ios_base::app);
        string textToSave = "";
        textToSave += ID + to_string(++maxID) + "\n" + train.getInText() + "\n";
        file << textToSave;
        file.close();
    }

    static string getTrains() {
        string trainsInString = "";
        ifstream file(TextDatabase::PATH);
        string line;
        while (getline(file, line)) {
            if (line.substr(0, ID.length()) != ID) {
                trainsInString += line + "\n";
            }
        }
        file.close();
        return trainsInString;
    }

    static void clearTrains() {
        ofstream file(TextDatabase::PATH);
        file << "";
        file.close();
    }

    static string getTrainsWithID() {
        string trainsInString = "";
        ifstream file(TextDatabase::PATH);
        string line;
        while (getline(file, line)) {
            trainsInString += line + "\n";
        }
        file.close();
        return trainsInString;
    }

    static void changeTrain(int id, Train train) {
        if (id <= 0 || id > getMaxID()) {
            throw invalid_argument("incorrect id");
        }
        ifstream file(TextDatabase::PATH);
        ofstream newFile(TextDatabase::newPATH);
        string line;
        bool ignoreLines = false;
        while (getline(file, line)) {
            if (line.substr(0, ID.length()) == ID) {
                newFile << line << endl;
                if (stoi(line.substr(ID.length())) == id) {
                    ignoreLines = true;
                    newFile << train.getInText() << endl;
                } else {
                    ignoreLines = false;
                }
            } else if (!ignoreLines) {
                newFile << line << endl;
            }
        }
        file.close();
        newFile.close();
        remove(TextDatabase::PATH);
        rename(TextDatabase::newPATH, TextDatabase::PATH);
    }

    static void deleteTrain(int id) {
        if (id <= 0 || id > getMaxID()) {
            throw invalid_argument("incorrect id");
        }
        ifstream file(TextDatabase::PATH);
        ofstream newFile(TextDatabase::newPATH);
        string line;
        bool ignoreLines = false;
        while (getline(file, line)) {
            if (line.substr(0, ID.length()) == ID) {
                if (stoi(line.substr(ID.length())) == id) {
                    ignoreLines = true;
                } else {
                    newFile << line << endl;
                    ignoreLines = false;
                }
            } else if (!ignoreLines) {
                newFile << line << endl;
            }
        }
        file.close();
        newFile.close();
        remove(TextDatabase::PATH);
        rename(TextDatabase::newPATH, TextDatabase::PATH);
    }

    static size_t getSize() {
        ifstream in(TextDatabase::PATH, std::ifstream::ate | std::ifstream::binary);
        size_t size = in.tellg();
        in.close();
        return size;
    }

    static vector<Train> task1(string lastFragmentOfName) {
        vector<Train> res;

        Train train;
        ifstream file(TextDatabase::PATH);
        string line;
        while (getline(file, line)) {
            extractTrain(train, line);
            if (line.substr(0, RATE.length()) == RATE) {
                if (task1Boolean(train, lastFragmentOfName)) {
                    res.push_back(train);
                }
            }
        }
        file.close();
        return res;
    }

    static vector<Train> task2(Destination destinationRequested, string numberMIN, string numberMAX) {
        vector<Train> res;

        Train train;
        ifstream file(TextDatabase::PATH);
        string line;
        while (getline(file, line)) {
            extractTrain(train, line);
            if (line.substr(0, RATE.length()) == RATE){
                if (task2Boolean(train, destinationRequested, numberMIN, numberMAX)) {
                    res.push_back(train);
                }
            }
        }
        file.close();
        return res;
    }

    static vector<Train> task3(Date departureGet) {
        vector<Train> res;

        Train train;
        ifstream file(TextDatabase::PATH);
        string line;
        while (getline(file, line)) {
            extractTrain(train, line);
            if (line.substr(0, RATE.length()) == RATE) {
                if (task3Boolean(train, departureGet)) {
                    res.push_back(train);
                }
            }
        }
        file.close();
        return res;
    }
};
