#ifndef HOMEWORK_LIST_H
#define HOMEWORK_LIST_H

template<class T>
class List {
public:
    virtual void add(T t) = 0;

//    virtual int getIndex(T t) = 0;
//
//    virtual T get(int index) = 0;
//
//    virtual int getIndexWhereCondition(bool (*condition)(T)) = 0;
//
    virtual int size() = 0;
};

#endif
