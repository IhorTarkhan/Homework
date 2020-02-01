#pragma once

#include <iostream>
#include "functionsOfDatabases/memory/SaveFunctions.h"

using namespace std;

Train getTrainFromConsole() {
    string number;
    string optionalName;
    int destinationInInt;
    Destination destination;
    int arriveHour;
    int arriveMinute;
    int arriveDay;
    int arriveMonth;
    int arriveYear;
    int departureHour;
    int departureMinute;
    int departureDay;
    int departureMonth;
    int departureYear;
    double rate;
    cout << "Adding in Memory..." << endl;
    cout << "Number (\"nnnn\"): ";
    cin >> number;
    cout << "Obtional Name (\"S...s\"): ";
    cin >> optionalName;

    cout << "Destination:" << endl;
    for (int i = 0; i < DestinationMap.size(); i++) {
        cout << "\"" + to_string(i + 1) + "\" - " + DestinationMap[i] << endl;
    }
    cout << "Destination: ";
    cin >> destinationInInt;
    if (destinationInInt <= 0 || destinationInInt > DestinationMap.size())
        throw invalid_argument("incorrect destination");
    destination = static_cast<Destination>(destinationInInt - 1);

    cout << "Arrive date (\"h m d m y\"): ";
    cin >> arriveHour >> arriveMinute >> arriveDay >> arriveMonth >> arriveYear;
    Date arrive = Date(arriveHour, arriveMinute, arriveDay, arriveMonth, arriveYear);

    cout << "Departure date (\"h m d m y\"): ";
    cin >> departureHour >> departureMinute >> departureDay >> departureMonth >> departureYear;
    Date departure = Date(departureHour, departureMinute, departureDay, departureMonth, departureYear);

    cout << "Rate: ";
    cin >> rate;

    Train train = Train(number, optionalName, destination, arrive, departure, rate);

    return train;
}
