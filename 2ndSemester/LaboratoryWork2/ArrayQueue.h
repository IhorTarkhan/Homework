#ifndef HOMEWORK_ARRAYQUEUE_H
#define HOMEWORK_ARRAYQUEUE_H

#include "Position.h"

class ArrayQueue {
    int size = -1;
    int fillingSize;
    Position *queue;

public:
    void create_empty(const int size) {
        if (size < 0) {
            throw "Incorrect argument of size";
        }
        if (this->size >= 0) {
            throw "Queue is already existed";
        }
        queue = new Position[size];
        this->size = size;
        fillingSize = 0;
    }

    void enqueue(Position position) {
        if (this->size < 0) {
            throw "Queue is not existed";
        }
        if (fillingSize >= size) {
            throw "Queue is overfill";
        }
        queue[fillingSize] = position;
        ++fillingSize;
    }

    Position dequeue() {
        if (this->size < 0) {
            throw "Queue is not existed";
        }
        if (!fillingSize) {
            throw "Queue is empty";
        }
        Position positionToReturn = queue[0];
        --fillingSize;
        for (int i = 0; i < fillingSize; ++i) {
            queue[i] = queue[i + 1];
        }
        return positionToReturn;
    }

    bool is_empty() {
        if (this->size < 0) {
            throw "Queue is not existed";
        }
        return fillingSize <= 0;
    }
};

#endif
