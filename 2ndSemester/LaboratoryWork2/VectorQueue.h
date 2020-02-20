#ifndef HOMEWORK_VECTORQUEUE_H
#define HOMEWORK_VECTORQUEUE_H

#include "Position.h"
#include <vector>

class VectorQueue {
    int fillingSize = -1;
    vector<Position> queue;

public:
    void create_empty() {
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
