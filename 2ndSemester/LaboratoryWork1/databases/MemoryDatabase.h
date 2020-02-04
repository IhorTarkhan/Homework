#pragma once

#include "../dataStructures/Train.h"
#include "taskConditions.h"
#include <vector>

// TODO Put trainsInMemory in class
static vector<Train> trainsInMemory;

class MemoryDatabase {
public:

    static int getMaxIDInMemory() {
        return trainsInMemory.size() - 1;
    }

    static void saveTrainInMemory(Train train) {
        trainsInMemory.push_back(train);
    }

    static string getTrainsFromMemory() {
        string trainsInString = "";
        for (int i = 0; i < trainsInMemory.size(); ++i) {
            trainsInString += trainsInMemory[i].getInText() + "\n";
        }
        return trainsInString;
    }

    static void clearTrainsInMemory() {
        trainsInMemory.clear();
    }

    static string getTrainsWithIDFromMemory() {
        string trainsInString = "";
        for (int i = 0; i < trainsInMemory.size(); ++i) {
            trainsInString += ID + to_string(i) + "\n";
            trainsInString += trainsInMemory[i].getInText() + "\n";
        }
        return trainsInString;
    }

    static void changeTrainInMemory(int id, Train train) {
        if (id < 0 || id >= trainsInMemory.size()) {
            throw invalid_argument("incorrect id");
        }
        trainsInMemory[id] = train;
    }

    static void deleteTrainInMemory(int id) {
        if (id < 0 || id >= trainsInMemory.size()) {
            throw invalid_argument("incorrect id");
        }
        vector<Train>::iterator it = trainsInMemory.begin() + id + 1;
        trainsInMemory.erase(it);
    }

    //template <typename Params>
    static vector<Train> task1InMemory(string lastFragmentOfName) {
        vector<Train> res;
        for (int i = 0; i < trainsInMemory.size(); ++i) {
            string iTrainName = trainsInMemory[i].optionalName;
            if (task1Boolean(trainsInMemory[i], lastFragmentOfName)) {
                res.push_back(trainsInMemory[i]);
            }
        }
        return res;
    }

    static vector<Train> task2InMemory(Destination destinationRequested, string numberMIN, string numberMAX) {
        vector<Train> res;
        for (int i = 0; i < trainsInMemory.size(); ++i) {
            string iTrainName = trainsInMemory[i].optionalName;
            if (task2Boolean(trainsInMemory[i], destinationRequested, numberMIN, numberMAX)) {
                res.push_back(trainsInMemory[i]);
            }
        }
        return res;
    }

    static vector<Train> task3InMemory(Date departureGet) {
        vector<Train> res;
        for (int i = 0; i < trainsInMemory.size(); ++i) {
            string iTrainName = trainsInMemory[i].optionalName;
            if (task3Boolean(trainsInMemory[i], departureGet)) {
                res.push_back(trainsInMemory[i]);
            }
        }
        return res;
    }
};
