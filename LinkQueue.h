#include "LinkList.h"

#ifndef DEMO_LINKQUEUE_H
#define DEMO_LINKQUEUE_H

template <typename T>
class LinkQueue: public LinkList<T>{
public:
    LinkQueue(){this->size = 0; this->head = this->tail; this->head = nullptr;}
    bool push(T _data);
    T pop();
    T front();
    T back();
    ~LinkQueue(){};
};

template<typename T>
bool LinkQueue<T>::push(T _data) {
    return this->insert(_data);
}

template<typename T>
T LinkQueue<T>::pop() {
    if(this->head == nullptr)
        exit(1);

    typename LinkQueue<T>::LNode *cur = this->head;

    T v = cur->data;
    this->head = cur->next;
    delete(cur);
    cur = nullptr;
    this->size--;
    return v;
}

template<typename T>
T LinkQueue<T>::front() {
    return this->head->data;
}

template<typename T>
T LinkQueue<T>::back() {
    return this->tail->data;
}

#endif //DEMO_LINKQUEUE_H
