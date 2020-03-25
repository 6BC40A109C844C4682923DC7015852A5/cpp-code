#include "List.h"
#include <iostream>

#ifndef LINK_LIST
#define LINK_LIST

template <typename T>
class LinkList : public List<T> {
protected:
    struct LNode;
public:
    class iterator {
        LNode *node;

    public:
        explicit iterator(LNode *node) : node(node) {}
        iterator &operator++() {
            node = node->next;
            return *this;
        }
        iterator operator++(int) {
            iterator retval = *this;
            ++(*this);
            return retval;
        }
        bool operator==(iterator other) const { return node == other.node; }
        bool operator!=(iterator other) const { return !(*this == other); }
        T operator*() const { return node->data; }
    };

    iterator begin() { return iterator(head); }
    iterator end() { return iterator(tail->next); }

public:
    LinkList(){this->size = 0; this->head = this->tail; this->head = nullptr;};
    bool isEmpty();
    T get(int index);
    bool set(int index, T _data);
    bool insert(T _data);
    bool insert(int index, T _data);
    T remove(int index);
    int removeAll(T _data);
    int contains(T _data);
    void traversal(std::function<void(T)> visit);
    ~LinkList(){free(head);free(tail);};
protected:
  struct LNode {
    T data;
    LNode *next;
  };

  LNode *head;
  LNode *tail;
  int size;
};


template<typename T>
bool LinkList<T>::isEmpty() {
    return !this->size;
}

template<typename T>
T LinkList<T>::get(int index) {
    if(index < 0 || this->size == 0)
        exit(1);

    int count = 0;
    LNode *cur = this->head;
    while (count < index){
        if(cur == nullptr && count != index)
            exit(1);
        cur = cur->next;
        count++;
    }

    return cur->data;
}

template<typename T>
bool LinkList<T>::set(int index, T _data) {
    if(index < 0 || this->size == 0)
        return false;

    int count = 0;
    LNode *cur = this->head;
    while (count < index){
        if(cur == nullptr && count != index)
            exit(1);
        cur = cur->next;
        count++;
    }

    cur->data = _data;
    return true;
}

template<typename T>
bool LinkList<T>::insert(T _data) {
    if(this->head == nullptr){
        this->head = this->tail = new LNode();
        this->head->data = _data;
        this->head->next = nullptr;
        this->size++;
        return true;
    }

    LNode *s = new LNode();
    s->data = _data;
    this->tail->next = s;
    this->tail = s;
    this->size++;
    return true;
}

template<typename T>
bool LinkList<T>::insert(const int index, T _data) {
    if(index < 0)
        return false;

    LNode *cur = this->head;
    LNode *pri = nullptr;
    int count = 0;
    while(count < index){
        if(cur == nullptr && count != index)
            return false;
        pri = cur;
        cur = cur->next;
        count++;
    }

    LNode *s = new LNode();
    s->data = _data;

    if(this->head == cur){
        s->next = this->head;
        this->head = s;
        this->size++;
        return true;
    } else{
        s->next = cur->next;
        pri->next = s;
        this->size++;
        return true;
    }
}

template<typename T>
T LinkList<T>::remove(int index) {
    if(index < 0 || this->size == 0)
        exit(1);

    int count = 0;
    LNode *cur = this->head;
    LNode *pri = nullptr;
    while (count < index){
        if(cur == nullptr && count != index)
            exit(1);
        pri = cur;
        cur = cur->next;
        count++;
    }

    T v = cur->data;
    if(this->head == cur){
        this->head = this->head->next;
        this->size--;
    }
    else{
        pri->next = cur->next;
        cur->next = nullptr;
        free(cur);
        this->size--;
    }
    return v;
}

template<typename T>
int LinkList<T>::removeAll(T _data) {
    int count = 0;
    int index = 0;
    for (LNode *item = this->head; item != nullptr; item = item->next) {
        if(item->data == _data){
            remove(index);
            count++;
        } else
            index++;
    }

    return count;
}

template<typename T>
int LinkList<T>::contains(T _data) {
    int count = 0;
    for (LNode *item = this->head; item != nullptr; item = item->next) {
        if(item->data == _data)
            count++;
    }

    return count;
}

template<typename T>
void LinkList<T>::traversal(std::function<void(T)> visit) {
    for(T _data : *this)
        visit(_data);

}

#endif
