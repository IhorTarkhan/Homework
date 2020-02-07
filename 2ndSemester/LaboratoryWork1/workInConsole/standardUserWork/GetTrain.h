#pragma once

#include <iostream>
#include "../../dataStructures/Train.h"

using namespace std;

bool isItInt(string line) {
    for (int i = 0; i < line.size(); ++i)
        if (line[i] < '0' || line[i] > '9')
            return false;
    return true;
}

bool isItDouble(string line) {
    bool wasPoint = false;
    for (int i = 0; i < line.size(); ++i)
        if (line[i] < '0' || line[i] > '9')
            if ((line[i] != '.' && line[i] != ',') || wasPoint)
                return false;
            else
                wasPoint = true;
    return true;
}

Train getTrainFromConsole() {
    string number;
    string optionalName;
    string destinationIntInString;
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
    Date arrive;
    Date departure;

    cout << "Adding in Memory..." << endl;

    do {
        cout << "Number (\"nnnn\"): ";
        cin >> number;
    } while (number.length() != 4 || !isItInt(number));

    cout << "Obtional Name (\"S...s\"): ";
    cin >> optionalName;

    do {
        cout << "Destination: " << endl;
        for (int i = 0; i < DestinationMap.size(); ++i) {
            cout << "\"" << to_string(i + 1) << "\" - " << DestinationMap[i] << endl;
        }
        cout << "Destination: ";
        cin >> destinationIntInString;
    } while (destinationIntInString.length() != 1 ||
             (destinationIntInString[0] <= '0' || destinationIntInString[0] > '4'));
    destination = static_cast<Destination>(stoi(destinationIntInString) - 1);

    while (true) {
        do {
            cout << "Arrive date (\"h m d m y\"): ";
            cin >> arriveHourString >> arriveMinuteString >> arriveDayString >> arriveMonthString
                >> arriveYearString;
        } while (!isItInt(arriveHourString) || !isItInt(arriveMinuteString) || !isItInt(arriveDayString) ||
                 !isItInt(arriveMonthString) || !isItInt(arriveYearString));
        try {
            arrive = Date(stoi(arriveHourString), stoi(arriveMinuteString), stoi(arriveDayString),
                          stoi(arriveMonthString), stoi(arriveYearString));
            break;
        }
        catch (const std::invalid_argument &ia) {
            continue;
        }
    }

    while (true) {
        do {
            cout << "Departure date (\"h m d m y\"): ";
            cin >> departureHourString >> departureMinuteString >> departureDayString >> departureMonthString
                >> departureYearString;
        } while (!isItInt(departureHourString) || !isItInt(departureMinuteString) || !isItInt(departureDayString) ||
                 !isItInt(departureMonthString) || !isItInt(departureYearString));
        try {
            departure = Date(stoi(departureHourString), stoi(departureMinuteString), stoi(departureDayString),
                             stoi(departureMonthString), stoi(departureYearString));
            break;
        }
        catch (const std::invalid_argument &ia) {
            continue;
        }
    }

    do {
        cout << "Rate (\"double\"): ";
        cin >> rateString;
    } while (!isItDouble(rateString));

    Train train = Train(number, optionalName, destination, arrive, departure, stod(rateString));
    return train;
}
