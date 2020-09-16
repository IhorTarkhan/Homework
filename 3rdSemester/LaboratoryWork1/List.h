#ifndef HOMEWORK_LIST_H
#define HOMEWORK_LIST_H

template<class T>
class Iterator {
    virtual bool hasNext() = 0;

    virtual T next() = 0;
};

template<class T>
class List {
private:
    class Itr : public Iterator<T> {
    private:
        int currentPosition = -1;
        List<T> *thisList;

        Itr(List<T> *thisList) : thisList(thisList) {}

    public:
        T next() {
            ++currentPosition;
            return thisList->get(currentPosition);
        }

        bool hasNext() {
            return currentPosition + 1 > thisList->size();
        }
    };

public:
    virtual int size() = 0;

    virtual void add(T t) = 0;

    virtual T get(int index) = 0;

    virtual int getIndexWhereCondition(bool (*condition)(T)) = 0;

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

    void foreach(void (*lambda)(T)) {
        for (int i = 0; i < size(); ++i) {
            lambda(get(i));
        }
    }

    Iterator<T> iterator() {
        return Itr(this);
    }
};

#endif
