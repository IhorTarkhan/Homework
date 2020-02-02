#pragma once

#include "../DataInMemory.h"

vector<Train> task1InMemory(string lastFragmentOfName) {
    vector<Train> res;
    for (int i = 0; i < trainsInMemory.size(); ++i) {
        string iTrainName = trainsInMemory[i].optionalName;
        if (iTrainName.substr(iTrainName.length() - lastFragmentOfName.length()) == lastFragmentOfName) {
            res.push_back(trainsInMemory[i]);
        }
    }
    return res;
}

vector<Train> task2InMemory(Destination destinationRequested, string numberMIN, string numberMAX) {
    vector<Train> res;
    for (int i = 0; i < trainsInMemory.size(); ++i) {
        string iTrainName = trainsInMemory[i].optionalName;
        if (trainsInMemory[i].destination == destinationRequested &&
            (stoi(trainsInMemory[i].number) >= stoi(numberMIN) && stoi(trainsInMemory[i].number) <= stoi(numberMAX))) {
            res.push_back(trainsInMemory[i]);
        }
    }
    return res;
}

vector<Train> task3InMemory(Date departureGet) {
    vector<Train> res;
    for (int i = 0; i < trainsInMemory.size(); ++i) {
        string iTrainName = trainsInMemory[i].optionalName;
        if ((trainsInMemory[i].departure.year > departureGet.year) ||

            (trainsInMemory[i].departure.year == departureGet.year &&
             trainsInMemory[i].departure.month > departureGet.month) ||

            (trainsInMemory[i].departure.year == departureGet.year &&
             trainsInMemory[i].departure.month == departureGet.month &&
             trainsInMemory[i].departure.day > departureGet.day) ||

            (trainsInMemory[i].departure.year == departureGet.year &&
             trainsInMemory[i].departure.month == departureGet.month &&
             trainsInMemory[i].departure.day == departureGet.day &&
             trainsInMemory[i].departure.hour > departureGet.hour) ||

            (trainsInMemory[i].departure.year == departureGet.year &&
             trainsInMemory[i].departure.month == departureGet.month &&
             trainsInMemory[i].departure.day == departureGet.day &&
             trainsInMemory[i].departure.hour == departureGet.hour &&
             trainsInMemory[i].departure.minute > departureGet.minute)) {
            res.push_back(trainsInMemory[i]);
        }
    }
    return res;
}
