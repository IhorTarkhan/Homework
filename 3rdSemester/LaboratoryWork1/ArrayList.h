#ifndef HOMEWORK_ARRAYLIST_H
#define HOMEWORK_ARRAYLIST_H

template<class T>
class ArrayList : public List<T> {
private:
    int (*comparator)(T, T);

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

    ArrayList(int (*comparator)(T, T)) {
        this->comparator = comparator;
    }

    void add(T t) {
        if (maxSize <= actualSize) {
            resize();
        }
        array[actualSize] = t;
        ++actualSize;
    }

//    virtual int getIndex(T t) = 0;
//
//    virtual T get(int index) = 0;
//
//    virtual int getIndexWhereCondition(bool (*condition)(T)) = 0;
//
//    void compareTwo(T t1, T t2) {
//        std::cout << comparator(t1, t2);
//    }
    int size() {
        return actualSize;
    }
};

#endif
