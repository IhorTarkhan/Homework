#pragma once

#include <fstream>
#include "../dataStructures/Train.h"

bool task1Boolean(Train train, string lastFragmentOfName) {
    return train.optionalName.substr(train.optionalName.length() - lastFragmentOfName.length()) == lastFragmentOfName;
}

bool task2Boolean(Train train, Destination destinationRequested, string numberMIN, string numberMAX) {
    return train.destination == destinationRequested &&
           (stoi(train.number) >= stoi(numberMIN) && stoi(train.number) <= stoi(numberMAX));
}

bool task3Boolean(Train train, Date departureGet) {
    return (train.departure.year > departureGet.year) ||

           (train.departure.year == departureGet.year && train.departure.month > departureGet.month) ||

           (train.departure.year == departureGet.year && train.departure.month == departureGet.month &&
            train.departure.day > departureGet.day) ||

           (train.departure.year == departureGet.year && train.departure.month == departureGet.month &&
            train.departure.day == departureGet.day && train.departure.hour > departureGet.hour) ||

           (train.departure.year == departureGet.year && train.departure.month == departureGet.month &&
            train.departure.day == departureGet.day && train.departure.hour == departureGet.hour &&
            train.departure.minute > departureGet.minute);
}
