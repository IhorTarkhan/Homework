#ifndef HOMEWORK_AUTONOMOUS_H
#define HOMEWORK_AUTONOMOUS_H

#include "../Data/Position.h"
#include <math.h>

using namespace std;

class Autonomous {
private:
    ArrayQueue *arrayQueue;
    const int arrayQueueSize = 3;
    VectorQueue *vectorQueue;
    LinkedQueue *linkedQueue;

    const int numberOfBenchmarkObjects = 1000;

    const string _1ST_IN_CONSOLE = "\u001B[30m";            /// WHITE
    const string _2ND_IN_CONSOLE = "\u001B[34m";            /// BLUE
    const string _3RD_IN_CONSOLE = "\u001B[35m";            /// VIOLET

    const string EXCEPTION_IN_CONSOLE = "\u001B[31m";       /// READ
    const string MESSAGE_IN_CONSOLE = "\u001B[33m";         /// YELLOW

    Position createRandomPosition() {
        const double max = 30;
        const double min = -30;
        const int accuracy = 6;

        Position position;
        position.x = (rand() % (int) ((max - min) * pow(10, accuracy))) / pow(10, accuracy) + min;
        position.y = (rand() % (int) ((max - min) * pow(10, accuracy))) / pow(10, accuracy) + min;
        position.z = (rand() % (int) ((max - min) * pow(10, accuracy))) / pow(10, accuracy) + min;
        return position;
    }

    string getPositionInString(Position position) {
        return to_string(position.x) + "; " + to_string(position.y) + "; " + to_string(position.z);
    }

    void demo_create_empty(VirtualQueue *queue, string colorInConsole) {
        cout << colorInConsole;
        cout << "\t" << "\t"
             << "Try to use function \"create_empty\" (for array size by default = " + to_string(arrayQueueSize) + ")" +
                "..." << endl;
        try {
            queue->create_empty(arrayQueueSize);
            cout << "\t" << "\t" << "Complete!" << endl;
        } catch (const char *msg) {
            cout << EXCEPTION_IN_CONSOLE;
            cout << "\t" << "\t" << "\t" << msg << endl;
            cout << colorInConsole;
        }
        cout << endl;
    }

    void demo_enqueue(VirtualQueue *queue, string colorInConsole) {
        try {
            cout << colorInConsole;
            cout << "\t" << "\t" << "Try to use function \"enqueue( <random position> )\" ..." << endl;
            Position position = createRandomPosition();
            cout << MESSAGE_IN_CONSOLE;
            cout << "\t" << "\t" << "\t" << "Position = " << getPositionInString(position) << endl;
            cout << colorInConsole;

            queue->enqueue(position);
            cout << "\t" << "\t" << "Complete!" << endl;
        } catch (const char *msg) {
            cout << EXCEPTION_IN_CONSOLE;
            cout << "\t" << "\t" << "\t" << msg << endl;
            cout << colorInConsole;
        }
        cout << endl;
    }

    void demo_dequeue(VirtualQueue *queue, string colorInConsole) {
        cout << colorInConsole;
        cout << "\t" << "\t" << "Try to use function \"dequeue()\" ..." << endl;
        try {
            queue->dequeue();
            cout << "\t" << "\t" << "Complete!" << endl;
        } catch (const char *msg) {
            cout << EXCEPTION_IN_CONSOLE;
            cout << "\t" << "\t" << "\t" << msg << endl;
            cout << colorInConsole;
        }
        cout << endl;
    }

    void demo_is_empty(VirtualQueue *queue, string colorInConsole) {
        cout << colorInConsole;
        cout << "\t" << "\t" << "Try to use function \"is_empty()\" ..." << endl;
        try {
            cout << MESSAGE_IN_CONSOLE;
            bool isEmpty = queue->is_empty();
            cout << "\t" << "\t" << "\t" << ((isEmpty) ? "TRUE" : "FALSE") << endl;
            cout << colorInConsole;
            cout << "\t" << "\t" << "Complete!" << endl;
        } catch (const char *msg) {
            cout << EXCEPTION_IN_CONSOLE;
            cout << "\t" << "\t" << "\t" << msg << endl;
            cout << colorInConsole;
        }
        cout << endl;
    }

    void standardDemo(VirtualQueue *queue, string colorInConsole) {
        demo_enqueue(queue, colorInConsole);
        demo_dequeue(queue, colorInConsole);
        demo_is_empty(queue, colorInConsole);

        demo_create_empty(queue, colorInConsole);
        demo_create_empty(queue, colorInConsole);

        demo_is_empty(queue, colorInConsole);

        demo_enqueue(queue, colorInConsole);
        demo_is_empty(queue, colorInConsole);

        demo_dequeue(queue, colorInConsole);
        demo_is_empty(queue, colorInConsole);
    }

    void additionalDemoForArray(string colorInConsole) {
        cout << colorInConsole;
        cout << "\t" << "\t" << "Clear Array-Queue or create new one, if it don't existed:" << endl;
        try {
            arrayQueue->create_empty(arrayQueueSize);
        } catch (...) {}
        while (!arrayQueue->is_empty()) {
            arrayQueue->dequeue();
        }
        cout << "\t" << "\t" << "Done!" << endl << endl;

        cout << "\t" << "\t" << "Now Array-Queue size = " << arrayQueueSize << endl;
        cout << "\t" << "\t" << "And Array-Queue is empty." << endl << endl;

        for (int i = 0; i < arrayQueueSize + 2; ++i) {
            cout << "\t" << "\t" << "#" << (i + 1) << ", size = " << arrayQueueSize << endl;
            demo_enqueue(arrayQueue, colorInConsole);
        }
    }

