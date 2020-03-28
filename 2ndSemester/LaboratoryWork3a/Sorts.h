#ifndef HOMEWORK_SORTS_H
#define HOMEWORK_SORTS_H

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
        for (i = 1; i < array.size(); i++)
        {
            key = array[i];
            j = i - 1;
            while (j >= 0 && array[j].getSortValue() > key.getSortValue())
            {
                array[j + 1] = array[j];
                j = j - 1;
            }
            array[j + 1] = key;
            if (demonstrateSteps) {
                print(array);
            }
        }
    }

public:
    static void quickSort(vector<DataStructure> &array, bool demonstrateSteps) {
        mergeSort(array, 0, array.size() - 1, demonstrateSteps);
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

public:
    static void combinedSort(vector<DataStructure> &array, bool demonstrateSteps) {
        mergeSort(array, 0, array.size() - 1, demonstrateSteps);
    }

public:
    static void librarySort(vector<DataStructure> &array, bool demonstrateSteps) {
        mergeSort(array, 0, array.size() - 1, demonstrateSteps);
    }
};

#endif
