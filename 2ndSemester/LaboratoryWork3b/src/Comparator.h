#ifndef HOMEWORK_COMPARATOR_H
#define HOMEWORK_COMPARATOR_H

#include "TrainFields.h"
#include "../../LaboratoryWork1/dataStructures/Train.h"
#include "CompareOneField.h"
#include <iostream>

using namespace std;

static int numberOfComparableFields;
static TrainFields field1;
static TrainFields field2;

class Comparator {
private:
public:
    static void setField1(TrainFields field) {
        field1 = field;
        numberOfComparableFields = 1;
    }

    static void setField2(TrainFields field1, TrainFields field2) {
        field1 = field1;
        field2 = field2;
        numberOfComparableFields = 2;
    }

    static bool oneFieldCompare(Train train1, Train train2) {
        switch (field1) {
            case number:
                return CompareOneField::numberCompare(train1, train2) == 1;
            case optionalName:
                return CompareOneField::optionalNameCompare(train1, train2) == 1;
            case destination:
                return CompareOneField::destinationCompare(train1, train2) == 1;
            case arrive:
                return CompareOneField::arriveCompare(train1, train2) == 1;
            case departure:
                return CompareOneField::departureCompare(train1, train2) == 1;
            case rate:
                return CompareOneField::rateCompare(train1, train2) == 1;
            default:
                return false;
        }
    }


};

#endif
