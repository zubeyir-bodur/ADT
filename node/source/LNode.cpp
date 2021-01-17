/**
 * Author: Zubeyir Bodur
 * Date: 9.1.2021
 */
#include "node/header/LNode.h"
template <typename T>
LNode<T>::LNode() {
   next = nullptr;
   item = NULL;
}

template<typename T>
LNode<T>::~LNode() {}

template<typename T>
LNode<T>::LNode(const LNode<T>& node) {
    next = nullptr;
    item = node.item;
}

template<typename T>
LNode<T>::LNode(const T& item, LNode<T>* next) {
    this->next = next;
    this->item = item;
}

template<typename T>
LNode<T> &LNode<T>::operator=(const LNode<T> &rvalue) {
    if (this == &rvalue) // self assignment
        return *this;
    else {
        this->next = nullptr; // copy only the item, not the rest of the links
        this->item = rvalue.item;
    }
    return *this;
}

