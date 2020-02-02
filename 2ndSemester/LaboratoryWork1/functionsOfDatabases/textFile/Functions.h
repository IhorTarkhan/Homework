#pragma once

#include <fstream>
#include "../../dadaStructures/Train.h"
#include "../memory/DataInMemory.h"
#include "Constants.h"

int getMaxID() {
    int maxID = 0;
    string line;
    ifstream file(PATH);
    while (getline(file, line)) {
        if (line.substr(0, ID.length()) == ID) {
            if (stoi(line.substr(ID.length())) > maxID)
                maxID = stoi(line.substr(ID.length()));
        }
    }
    return maxID;
}

void saveMemoryToText() {
    int maxID = getMaxID();
    string textToSave = "";
    ofstream file(PATH, ios_base::app);
    for (int i = 0; i < trainsInMemory.size(); i++) {
        textToSave += ID + to_string(++maxID) + "\n" + trainsInMemory[i].getInText() + "\n";
    }
    file << textToSave;
    file.close();
}

void saveTextToMemory() {
    string number;
    string optionalName;
    Destination destination;
    string arriveHourString;
    string arriveMinuteString;
    string arriveDayString;
    string arriveMonthString;
    string arriveYearString;
    string departureHourString;
    string departureMinuteString;
    string departureDayString;
    string departureMonthString;
    string departureYearString;
    string rateString;
    Date arrive = Date(1, 1, 1, 1, 1);
    Date departure = Date(1, 1, 1, 1, 1);

    ifstream file(PATH);
    string line;
    while (getline(file, line)) {
        if (line.substr(0, NUMBER.length()) == NUMBER) {
            line = line.substr(NUMBER.length());
            number = line;
            continue;
        }
        if (line.substr(0, OPTIONAL_NAME.length()) == OPTIONAL_NAME) {
            line = line.substr(OPTIONAL_NAME.length());
            optionalName = line;
            continue;
        }
        if (line.substr(0, DESTINATION.length()) == DESTINATION) {
            line = line.substr(DESTINATION.length());
            for (int i = 0; i < DestinationMap.size(); ++i) {
                if (line == DestinationMap[i]) {
                    destination = DestinationList[i];
                    break;
                }
            }
            continue;
        }
        if (line.substr(0, ARRIVE.length()) == ARRIVE) {
            line = line.substr(ARRIVE.length());
            arriveHourString = line.substr(0, line.find_first_of(":"));
            line = line.substr(line.find_first_of(":") + 1);

            arriveMinuteString = line.substr(0, line.find_first_of(" "));
            line = line.substr(line.find_first_of(" ") + 1);

            arriveDayString = line.substr(0, line.find_first_of("/"));
            line = line.substr(line.find_first_of("/") + 1);

            arriveMonthString = line.substr(0, line.find_first_of("/"));
            line = line.substr(line.find_first_of("/") + 1);

            arriveYearString = line;

            arrive = Date(stoi(arriveHourString), stoi(arriveMinuteString),
                          stoi(arriveDayString), stoi(arriveMonthString), stoi(arriveMonthString));
            continue;
        }
        if (line.substr(0, DEPARTURE.length()) == DEPARTURE) {
            line = line.substr(DEPARTURE.length());
            departureHourString = line.substr(0, line.find_first_of(":"));
            line = line.substr(line.find_first_of(":") + 1);

            departureMinuteString = line.substr(0, line.find_first_of(" "));
            line = line.substr(line.find_first_of(" ") + 1);

            departureDayString = line.substr(0, line.find_first_of("/"));
            line = line.substr(line.find_first_of("/") + 1);

            departureMonthString = line.substr(0, line.find_first_of("/"));
            line = line.substr(line.find_first_of("/") + 1);

            departureYearString = line;

            departure = Date(stoi(departureHourString), stoi(departureMinuteString),
                             stoi(departureDayString), stoi(departureMonthString), stoi(departureMonthString));
            continue;
        }
        if (line.substr(0, RATE.length()) == RATE) {
            line = line.substr(RATE.length());
            rateString = line;
            Train train = Train(number, optionalName, destination, arrive, departure, stod(rateString));
            saveTrainToMemory(train);
            continue;
        }
    }
    file.close();
}

void saveTrainToText(Train train) {
    int maxID = getMaxID();
    ofstream file(PATH, ios_base::app);
    string textToSave = "";
    textToSave += ID + to_string(++maxID) + "\n" + train.getInText() + "\n";
    file << textToSave;
    file.close();
}

void clearTrainsInText() {
    ofstream file(PATH);
    file << "";
    file.close();
}

string getTrainsFromText() {
    string trainsInString = "";
    ifstream file(PATH);
    string line;
    while (getline(file, line)) {
        if (line.substr(0, ID.length()) != ID) {
            trainsInString += line + "\n";
        }
    }
    file.close();
    return trainsInString;
}
