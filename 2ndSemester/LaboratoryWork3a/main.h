#include <iostream>
#include "Coordinates.h"
#include "Sorts.h"

using namespace std;

void printArray(vector<Coordinates> array) {
    for (int i = 0; i < array.size(); i++) {
        cout << array[i].getSortValue() << " ";
    }
    cout << endl;
}

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

int main_Lab_2_3a() {
    vector<Coordinates> arr = createRandomArray(10);

    cout << "Given array is" << endl;
    Sorts<Coordinates>::print(arr);
    cout << endl;

    Sorts<Coordinates>::mergeSort(arr);
    cout << endl;

    cout << "Sorted array is" << endl;
    Sorts<Coordinates>::print(arr);
    cout << endl;

    return 0;
}