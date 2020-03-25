#include "LinkList.h"

#ifndef DEMO_BTREE_H
#define DEMO_BTREE_H

template <typename T>
class Btree{
protected:
    struct BiTNode{
        T data;
        struct BiTNode *lchild, *rchild;
    };

public:
    Btree(): bitree(new BiTNode()){};
    void PreInCreate(T pre[], T in[], int h1, int h2, int l1 = 0, int l2 = 0);
    void PreOrder(LinkList<T> &l);
    void InOrder(LinkList<T> &l);
    void PostOrder(LinkList<T> &l);
    ~Btree(){
        if(bitree != nullptr){
            delete(bitree);
            bitree = nullptr;
        }
    };

private:
    BiTNode* pic(T pre[], T in[], int h1, int h2, int l1, int l2);
    void pre(BiTNode *_bitree, LinkList<T> &l);
    void in(BiTNode *_bitree, LinkList<T> &l);
    void pos(BiTNode *_bitree, LinkList<T> &l);
    BiTNode *bitree;

};

template<typename T>
void Btree<T>::PreInCreate(T *pre, T *in, int h1, int h2, int l1, int l2) {
    this->bitree = pic(pre, in, h1, h2, l1, l2);
}

template<typename T>
typename Btree<T>::BiTNode* Btree<T>::pic(T *pre, T *in, int h1, int h2, int l1, int l2) {
    // l1, h1 are the preorder's first and last indexes,
    // l2, h2 are the inorder's first and last indexes, default l1=l2=0, h1=h2=(n - 1).
    BiTNode *root = new BiTNode();
    int llen, rlen, i;

    root->data = pre[l1];
    for(i = l2; in[i] != root->data; i++);
    llen = i - l2;
    rlen = h2 - i;
    if(llen)
        root->lchild = pic(pre, in, l1 + llen, l2 + llen - 1, l1 + 1, l2);
    else
        root->lchild = NULL;
    if(rlen)
        root->rchild = pic(pre, in,  h1, h2, h1 - rlen + 1, h2 - rlen + 1);
    else
        root->rchild = NULL;

    return root;
}

template<typename T>
void Btree<T>::pre(BiTNode *_bitree, LinkList<T> &l) {
    if(NULL != _bitree){
        l.insert(_bitree -> data);
        pre(_bitree->lchild, l);
        pre(_bitree->rchild, l);
    }
}

template<typename T>
void Btree<T>::in(BiTNode *_bitree, LinkList<T> &l) {
    if(NULL != _bitree){
        in(_bitree->lchild, l);
        l.insert(_bitree -> data);
        in(_bitree->rchild, l);
    }
}

template<typename T>
void Btree<T>::pos(BiTNode *_bitree, LinkList<T> &l) {
    if(NULL != _bitree){
        pos(_bitree->lchild, l);
        pos(_bitree->rchild, l);
        l.insert(_bitree -> data);
    }
}


template<typename T>
void Btree<T>::PreOrder(LinkList<T> &l) {
    pre(this->bitree, l);
}

template<typename T>
void Btree<T>::InOrder(LinkList<T> &l) {
    in(this->bitree, l);
}

template<typename T>
void Btree<T>::PostOrder(LinkList<T> &l) {
    pos(this->bitree, l);
}


#endif //DEMO_BTREE_H
