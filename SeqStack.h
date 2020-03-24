#include <iostream>
#include "SqList.h"

#ifndef SEQSTACK_H
#define SEQSTACK_H

template <typename T>
class SqStack: public Sqlist<T>{
public:
    SqStack(int n){top = -1; this->capacity = n; this->data = new T[this->capacity];};
    bool push(T _data);
    T pop();
    ~SqStack(){free(this->data);};

private:
    int top;

};

template<typename T>
bool SqStack<T>::push(T _data) {
    if(top == this->capacity - 1)
        return false;
    top += 1;
    this->data[top] = _data;
    this->size++;
    return true;
}

template<typename T>
T SqStack<T>::pop() {
    if(!this->size)
        exit(1);

    int v = this->data[top];
    top--;
    this->size--;
    return v;
}

#endif
