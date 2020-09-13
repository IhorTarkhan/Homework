#ifndef HOMEWORK_LOINKEDLIST_H
#define HOMEWORK_LOINKEDLIST_H

#include "../List.h"

template<class T>
class LinkedList : public List<T> {
private:
    class Node {
    public:
        T value;
        Node *next = nullptr;

        Node(T value) : value(value) {}
    };

    Node *head = nullptr;
    int actualSize = 0;

public:
    int size() {
        return actualSize;
    }

    void add(T t) {
        if (head == nullptr) {
            head = new Node(t);
        } else {
            Node *nextNode = head;
            while (nextNode->next != nullptr) {
                nextNode = nextNode->next;
            }
            nextNode->next = new Node(t);
        }
        ++actualSize;
    }

    T get(int index) {
        if (index >= actualSize || index < 0) {
            throw std::exception();
        }
        Node *nextNode = head;
        while (index > 0) {
            nextNode = nextNode->next;
            --index;
        }
        return nextNode->value;
    }

    int getIndexWhereCondition(bool (*condition)(T)) {
        int index = 0;
        Node *nextNode = head;
        while (nextNode != nullptr) {
            if (condition(nextNode->value)) {
                return index;
            }
            nextNode = nextNode->next;
            ++index;
        }
        throw std::exception();
    };
};

#endif
