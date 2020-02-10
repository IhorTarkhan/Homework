#pragma once

#include "../../databases/MemoryDatabase.h"
#include "../../databases/TextDatabase.h"
#include "../../databases/BinaryDatabase.h"
#include "../../dataStructures/Train.h"
#include "../demoWork/demon.h"

#include <chrono>

using namespace std::chrono;

template<typename Database>
static void createAndFindingIn_N_Elements(long N) {
    for (int i = 0; i < N; ++i) {
        Database::saveTrain(createRandomTrain());
    }
    Database::task1("a");
    Database::task2(FAST, "3000", "6000");
    Database::task3(Date(1, 1, 1, 1, 2000));
}

template<typename Database>
static void bench() {
    ofstream file("../2ndSemester/LaboratoryWork1/Bench.txt", ios_base::app);
    time_t end_time = chrono::system_clock::to_time_t(chrono::system_clock::now());
    file << ctime(&end_time) << endl;
    if (typeid(Database) == typeid(MemoryDatabase)) {
        file << "Memory" << endl;
    }
    if (typeid(Database) == typeid(TextDatabase)) {
        file << "Text" << endl;
    }
    if (typeid(Database) == typeid(BinaryDatabase)) {
        file << "Binary" << endl;
    }
    Database::clearTrains();
    long N = 10;
    long N_10 = 10;
    size_t size;
    auto start = high_resolution_clock::now();
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<milliseconds>(stop - start);

    while (duration.count() < 1000) {
        start = high_resolution_clock::now();

        createAndFindingIn_N_Elements<Database>(N);
        size = Database::getSize();
        Database::clearTrains();

        stop = high_resolution_clock::now();
        duration = duration_cast<milliseconds>(stop - start);

        cout << "N = " << to_string(N) << " elements" << "\t" << "\t"
             << "size = " << size << " bites" << "\t" << "\t"
             << "time = " << duration.count() << " ms" << endl;

        file << "N = " << to_string(N) << " elements" << "\t" << "\t"
             << "size = " << size << " bites" << "\t" << "\t"
             << "time = " << duration.count() << " ms" << endl;

        N *= 2;
    }

    N_10 = N / 4;
    N = N / 2 + N_10;

    while (duration.count() < 10000) {
        start = high_resolution_clock::now();

        createAndFindingIn_N_Elements<Database>(N);
        size = Database::getSize();
        Database::clearTrains();

        stop = high_resolution_clock::now();
        duration = duration_cast<milliseconds>(stop - start);

        cout << "N = " << to_string(N) << " elements" << "\t" << "\t"
             << "size = " << size << " bites" << "\t" << "\t"
             << "time = " << duration.count() << " ms" << endl;

        file << "N = " << to_string(N) << " elements" << "\t" << "\t"
             << "size = " << size << " bites" << "\t" << "\t"
             << "time = " << duration.count() << " ms" << endl;

        N += N_10;
    }
    file << endl;
    file.close();
}
