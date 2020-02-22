#ifndef HOMEWORK_INTERACTIVE_H
#define HOMEWORK_INTERACTIVE_H

class Interactive {
private:
    ArrayQueue *arrayQueue = new struct ArrayQueue();
    VectorQueue *vectorQueue = new struct VectorQueue();
    LinkedQueue *linkedQueue = new struct LinkedQueue();
    VirtualQueue *queue;

    const string _1ST_LEVEL_PRINTING = "\u001B[34m";    /// BLUE
    const string _2ND_LEVEL_PRINTING = "\u001B[33m";    /// YELLOW
    const string _3RG_LEVEL_PRINTING = "\u001B[35m";    /// VIOLET

    void printPosition(Position position) {
        cout << _3RG_LEVEL_PRINTING;
        cout << "\t" << "\t" << "\t" << to_string(position.x) << "; " << to_string(position.y) << "; "
             << to_string(position.z) << endl;
    }

    Position readPositionFromConsole() {
        cout << _3RG_LEVEL_PRINTING;
        Position position;
        cout << "\t" << "\t" << "\t" << "Enter position values in format \"<x> <y> <z>\": ";

        /* By the way, standard function "stod" don'n check values after point
         * If you enter incorrect values, position values will be 0, the same in function "stod" */

        cin >> position.x;
        cin >> position.y;
        cin >> position.z;
        return position;
    }

    int readSizeOfArrayFromConsole() {
        cout << _3RG_LEVEL_PRINTING;
        string size;
        do {
            cout << "\t" << "\t" << "\t" << "Enter size of array: ";
            cin >> size;
        } while (size != to_string(stoi(size)));
        return stoi(size);
    }

    void readFunctionType() {
        cout << _2ND_LEVEL_PRINTING;
        while (true) {
            cout << "\t" << "\t" << "Enter type of Function, witch you want to use:" << endl;
            cout << "\t" << "\t" << "1 - create_empty;" << endl;
            cout << "\t" << "\t" << "2 - enqueue;" << endl;
            cout << "\t" << "\t" << "3 - dequeue;" << endl;
            cout << "\t" << "\t" << "4 - is_empty." << endl;
            cout << "\t" << "\t" << "Your choice: ";

            int choiceValue;
            cin >> choiceValue;
            switch (choiceValue) {
                case 1:
                    int size;
                    if (queue == arrayQueue) {
                        size = readSizeOfArrayFromConsole();
                    } else {
                        size = 0;
                    }
                    queue->create_empty(size);
                    return;
                case 2:
                    queue->enqueue(readPositionFromConsole());
                    return;
                case 3:
                    printPosition(queue->dequeue());
                    return;
                case 4:
                    cout << _3RG_LEVEL_PRINTING;
                    cout << "\t" << "\t" << "\t" << ((queue->is_empty()) ? "TRUE" : "FALSE");
                    cout << endl;
                    return;
                default:
                    cout << "\t" << "\t" << "Incorrect option selected!" << endl;
            }
        }
    }

    void readQueueType() {
        cout << _1ST_LEVEL_PRINTING;
        while (true) {
            cout << "\t" << "Enter type of Queue, witch you want to use:" << endl;
            cout << "\t" << "1 - Array;" << endl;
            cout << "\t" << "2 - Vector;" << endl;
            cout << "\t" << "3 - Linked." << endl;
            cout << "\t" << "Your choice: ";

            int choiceValue;
            cin >> choiceValue;
            switch (choiceValue) {
                case 1:
                    queue = arrayQueue;
                    return;
                case 2:
                    queue = vectorQueue;
                    return;
                case 3:
                    queue = linkedQueue;
                    return;
                default:
                    cout << "\t" << "Incorrect option selected!" << endl;
            }
        }
    }

public:
    void run() {
        readQueueType();
        readFunctionType();
    }
};

#endif
