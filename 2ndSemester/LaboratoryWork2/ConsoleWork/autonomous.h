#ifndef HOMEWORK_AUTONOMOUS_H
#define HOMEWORK_AUTONOMOUS_H

#include "../Data/Position.h"

using namespace std;

class Autonomous {
private:
    ArrayQueue *arrayQueue;
    const int arrayQueueSize = 3;
    VectorQueue *vectorQueue;
    LinkedQueue *linkedQueue;

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

    void use_create_empty(VirtualQueue *queue, string colorInConsole) {
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

    void use_enqueue(VirtualQueue *queue, string colorInConsole) {
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

    void use_dequeue(VirtualQueue *queue, string colorInConsole) {
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

    void use_is_empty(VirtualQueue *queue, string colorInConsole) {
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
        use_enqueue(queue, colorInConsole);
        use_dequeue(queue, colorInConsole);
        use_is_empty(queue, colorInConsole);

        use_create_empty(queue, colorInConsole);
        use_create_empty(queue, colorInConsole);

        use_is_empty(queue, colorInConsole);

        use_enqueue(queue, colorInConsole);
        use_is_empty(queue, colorInConsole);

        use_dequeue(queue, colorInConsole);
        use_is_empty(queue, colorInConsole);
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
            use_enqueue(arrayQueue, colorInConsole);
        }
    }

    void standardBench(VirtualQueue *queue, string colorInConsole) {
        cout << colorInConsole;

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
