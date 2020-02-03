#pragma once

#include <fstream>
#include "../../../dataStructures/Train.h"
#include "../Path.h"
#include "../../taskConditions.h"

vector<Train> task1InText(string lastFragmentOfName) {
    vector<Train> res;

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
            if (task1Boolean(train, lastFragmentOfName)) {
                res.push_back(train);
            }
            continue;
        }
    }
    file.close();
    return res;
}

vector<Train> task2InText(Destination destinationRequested, string numberMIN, string numberMAX) {
    vector<Train> res;

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
            if (task2Boolean(train, destinationRequested, numberMIN, numberMAX)) {
                res.push_back(train);
            }
            continue;
        }
    }
    file.close();
    return res;
}

vector<Train> task3InText(Date departureGet) {
    vector<Train> res;

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
            if (task3Boolean(train, departureGet)) {
                res.push_back(train);
            }
            continue;
        }
    }
    file.close();
    return res;
}
