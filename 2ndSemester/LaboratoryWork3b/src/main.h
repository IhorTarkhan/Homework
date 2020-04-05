#include "CompareSortsMemoryTrains.h"
#include "NonCompareSortsMemoryTrains.h"

int main_Lab_2_3b() {
    int n = 200;
    for (int i = 0; i < n; ++i) {
        Train train = createRandomTrain();
        trainsInMemory.push_back(train);
    }

//    Comparator::setFields(destination, number);
//    CompareSortsMemoryTrains::mergeSort(Comparator::twoFieldCompare);
    NonCompareSortsMemoryTrains::radixSort();

    for (int i = 0; i < n; ++i) {
        cout << trainsInMemory[i].getInText() << endl;
    }
    return 0;
}
