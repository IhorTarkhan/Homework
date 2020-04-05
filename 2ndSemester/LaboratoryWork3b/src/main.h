#include <iostream>
#include "../../LaboratoryWork1/dataStructures/Train.h"
#include "SortsMemoryTrains.h"
#include "Comparator.h"
#include "../../LaboratoryWork1/workInConsole/demoWork/demon.h"

using namespace std;

int main_Lab_2_3b() {
    int n = 200;
    for (int i = 0; i < n; ++i) {
        Train train = createRandomTrain();
        trainsInMemory.push_back(train);
    }

    Comparator::setFields(destination, number);
    SortsMemoryTrains::mergeSort(Comparator::twoFieldCompare);

    for (int i = 0; i < n; ++i) {
        cout << trainsInMemory[i].getInText() << endl;
    }
    return 0;
}
