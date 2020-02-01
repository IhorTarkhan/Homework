#include <iostream>
#include "dadaStructures/Train.h"
#include "dadaStructures/SaveToFileCONSTANTS.h"
#include "lib/saveTextFile/addOperations.h"

int main_Lab_2_1() {
    vector<Train> trains;

    Train train1 = Train("0001", "myName", NEARCITY,
                         Date(0, 0, 0, 0, 1900),
                         Date(1, 1, 1, 1, 1991),
                         1.0);
    trains.push_back(train1);

    Train train2 = Train("0020", "yourName", INTERNATIONAL,
                         Date(14, 29, 5, 12, 1804),
                         Date(23, 59, 31, 12, 2019),
                         1.5);
    trains.push_back(train2);

    addVectorToFile("../2ndSemester/LaboratoryWork1/test.txt", trains);
}
