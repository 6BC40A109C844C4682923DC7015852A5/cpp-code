#include <functional>

#ifndef LIST_H
#define LIST_H

template <typename T>
class List{
public:
    List(){};
    virtual bool insert(T data) = 0;
    virtual void traversal(std::function<void(T)> visit) = 0;
    virtual ~List(){};
};

#endif
