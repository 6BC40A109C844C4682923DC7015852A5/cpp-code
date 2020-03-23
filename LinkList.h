#include "List.h"
#include <iostream>

#ifndef LINK_LIST
#define LINK_LIST

template <typename T>
class LinkList : public List<T> {
private:
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

    iterator begin() { return iterator(first); }
    iterator end() { return iterator(nullptr); }

public:
    LinkList(): first(nullptr){};
    bool insert(T _data);
    void traversal(std::function<void(T)> visit);
    ~LinkList(){free(first);};
private:
  struct LNode {
    T data;
    LNode *next;
  };

  LNode *first = nullptr;
};

template<typename T>
bool LinkList<T>::insert(T _data) {
    if(this->first == nullptr){
        this->first = new LNode();
        this->first->data = _data;
        this->first->next = NULL;
        return true;
    }

    LNode *p = this->first;
    LNode *s = new LNode();
    s->data = _data;

    while (p->next){
        p = p->next;
    }
    s->next = p->next;
    p->next = s;
    return true;
}

template<typename T>
void LinkList<T>::traversal(std::function<void(T)> visit) {
    for(T _data : *this)
        visit(_data);

}

#endif
