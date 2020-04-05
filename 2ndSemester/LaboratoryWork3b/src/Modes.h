#ifndef HOMEWORK_MODES_H
#define HOMEWORK_MODES_H

#include "CompareSortsMemoryTrains.h"
#include "NonCompareSortsMemoryTrains.h"
#include "TrainFields.h"
#include "Comparator.h"

class Modes {
private:
    static void prepareDataBase(int n) {
        MemoryDatabase::clearTrains();
        for (int i = 0; i < n; ++i) {
            trainsInMemory.push_back(createRandomTrain());
        }
    }

    static void printDataBase() {
        for (int i = 0; i < trainsInMemory.size(); ++i) {
            cout << trainsInMemory[i].getInText() << endl;
        }
        cout << endl;
    }

public:
    static void demon(int n) {
        const string YellowInConsole = "\u001B[33m";
        const string StandardConsole = "\u001B[0m";
        prepareDataBase(n);
        vector<Train> reserve(trainsInMemory);

        cout << YellowInConsole << "Compare Sorts Memory Trains:" << StandardConsole << endl;

        cout << "Started array:" << endl;
        printDataBase();

        Comparator::setFields(number);
        CompareSortsMemoryTrains::mergeSort(Comparator::oneFieldCompare);
        cout << "Sorted by number:" << endl;
        printDataBase();

        Comparator::setFields(optionalName);
        CompareSortsMemoryTrains::mergeSort(Comparator::oneFieldCompare);
        cout << "Sorted by optional name:" << endl;
        printDataBase();

        Comparator::setFields(destination);
        CompareSortsMemoryTrains::mergeSort(Comparator::oneFieldCompare);
        cout << "Sorted by destination:" << endl;
        printDataBase();

        Comparator::setFields(arrive);
        CompareSortsMemoryTrains::mergeSort(Comparator::oneFieldCompare);
        cout << "Sorted by arrive:" << endl;
        printDataBase();

        Comparator::setFields(departure);
        CompareSortsMemoryTrains::mergeSort(Comparator::oneFieldCompare);
        cout << "Sorted by departure:" << endl;
        printDataBase();

        Comparator::setFields(rate);
        CompareSortsMemoryTrains::mergeSort(Comparator::oneFieldCompare);
        cout << "Sorted by rate:" << endl;
        printDataBase();

        Comparator::setFields(destination, arrive);
        CompareSortsMemoryTrains::mergeSort(Comparator::twoFieldCompare);
        cout << "Sorted by destination and arrive:" << endl;
        printDataBase();

        Comparator::setFields(number, optionalName);
        CompareSortsMemoryTrains::mergeSort(Comparator::twoFieldCompare);
        cout << "Sorted by number and optional name:" << endl;
        printDataBase();

        cout << endl << endl;
        cout << YellowInConsole << "Non-Compare Sorts Memory Trains:" << StandardConsole << endl;

        NonCompareSortsMemoryTrains::countingSort();
        cout << "Counting Sorted by destination:" << endl;
        printDataBase();

        NonCompareSortsMemoryTrains::radixSort();
        cout << "Radix Sorted by number:" << endl;
        printDataBase();
    }

