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

    static bool twoFieldCompare(Train train1, Train train2) {
        bool compareResult;
        int (*universalCompare1)(Train, Train)(&CompareOneField::numberCompare);

        if (trainField1 == optionalName) {
            int (*compare)(Train, Train)(CompareOneField::optionalNameCompare);
            universalCompare1 = compare;
        }
        if (trainField1 == destination) {
            int (*compare)(Train, Train)(CompareOneField::destinationCompare);
            universalCompare1 = compare;
        }
        if (trainField1 == arrive) {
            int (*compare)(Train, Train)(CompareOneField::arriveCompare);
            universalCompare1 = compare;
        }
        if (trainField1 == departure) {
            int (*compare)(Train, Train)(CompareOneField::departureCompare);
            universalCompare1 = compare;
        }
        if (trainField1 == rate) {
            int (*compare)(Train, Train)(CompareOneField::rateCompare);
            universalCompare1 = compare;
        }


        int (*universalCompare2)(Train, Train)(&CompareOneField::numberCompare);
        if (trainField2 == optionalName) {
            int (*compare)(Train, Train)(CompareOneField::optionalNameCompare);
            universalCompare2 = compare;
        }
        if (trainField2 == destination) {
            int (*compare)(Train, Train)(CompareOneField::destinationCompare);
            universalCompare2 = compare;
        }
        if (trainField2 == arrive) {
            int (*compare)(Train, Train)(CompareOneField::arriveCompare);
            universalCompare2 = compare;
        }
        if (trainField2 == departure) {
            int (*compare)(Train, Train)(CompareOneField::departureCompare);
            universalCompare2 = compare;
        }
        if (trainField2 == rate) {
            int (*compare)(Train, Train)(CompareOneField::rateCompare);
            universalCompare2 = compare;
        }

        if ((*universalCompare1)(train1, train2) == 0) {
            compareResult = (*universalCompare2)(train1, train2) == 1;
        } else {
            compareResult = (*universalCompare1)(train1, train2) == 1;
        }
        return compareResult;
    }
};

#endif
