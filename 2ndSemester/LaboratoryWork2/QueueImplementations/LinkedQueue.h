#ifndef HOMEWORK_LINKEDQUEUE_H
#define HOMEWORK_LINKEDQUEUE_H

#include "VirtualQueue.h"

class Node {
public:
    Position value;
    Node *next;
    Node *prev;
};

struct LinkedQueue : VirtualQueue {
private:
    int fillingSize = -1;
    Node *head;
    Node *tail;

public:
    void create_empty(const int size) {
        if (size < 0) {
            throw "Incorrect argument of size";
        }
        if (fillingSize >= 0) {
            throw "Queue is already existed";
        }
        fillingSize = 0;
        head = nullptr;
        tail = nullptr;
    }

    void enqueue(Position position) {
        if (fillingSize < 0) {
            throw "Queue is not existed";
        }
        Node *node = new Node;
        node->value = position;
        node->prev = tail;
        node->next = nullptr;
        if (tail) {
            tail->next = node;
            tail = node;
        } else {
            tail = head = node;
        }
        ++fillingSize;
    }

    Position dequeue() {
        if (fillingSize < 0) {
            throw "Queue is not existed";
        }
        if (fillingSize == 0) {
            throw "Queue is empty";
        }
        Position positionToReturn;
        positionToReturn = head->value;
        head = head->next;
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
