#ifndef HOMEWORK_MODES_H
#define HOMEWORK_OPERATINGMODES_H

#include "Coordinates.h"
#include "Sorts.h"

struct OperatingModes {
private:
    static const int BENCHMARK_ARRAY_SIZE = 1000;
    static const int DEFAULT_VALUE_FOR_COMBINED_SORT = 10;

    static vector<Coordinates> createRandomArray(int size) {
        vector<Coordinates> arr(size);
        vector<int> places(size);
        for (int i = 0; i < size; ++i) {
            places[i] = i;
        }
        for (int i = 0; i < size; ++i) {
            int place = rand() % places.size();
            double coordinate_X = (i + 1) / pow(3, 0.5);
            arr[places[place]] = Coordinates(coordinate_X, coordinate_X, coordinate_X);
            places.erase(places.begin() + place);
        }
        return arr;
    }

    static vector<Coordinates> createAlmostSortedArray(int size) {
        vector<Coordinates> arr(size);
        for (int i = 0; i < size; ++i) {
            int N_i;
            if (i % 2 == 0) {
                N_i = (i + 2);
                if (i + 1 == size) {
                    N_i = (i + 1);
                }
            } else {
                N_i = (i);
            }
            double coordinate_X_Y_Z = N_i / pow(3, 0.5);
            arr[i] = Coordinates(coordinate_X_Y_Z, coordinate_X_Y_Z, coordinate_X_Y_Z);
        }
        return arr;
    }

    static vector<Coordinates> createAlmostSortedInversionArray(int size) {
        vector<Coordinates> arr(size);
        for (int i = 0; i < size; ++i) {
            int N_i;
            if (i % 2 == 0) {
                N_i = (size - i - 1);
                if (i + 1 == size) {
                    N_i = (size - i);
                }
            } else {
                N_i = (size - i + 1);
            }
            double coordinate_X_Y_Z = N_i / pow(3, 0.5);
            arr[i] = Coordinates(coordinate_X_Y_Z, coordinate_X_Y_Z, coordinate_X_Y_Z);
        }
        return arr;
    }

    static void runAllSortsWithParameters(int n, vector<Coordinates> functionOfCreate(int), bool isItDemo) {
        vector<Coordinates> arrayOrigin = functionOfCreate(n);
        vector<Coordinates> array;

        cout << "Array is:" << endl;
        Sorts<Coordinates>::print(arrayOrigin);

        array = arrayOrigin;
        cout << "Insertion Sort" << endl;
        auto start = high_resolution_clock::now();
        Sorts<Coordinates>::insertionSort(array, isItDemo);
        if (!isItDemo) {
            cout << duration_cast<microseconds>(high_resolution_clock::now() - start).count()
                 << " microseconds" << endl;
        }

        array = arrayOrigin;
        cout << "Quicksort" << endl;
        start = high_resolution_clock::now();
        Sorts<Coordinates>::quickSort(array, isItDemo);
        if (!isItDemo) {
            cout << duration_cast<microseconds>(high_resolution_clock::now() - start).count()
                 << " microseconds" << endl;
        }

        array = arrayOrigin;
        cout << "Merge Sort" << endl;
        start = high_resolution_clock::now();
        Sorts<Coordinates>::mergeSort(array, isItDemo);
        if (!isItDemo) {
            cout << duration_cast<microseconds>(high_resolution_clock::now() - start).count()
                 << " microseconds" << endl;
        }

        array = arrayOrigin;
        cout << "Combined Sort" << endl;
        start = high_resolution_clock::now();
        Sorts<Coordinates>::combinedSort(array, DEFAULT_VALUE_FOR_COMBINED_SORT, isItDemo);
        if (!isItDemo) {
            cout << duration_cast<microseconds>(high_resolution_clock::now() - start).count()
                 << " microseconds" << endl;
        }

        array = arrayOrigin;
        cout << "Library Sort" << endl;
        start = high_resolution_clock::now();
        Sorts<Coordinates>::librarySort(array);
        if (!isItDemo) {
            cout << duration_cast<microseconds>(high_resolution_clock::now() - start).count()
                 << " microseconds" << endl;
        }

        cout << endl;
    }

public:
    static void demon(int n) {
        runAllSortsWithParameters(n, createRandomArray, true);
        runAllSortsWithParameters(n, createAlmostSortedArray, true);
        runAllSortsWithParameters(n, createAlmostSortedInversionArray, true);
    }

    static void benchmark() {
        runAllSortsWithParameters(BENCHMARK_ARRAY_SIZE, createRandomArray, false);
        runAllSortsWithParameters(BENCHMARK_ARRAY_SIZE, createAlmostSortedArray, false);
        runAllSortsWithParameters(BENCHMARK_ARRAY_SIZE, createAlmostSortedInversionArray, false);
    }
};

#endif
