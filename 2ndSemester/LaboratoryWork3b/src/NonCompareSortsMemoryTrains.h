#ifndef HOMEWORK_NONCOMPARESORTSMEMORYTRAINS_H
#define HOMEWORK_NONCOMPARESORTSMEMORYTRAINS_H

#include "../../LaboratoryWork1/dataStructures/Train.h"
#include "../../LaboratoryWork1/databases/MemoryDatabase.h"

class NonCompareSortsMemoryTrains {
private:
    static Train getMax(vector<Train> &trains, int getSortableValue(Train)) {
        Train max = trains[0];
        for (int i = 1; i < trains.size(); i++) {
            if (getSortableValue(trains[i]) > getSortableValue(max))
                max = trains[i];
        }
        return max;
    }

    static void countingSort(vector<Train> &trains, int getSortableValue(Train)) {
        Train *output = new Train[(int) trains.size()];
        Train max = getMax(trains, getSortableValue);
        int *count = new int[getSortableValue(max) + 1];
        for (int i = 0; i < (getSortableValue(max) + 1); i++) {
            count[i] = 0;
        }
        for (int i = 0; i < (int) trains.size(); i++) {
            count[getSortableValue(trains[i])]++;
        }
        for (int i = 1; i < getSortableValue(max) + 1; i++) {
            count[i] += count[i - 1];
        }
        for (int i = (int) trains.size() - 1; i >= 0; i--) {
            output[count[getSortableValue(trains[i])] - 1] = trains[i];
            count[getSortableValue(trains[i])]--;
        }
        for (int i = 0; i < (int) trains.size(); i++) {
            trains[i] = output[i];
        }
    }

    static int getDestination(Train train) {
        return train.destination;
    }

    static int getUnits(Train train) {
        return train.number[3];
    }

    static int getTens(Train train) {
        return train.number[2];
    }

    static int getHundreds(Train train) {
        return train.number[1];
    }

    static int getThousands(Train train) {
        return train.number[0];
    }

public:
    static void countingSort() {
        countingSort(trainsInMemory, getDestination);
    }

    static void radixSort() {
        countingSort(trainsInMemory, getUnits);
        countingSort(trainsInMemory, getTens);
        countingSort(trainsInMemory, getHundreds);
        countingSort(trainsInMemory, getThousands);
    }
};

#endif
