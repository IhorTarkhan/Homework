#pragma once

#include "Date.h"
#include "DestinationENUM.h"
#include "../saveTo/textFile/Constants.h"

class Train {
public:
    string number;
    string optionalName;
    Destination destination;
    Date arrive = Date(0, 0, 0, 0, 1804);
    Date departure = Date(0, 0, 0, 0, 1804);
    double rate;

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
        string textToSave = NUMBER + this->number + "\n" +
                            OPTIONAL_NAME + this->optionalName + "\n" +
                            DESTINATION + DestinationMap[this->destination] + "\n" +
                            ARRIVE + this->arrive.getInText() + "\n" +
                            DEPARTURE + this->departure.getInText() + "\n" +
                            RATE + to_string(this->rate) + "\n";
        return textToSave;
    }
};
