#include <iostream>
#include "List.h"

#ifndef SQ_LIST_H
#define SQ_LIST_H

template <typename T>
class Sqlist: public List<T>{
public:
    class iterator {
        T *index;

    public:
        explicit iterator(T *_index) : index(_index) {}
        iterator &operator++() {
            index++;
            return *this;
        }
        iterator operator++(int) {
            iterator retval = *this;
            ++(*this);
            return retval;
        }
        bool operator==(iterator other) const { return index == other.index; }
        bool operator!=(iterator other) const { return !(*this == other); }
        T operator*() const { return *index; }
    };

    iterator begin() { return iterator(this->data); }
    iterator end() { return iterator(&this->data[this->size]); }

public:
    Sqlist(int n): capacity(n), data(new T[this->capacity]){};
    Sqlist(){};
    bool insert(T _data){
        if(this->size + 1 > this->capacity)
            return false;

        this->data[this->size] = _data;
        this->size++;
        return true;
    }
    void traversal(std::function<void(T)> visit){
        for (int i = 0; i < this->size; ++i)
            visit(data[i]);
    }

    ~Sqlist(){};
private:
    T *data;
    int size = 0;
    int capacity = 0;
};


#endif