    void bench_create_empty(VirtualQueue *queue, string colorInConsole) {
        cout << colorInConsole;
        auto start = high_resolution_clock::now();
        queue->create_empty(numberOfBenchmarkObjects);
        auto stop = high_resolution_clock::now();

        auto duration = duration_cast<nanoseconds>(stop - start);
        cout << "\t" << "\t" << "Creating queue took " << duration.count() << " nanoseconds" << endl;
    }

    void bench_enqueue(VirtualQueue *queue, string colorInConsole) {
        cout << colorInConsole;
        vector<Position> positions;
        for (int i = 0; i < numberOfBenchmarkObjects; ++i) {
            positions.push_back(createRandomPosition());
        }
        auto start = high_resolution_clock::now();
        for (int i = 0; i < numberOfBenchmarkObjects; ++i) {
            queue->enqueue(positions[i]);
        }
        auto stop = high_resolution_clock::now();
        auto duration = duration_cast<nanoseconds>(stop - start);
        cout << "\t" << "\t" << "Enqueue " << numberOfBenchmarkObjects << " elements took " <<
             duration.count() << " nanoseconds" << endl;
    }

    void bench_dequeue(VirtualQueue *queue, string colorInConsole) {
        cout << colorInConsole;
        vector<Position> positions;
        for (int i = 0; i < numberOfBenchmarkObjects; ++i) {
            positions.push_back(createRandomPosition());
        }
        auto start = high_resolution_clock::now();
        for (int i = 0; i < numberOfBenchmarkObjects; ++i) {
            queue->dequeue();
        }
        auto stop = high_resolution_clock::now();
        auto duration = duration_cast<nanoseconds>(stop - start);
        cout << "\t" << "\t" << "Dequeue " << numberOfBenchmarkObjects << " times took " <<
             duration.count() << " nanoseconds" << endl;
    }

    void bench_is_empty(VirtualQueue *queue, string colorInConsole) {
        cout << colorInConsole;
        vector<Position> positions;
        for (int i = 0; i < numberOfBenchmarkObjects; ++i) {
            positions.push_back(createRandomPosition());
        }
        auto start = high_resolution_clock::now();
        for (int i = 0; i < numberOfBenchmarkObjects; ++i) {
            queue->is_empty();
        }
        auto stop = high_resolution_clock::now();
        auto duration = duration_cast<nanoseconds>(stop - start);
        cout << "\t" << "\t" << "Is empty check " << numberOfBenchmarkObjects << " times took " <<
             duration.count() << " nanoseconds" << endl;
    }

    void bench_script(VirtualQueue *queue, string colorInConsole) {
        cout << colorInConsole;
        vector<Position> positions;
        for (int i = 0; i < numberOfBenchmarkObjects; ++i) {
            positions.push_back(createRandomPosition());
        }
        auto start = high_resolution_clock::now();
        for (int i = 0; i < numberOfBenchmarkObjects; ++i) {
            queue->enqueue(positions[i]);
        }
        for (int i = 0; i < numberOfBenchmarkObjects / 3; ++i) {
            queue->dequeue();
        }
        for (int i = 0; i < numberOfBenchmarkObjects / 4; ++i) {
            queue->is_empty();
        }
        while (!queue->is_empty()) {
            queue->dequeue();
        }
        auto stop = high_resolution_clock::now();
        auto duration = duration_cast<nanoseconds>(stop - start);
        cout << "\t" << "\t" << "My benchmark script took " << duration.count() << " nanoseconds" << endl;
    }

    void standardBench(VirtualQueue *queue, string colorInConsole) {
        bench_create_empty(queue, colorInConsole);
        bench_enqueue(queue, colorInConsole);
        bench_dequeue(queue, colorInConsole);
        bench_is_empty(queue, colorInConsole);
        cout << endl;
        bench_script(queue, colorInConsole);
    }

public:
    void demon() {
        arrayQueue = new struct ArrayQueue();
        cout << _1ST_IN_CONSOLE;
        cout << "\t" << "Demonstrating Array-Queue:" << endl;
        standardDemo(arrayQueue, _1ST_IN_CONSOLE);
        additionalDemoForArray(_1ST_IN_CONSOLE);
        cout << endl << endl;


        vectorQueue = new struct VectorQueue();
        cout << _2ND_IN_CONSOLE;
        cout << "\t" << "Demonstrating Vector-Queue:" << endl;
        standardDemo(vectorQueue, _2ND_IN_CONSOLE);
        cout << endl << endl;

        linkedQueue = new struct LinkedQueue();
        cout << _3RD_IN_CONSOLE;
        cout << "\t" << "Demonstrating Linked-Queue:" << endl;
        standardDemo(linkedQueue, _3RD_IN_CONSOLE);
    }

    void bench() {
        arrayQueue = new struct ArrayQueue();
        cout << _1ST_IN_CONSOLE;
        cout << "\t" << "Benchmark of Array-Queue:" << endl;
        standardBench(arrayQueue, _1ST_IN_CONSOLE);
        cout << endl << endl;

        vectorQueue = new struct VectorQueue();
        cout << _2ND_IN_CONSOLE;
        cout << "\t" << "Benchmark of Vector-Queue:" << endl;
        standardBench(vectorQueue, _2ND_IN_CONSOLE);
        cout << endl << endl;

        linkedQueue = new struct LinkedQueue();
        cout << _3RD_IN_CONSOLE;
        cout << "\t" << "Benchmark of Linked-Queue:" << endl;
        standardBench(linkedQueue, _3RD_IN_CONSOLE);
    }
};


#endif
