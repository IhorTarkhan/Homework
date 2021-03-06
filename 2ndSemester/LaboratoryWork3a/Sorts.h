#ifndef HOMEWORK_SORTS_H
#define HOMEWORK_SORTS_H

#include <bits/stdc++.h>

template<typename DataStructure>
class Sorts {
public:
    static void print(vector<DataStructure> array) {
        cout << "Sortable values:\t";
        for (int i = 0; i < array.size(); ++i) {
            cout << array[i].getSortValue() << "\t";
        }
        cout << endl;
    }

public:
    static void insertionSort(vector<DataStructure> &array, bool demonstrateSteps) {
        int i, j;
        DataStructure key;
        for (i = 1; i < array.size(); i++) {
            key = array[i];
            j = i - 1;
            while (j >= 0 && array[j].getSortValue() > key.getSortValue()) {
                array[j + 1] = array[j];
                j = j - 1;
            }
            array[j + 1] = key;
            if (demonstrateSteps) {
                print(array);
            }
        }
    }

private:
    static void quickSort(vector<DataStructure> &a, int first, int last, bool demonstrateSteps) {
        DataStructure x = a[first];
        int i = first, j = last;
        do {
            while (a[i].getSortValue() < x.getSortValue()) {
                i++;
            }
            while (a[j].getSortValue() > x.getSortValue()) {
                j--;
            }
            if (i <= j) {
                if (i < j) {
                    swap(a[i], a[j]);
                }
                i++;
                j--;
            }
        } while (i <= j);
        if (demonstrateSteps) {
            print(a);
        }
        if (first < j) {
            quickSort(a, first, j, demonstrateSteps);
        }
        if (last > i) {
            quickSort(a, i, last, demonstrateSteps);
        }
    }

public:
    static void quickSort(vector<DataStructure> &array, bool demonstrateSteps) {
        quickSort(array, 0, array.size() - 1, demonstrateSteps);
    }

private:
    static void merge(vector<DataStructure> &array, int l, int m, int r) {
        int i = 0, j = 0, k = l;
        int n1 = m - l + 1;
        int n2 = r - m;

        vector<DataStructure> L, R;
        L.assign(array.begin() + l, array.begin() + l + n1);
        R.assign(array.begin() + m + 1, array.begin() + m + 1 + n2);

        while (i < n1 && j < n2) {
            if (L[i].getSortValue() <= R[j].getSortValue()) {
                array[k] = L[i];
                i++;
            } else {
                array[k] = R[j];
                j++;
            }
            k++;
        }

        while (i < n1) {
            array[k] = L[i];
            i++;
            k++;
        }

        while (j < n2) {
            array[k] = R[j];
            j++;
            k++;
        }
    }

    static void mergeSort(vector<DataStructure> &array, int l, int r, bool demonstrateSteps) {
        if (l < r) {
            int m = l + (r - l) / 2;
            mergeSort(array, l, m, demonstrateSteps);
            mergeSort(array, m + 1, r, demonstrateSteps);
            merge(array, l, m, r);
            if (demonstrateSteps) {
                print(array);
            }
        }
    }

public:
    static void mergeSort(vector<DataStructure> &array, bool demonstrateSteps) {
        mergeSort(array, 0, array.size() - 1, demonstrateSteps);
    }

private:
    static void combinedSort(vector<DataStructure> &array, int l, int r, int changeSortSize, bool demonstrateSteps) {
        if (l < r) {
            if (array.size() >= changeSortSize) {
                int m = l + (r - l) / 2;
                mergeSort(array, l, m, demonstrateSteps);
                mergeSort(array, m + 1, r, demonstrateSteps);
                merge(array, l, m, r);
            } else {
                insertionSort(array, demonstrateSteps);
            }
            if (demonstrateSteps) {
                print(array);
            }
        }
    }

public:
    static void combinedSort(vector<DataStructure> &array, int changeSortSize, bool demonstrateSteps) {
        combinedSort(array, 0, array.size() - 1, changeSortSize, demonstrateSteps);
    }

private:
    static bool compare(DataStructure i1, DataStructure i2) {
        return (i1.getSortValue() < i2.getSortValue());
    }

public:
    static void librarySort(vector<DataStructure> &array) {

        sort(array.begin(), array.end(), compare);
    }
};

#endif
