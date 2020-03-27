#include <iostream>
#include "Coordinates.h"
#include "Sorts.h"

using namespace std;

vector<Coordinates> createRandomArray(int size) {
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

vector<Coordinates> createAlmostSortedArray(int size) {
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

vector<Coordinates> createAlmostSortedInversionArray(int size) {
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

int main_Lab_2_3a() {
    vector<Coordinates> arr = createAlmostSortedInversionArray(11);

    cout << "Given array is" << endl;
    Sorts<Coordinates>::print(arr);
    cout << endl;

    Sorts<Coordinates>::mergeSort(arr, false);
    cout << endl;

    cout << "Sorted array is" << endl;
    Sorts<Coordinates>::print(arr);
    cout << endl;

    return 0;
}