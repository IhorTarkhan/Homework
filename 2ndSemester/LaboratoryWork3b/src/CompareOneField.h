#ifndef HOMEWORK_COMPAREONEFIELD_H
#define HOMEWORK_COMPAREONEFIELD_H

#include "../../LaboratoryWork1/dataStructures/Train.h"
#include "../../LaboratoryWork1/databases/MemoryDatabase.h"

class CompareOneField {
private:
    template<typename T>
    static int compare(T i1, T i2) {
        if (i1 == i2)
            return 0;
        if (i1 < i2)
            return 1;
        else
            return -1;
    }

    static int getMinutes(Date date) {
        return (((date.year * 12 + date.month) * 30 + date.day) * 24 + date.hour) * 60 + date.minute;
    }

public:
    static int numberCompare(Train train1, Train train2) {
        int i1 = stoi(train1.number);
        int i2 = stoi(train2.number);
        return compare<int>(i1, i2);
    }

    static int optionalNameCompare(Train train1, Train train2) {
        string i1 = train1.optionalName;
        string i2 = train2.optionalName;
        return compare<string>(i1, i2);
    }

    static int destinationCompare(Train train1, Train train2) {
        string i1 = DestinationMap[train1.destination];
        string i2 = DestinationMap[train2.destination];
        return compare<string>(i1, i2);
    }

    static int arriveCompare(Train train1, Train train2) {
        int i1 = getMinutes(train1.arrive);
        int i2 = getMinutes(train2.arrive);
        return compare<int>(i1, i2);
    }

    static int departureCompare(Train train1, Train train2) {
        int i1 = getMinutes(train1.departure);
        int i2 = getMinutes(train2.departure);
        return compare<int>(i1, i2);
    }

    static int rateCompare(Train train1, Train train2) {
        double i1 = train1.rate;
        double i2 = train2.rate;
        return compare<double >(i1, i2);
    }
};

#endif
