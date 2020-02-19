#ifndef HOMEWORK_ARRAYQUEUE_H
#define HOMEWORK_ARRAYQUEUE_H

#include "Position.h"

class ArrayQueue {
    int size;
    int fillingSize;
    Position *queue;

public:
    void create_empty(const int size) {
        Position array[size];
        queue = array;
        ArrayQueue::size = size;
        fillingSize = 0;
    }

    void enqueue(Position position) {
        if (fillingSize >= size) {
            throw "Queue is overfill";
        }
        queue[fillingSize] = position;
        ++fillingSize;
    }

    Position dequeue() {
        Position positionToReturn = queue[0];
        for (int i = 0; i < fillingSize - 1; ++i) {
            queue[i] = queue[i + 1];
        }
        --fillingSize;
        return positionToReturn;
    }
};

#endif
