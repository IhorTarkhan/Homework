#pragma once

#include "Date.h"
#include "DestinationENUM.h"
#include "Constants.h"

class Train {
public:
    string number;
    string optionalName;
    Destination destination;
    Date arrive;
    Date departure;
    double rate;

    Train() = default;

    Train(string number, string optionalName, Destination destination, Date arrive, Date departure, double rate) {
        if (number.length() != 4) {
            throw invalid_argument("incorrect Train number");
        }

        for (int i = 0; i < number.length(); i++) {
            if (number[i] < '0' || number[i] > '9') {
                throw invalid_argument("incorrect Train number");
            }
        }

        this->number = number;
        this->optionalName = optionalName;
        this->destination = destination;
        this->arrive = arrive;
        this->departure = departure;
        this->rate = rate;
    }

    string getInText() {
        string textToSave = NUMBER + number + "\n" +
                            OPTIONAL_NAME + optionalName + "\n" +
                            DESTINATION + DestinationMap[destination] + "\n" +
                            ARRIVE + arrive.getInText() + "\n" +
                            DEPARTURE + departure.getInText() + "\n" +
                            RATE + to_string(rate) + "\n";
        return textToSave;
    }
};
