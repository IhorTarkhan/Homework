#ifndef HOMEWORK_VIRTUALQUEUE_H
#define HOMEWORK_VIRTUALQUEUE_H

#include "../Data/Position.h"

struct VirtualQueue {
public:
    virtual void create_empty(const int size) = 0;

    virtual bool is_empty() = 0;

    virtual void enqueue(Position position) = 0;

    virtual Position dequeue() = 0;
};

#endif
