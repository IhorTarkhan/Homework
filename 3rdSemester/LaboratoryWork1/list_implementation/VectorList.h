#ifndef HOMEWORK_VECTORLIST_H
#define HOMEWORK_VECTORLIST_H

#include "../List.h"

template<class T>
class VectorList : public List<T> {
private:
    std::vector<T> list;

public:
    int size() {
        return list.size();
    }

    void add(T t) {
        list.push_back(t);
    }

    T get(int index) {
        if (index >= list.size() || index < 0) {
            throw std::exception();
        }
        return list[index];
    }

    int getIndexWhereCondition(bool (*condition)(T)) {
        for (int i = 0; i < list.size(); ++i) {
            if (condition(list[i])) {
                return i;
            }
        }
        throw std::exception();
    }
};

#endif
