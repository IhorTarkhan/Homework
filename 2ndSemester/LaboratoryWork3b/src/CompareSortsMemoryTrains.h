#ifndef HOMEWORK_COMPARESORTSMEMORYTRAINS_H
#define HOMEWORK_COMPARESORTSMEMORYTRAINS_H

#include "../../LaboratoryWork1/dataStructures/Train.h"
#include "../../LaboratoryWork1/databases/MemoryDatabase.h"
#include "CompareOneField.h"

class CompareSortsMemoryTrains {
private:
    static void mergeSort(vector<Train> &left, vector<Train> &right, vector<Train> &bars,
                          bool compare(Train train1, Train train2)) {
        int nL = left.size();
        int nR = right.size();
        int i = 0, j = 0, k = 0;

        while (j < nL && k < nR) {
            if (compare(left[j], right[k])) {
                bars[i] = left[j];
                j++;
            } else {
                bars[i] = right[k];
                k++;
            }
            i++;
        }
        while (j < nL) {
            bars[i] = left[j];
            j++;
            i++;
        }
        while (k < nR) {
            bars[i] = right[k];
            k++;
            i++;
        }
    }

    static void sort(vector<Train> &bar, bool compare(Train train1, Train train2)) {
        if (bar.size() <= 1) return;

        int mid = bar.size() / 2;
        vector<Train> left;
        vector<Train> right;

        for (size_t j = 0; j < mid; j++)
            left.push_back(bar[j]);
        for (size_t j = 0; j < (bar.size()) - mid; j++)
            right.push_back(bar[mid + j]);

        sort(left, compare);
        sort(right, compare);
        mergeSort(left, right, bar, compare);
    }

public:
    static void mergeSort(bool compare(Train train1, Train train2)) {
        sort(trainsInMemory, compare);
    }
};

#endif
