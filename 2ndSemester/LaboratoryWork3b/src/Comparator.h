#ifndef HOMEWORK_COMPARATOR_H
#define HOMEWORK_COMPARATOR_H

#include "TrainFields.h"
#include "../../LaboratoryWork1/dataStructures/Train.h"
#include "CompareOneField.h"
#include <iostream>

using namespace std;

// TODO Put next variable in class
static TrainFields trainField1;
static TrainFields trainField2;

class Comparator {
private:
    static bool twoFieldCompare(Train train1, Train train2,
                                int compare1(Train train1, Train train2), int compare2(Train train1, Train train2)) {
        if (compare1(train1, train2) == 0) {
            return compare2(train1, train2) == 1;
        } else {
            return compare1(train1, train2) == 1;
        }
    }

public:
    static void setFields(TrainFields field) {
        trainField1 = field;
    }

    static void setFields(TrainFields field1, TrainFields field2) {
        trainField1 = field1;
        trainField2 = field2;
    }

    static bool oneFieldCompare(Train train1, Train train2) {
        bool compareResult;
        int (*universalCompare)(Train, Train)(&CompareOneField::numberCompare);

        if (trainField1 == optionalName) {
            int (*compare)(Train, Train)(CompareOneField::optionalNameCompare);
            universalCompare = compare;
        }
        if (trainField1 == destination) {
            int (*compare)(Train, Train)(CompareOneField::destinationCompare);
            universalCompare = compare;
        }
        if (trainField1 == arrive) {
            int (*compare)(Train, Train)(CompareOneField::arriveCompare);
            universalCompare = compare;
        }
        if (trainField1 == departure) {
            int (*compare)(Train, Train)(CompareOneField::departureCompare);
            universalCompare = compare;
        }
        if (trainField1 == rate) {
            int (*compare)(Train, Train)(CompareOneField::rateCompare);
            universalCompare = compare;
        }

        compareResult = (*universalCompare)(train1, train2) == 1;
        return compareResult;
    }
};

#endif
