#ifndef HOMEWORK_VECTORQUEUE_H
#define HOMEWORK_VECTORQUEUE_H

#include <vector>
#include "VirtualQueue.h"

struct VectorQueue : VirtualQueue {
    int fillingSize = -1;
    vector<Position> queue;

public:
    void create_empty(const int size) {
        if (size < 0) {
            throw "Incorrect argument of size";
        }
        if (fillingSize >= 0) {
            throw "Queue is already existed";
        }
        fillingSize = 0;
    }

    void enqueue(Position position) {
        if (fillingSize < 0) {
            throw "Queue is not existed";
        }
        queue.push_back(position);
        ++fillingSize;
    }

    Position dequeue() {
        if (fillingSize < 0) {
            throw "Queue is not existed";
        }
        if (fillingSize == 0) {
            throw "Queue is empty";
        }
        Position positionToReturn = queue[0];
        queue.erase(queue.begin());
        --fillingSize;
        return positionToReturn;
    }

    bool is_empty() {
        if (fillingSize < 0) {
            throw "Queue is not existed";
        }
        return fillingSize <= 0;
    }
};

#endif
