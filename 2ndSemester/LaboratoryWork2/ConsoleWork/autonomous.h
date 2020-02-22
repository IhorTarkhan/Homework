#ifndef HOMEWORK_AUTONOMOUS_H
#define HOMEWORK_AUTONOMOUS_H

#include "../Data/Position.h"

using namespace std;

class Autonomous {
private:
    ArrayQueue *arrayQueue = new struct ArrayQueue();
    const int arrayQueueSize = 3;
    VectorQueue *vectorQueue = new struct VectorQueue();
    LinkedQueue *linkedQueue = new struct LinkedQueue();

    const string _1ST_DEMO = "\u001B[30m";            /// WHITE
    const string _2ND_DEMO = "\u001B[34m";            /// BLUE
    const string _3RD_DEMO = "\u001B[35m";            /// VIOLET

    const string EXCEPTION_DEMO = "\u001B[31m";       /// READ
    const string MESSAGE_DEMO = "\u001B[33m";         /// YELLOW

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
            cout << EXCEPTION_DEMO;
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
            cout << MESSAGE_DEMO;
            cout << "\t" << "\t" << "\t" << "Position = " << getPositionInString(position) << endl;
            cout << colorInConsole;

            queue->enqueue(position);
            cout << "\t" << "\t" << "Complete!" << endl;
        } catch (const char *msg) {
            cout << EXCEPTION_DEMO;
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
            cout << EXCEPTION_DEMO;
            cout << "\t" << "\t" << "\t" << msg << endl;
            cout << colorInConsole;
        }
        cout << endl;
    }

    void use_is_empty(VirtualQueue *queue, string colorInConsole) {
        cout << colorInConsole;
        cout << "\t" << "\t" << "Try to use function \"is_empty()\" ..." << endl;
        try {
            cout << MESSAGE_DEMO;
            bool isEmpty = queue->is_empty();
            cout << "\t" << "\t" << "\t" << ((isEmpty) ? "TRUE" : "FALSE") << endl;
            cout << colorInConsole;
            cout << "\t" << "\t" << "Complete!" << endl;
        } catch (const char *msg) {
            cout << EXCEPTION_DEMO;
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

public:
    void demon() {
        cout << _1ST_DEMO;
        cout << "\t" << "Demonstrating Array-Queue:" << endl;
        standardDemo(arrayQueue, _1ST_DEMO);
        cout << endl << endl;

        cout << _2ND_DEMO;
        cout << "\t" << "Demonstrating Vector-Queue:" << endl;
        standardDemo(vectorQueue, _2ND_DEMO);
        cout << endl << endl;

        cout << _3RD_DEMO;
        cout << "\t" << "Demonstrating Linked-Queue:" << endl;
        standardDemo(linkedQueue, _3RD_DEMO);
    }

    void bench() {
        Position position = createRandomPosition();
        getPositionInString(position);
    }
};


#endif
