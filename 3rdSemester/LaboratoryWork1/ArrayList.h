#ifndef HOMEWORK_ARRAYLIST_H
#define HOMEWORK_ARRAYLIST_H

template<class T>
class ArrayList : public List<T> {
private:
    int maxSize = 16;
    T *array = new T[maxSize];
    int actualSize = 0;

    void resize() {
        maxSize *= 1.5;
        T *newArray = new T[maxSize];
        for (int i = 0; i < actualSize; ++i) {
            newArray[i] = array[i];
        }
        array = newArray;
    };

public:
    int size() {
        return actualSize;
    }

    void add(T t) {
        if (maxSize <= actualSize) {
            resize();
        }
        array[actualSize] = t;
        ++actualSize;
    }

    T get(int index) {
        if (index >= actualSize || index < 0) {
            throw std::exception();
        } else {
            return array[index];
        }
    }

    int getIndexWhereCondition(bool (*condition)(T)) {
        for (int i = 0; i < actualSize; ++i) {
            if (condition(array[i])) {
                return i;
            }
        }
        throw std::exception();
    };
};

#endif
