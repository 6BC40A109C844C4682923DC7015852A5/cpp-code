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
    explicit Sqlist(int n): capacity(n), data(new T[this->capacity]){};
    Sqlist(){};

    T get(int index);
    bool set(int index, T _data);
    bool insert(int index, T _data);
    bool insert(T _data);
    T remove(int index);
    int removeAll(T _data);
    int contains(T _data);
    void traversal(std::function<void(T)> visit);
    bool isEmpty();

    ~Sqlist(){};
protected:
    T *data;
    int size = 0;
    int capacity = 0;
};


template <typename T>
void Sqlist<T>::traversal(std::function<void (T)> visit) {
    for (int i = 0; i < this->size; ++i)
        visit(data[i]);
}

template<typename T>
T Sqlist<T>::get(const int index) {
    return data[index];
}

template<typename T>
bool Sqlist<T>::set(const int index, const T _data) {
    if(index < 0 || index > this->capacity - 1)
        return false;

    data[index] = _data;
    return true;
}

template <typename T>
bool Sqlist<T>::insert(const T _data) {
    if(size + 1 > this->capacity)
        return false;

    data[this->size] = _data;
    size++;
    return true;
}

template<typename T>
bool Sqlist<T>::insert(const int index, const T _data) {
    if(index < 0 || index > capacity - 1 || size == capacity)
        return false;

    for (int i = this->size - 1; i >= index ; ++i)
        data[i + 1] = data[i];

    data[index] = _data;
    size++;

    return true;

}

template<typename T>
T Sqlist<T>::remove(const int index) {
    if(index < 0 || index > capacity - 1 || size == 0)
        exit(1);

    T temp = data[index];
    for (int i = index; i < size - 1; ++i)
        data[i] = data[i + 1];
    size--;

    return temp;
}

template<typename T>
int Sqlist<T>::removeAll(const T _data) {
    int count = 0;
    for (int index = 0; index < capacity; index++){
        if(_data == data[index]){
            remove(index);
            count++;
        }
    }

    return count;
}

template<typename T>
int Sqlist<T>::contains(const T _data) {
    int count = 0;
    for (int index = 0; index < capacity; index++){
        if(_data == data[index])
            count++;
    }

    return count;
}

template<typename T>
bool Sqlist<T>::isEmpty() {
    return size == 0;
}


#endif
