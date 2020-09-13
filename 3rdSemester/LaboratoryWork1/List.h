#ifndef HOMEWORK_LIST_H
#define HOMEWORK_LIST_H

template<class T>
class List {
public:
    virtual void add(T t) = 0;

    virtual T get(int index) = 0;

//    virtual int getIndex(T t) = 0;
//
//    virtual int getIndexWhereCondition(bool (*condition)(T)) = 0;
//
    virtual int size() = 0;

    std::string toString(std::string (*toStringType)(T)) {
        std::string result = "[";
        for (int i = 0; i < size(); ++i) {
            result += toStringType(get(i)) + ", ";
        }
        if (size() != 0) {
            result = result.substr(0, result.size() - 2);
        }
        result += "]";
        return result;
    };
};

#endif