    static void benchmark(int n) {
        prepareDataBase(n);
        vector<Train> reserve(trainsInMemory);
        auto start = high_resolution_clock::now();
        auto stop = high_resolution_clock::now();
        auto duration = duration_cast<milliseconds>(stop - start);
        cout << endl;

        cout << "(Non-Compare) Counting Sorting by destination: ";
        start = high_resolution_clock::now();
        NonCompareSortsMemoryTrains::countingSort();
        stop = high_resolution_clock::now();
        duration = duration_cast<milliseconds>(stop - start);
        cout << duration.count() << " milliseconds" << endl;
        trainsInMemory = reserve;

        cout << "(Compare) by destination                     : ";
        Comparator::setFields(destination);
        start = high_resolution_clock::now();
        CompareSortsMemoryTrains::mergeSort(Comparator::oneFieldCompare);
        stop = high_resolution_clock::now();
        duration = duration_cast<milliseconds>(stop - start);
        cout << duration.count() << " milliseconds" << endl;
        trainsInMemory = reserve;

        cout << "(Compare) by destination and number          : ";
        Comparator::setFields(destination, number);
        start = high_resolution_clock::now();
        CompareSortsMemoryTrains::mergeSort(Comparator::twoFieldCompare);
        stop = high_resolution_clock::now();
        duration = duration_cast<milliseconds>(stop - start);
        cout << duration.count() << " milliseconds" << endl;
        trainsInMemory = reserve;

        cout << "(Compare) by destination and optional name   : ";
        Comparator::setFields(destination, optionalName);
        start = high_resolution_clock::now();
        CompareSortsMemoryTrains::mergeSort(Comparator::twoFieldCompare);
        stop = high_resolution_clock::now();
        duration = duration_cast<milliseconds>(stop - start);
        cout << duration.count() << " milliseconds" << endl;
        trainsInMemory = reserve;

        cout << "(Compare) by destination and arrive          : ";
        Comparator::setFields(destination, arrive);
        start = high_resolution_clock::now();
        CompareSortsMemoryTrains::mergeSort(Comparator::twoFieldCompare);
        stop = high_resolution_clock::now();
        duration = duration_cast<milliseconds>(stop - start);
        cout << duration.count() << " milliseconds" << endl;
        trainsInMemory = reserve;

        cout << "(Compare) by destination and departure       : ";
        Comparator::setFields(destination, departure);
        start = high_resolution_clock::now();
        CompareSortsMemoryTrains::mergeSort(Comparator::twoFieldCompare);
        stop = high_resolution_clock::now();
        duration = duration_cast<milliseconds>(stop - start);
        cout << duration.count() << " milliseconds" << endl;
        trainsInMemory = reserve;

        cout << "(Compare) by destination and rate            : ";
        Comparator::setFields(destination, rate);
        start = high_resolution_clock::now();
        CompareSortsMemoryTrains::mergeSort(Comparator::twoFieldCompare);
        stop = high_resolution_clock::now();
        duration = duration_cast<milliseconds>(stop - start);
        cout << duration.count() << " milliseconds" << endl;
        trainsInMemory = reserve;


        cout << endl;


        cout << "(Non-Compare) Radix Sorting by number   : ";
        start = high_resolution_clock::now();
        NonCompareSortsMemoryTrains::radixSort();
        stop = high_resolution_clock::now();
        duration = duration_cast<milliseconds>(stop - start);
        cout << duration.count() << " milliseconds" << endl;
        trainsInMemory = reserve;

        cout << "(Compare) by number                     : ";
        Comparator::setFields(number);
        start = high_resolution_clock::now();
        CompareSortsMemoryTrains::mergeSort(Comparator::oneFieldCompare);
        stop = high_resolution_clock::now();
        duration = duration_cast<milliseconds>(stop - start);
        cout << duration.count() << " milliseconds" << endl;
        trainsInMemory = reserve;


        cout << "(Compare) by number and optional name   : ";
        Comparator::setFields(number, optionalName);
        start = high_resolution_clock::now();
        CompareSortsMemoryTrains::mergeSort(Comparator::twoFieldCompare);
        stop = high_resolution_clock::now();
        duration = duration_cast<milliseconds>(stop - start);
        cout << duration.count() << " milliseconds" << endl;
        trainsInMemory = reserve;

        cout << "(Compare) by number and destination     : ";
        Comparator::setFields(number, destination);
        start = high_resolution_clock::now();
        CompareSortsMemoryTrains::mergeSort(Comparator::twoFieldCompare);
        stop = high_resolution_clock::now();
        duration = duration_cast<milliseconds>(stop - start);
        cout << duration.count() << " milliseconds" << endl;
        trainsInMemory = reserve;

        cout << "(Compare) by number and arrive          : ";
        Comparator::setFields(number, arrive);
        start = high_resolution_clock::now();
        CompareSortsMemoryTrains::mergeSort(Comparator::twoFieldCompare);
        stop = high_resolution_clock::now();
        duration = duration_cast<milliseconds>(stop - start);
        cout << duration.count() << " milliseconds" << endl;
        trainsInMemory = reserve;

        cout << "(Compare) by number and departure       : ";
        Comparator::setFields(number, departure);
        start = high_resolution_clock::now();
        CompareSortsMemoryTrains::mergeSort(Comparator::twoFieldCompare);
        stop = high_resolution_clock::now();
        duration = duration_cast<milliseconds>(stop - start);
        cout << duration.count() << " milliseconds" << endl;
        trainsInMemory = reserve;

        cout << "(Compare) by number and rate            : ";
        Comparator::setFields(number, rate);
        start = high_resolution_clock::now();
        CompareSortsMemoryTrains::mergeSort(Comparator::twoFieldCompare);
        stop = high_resolution_clock::now();
        duration = duration_cast<milliseconds>(stop - start);
        cout << duration.count() << " milliseconds" << endl;
        cout << endl;
    }
};

#endif
