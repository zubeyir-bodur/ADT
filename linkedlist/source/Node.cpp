/**
 * Author: Zubeyir Bodur
 * Date: 9.1.2021
 */
#include "../header/Node.h"
template <typename T>
Node<T>::Node() {
   next = nullptr;
   item = NULL;
}

template<typename T>
Node<T>::~Node() {}

template<typename T>
Node<T>::Node(const Node<T>& node) {
    next = nullptr;
    item = node.item;
}

template<typename T>
Node<T>::Node(const T& item, Node<T>* next) {
    this->next = next;
    this->item = item;
}

template<typename T>
Node<T> &Node<T>::operator=(const Node<T> &rvalue) {
    if (this == &rvalue) // self assignment
        return *this;
    else {
        this->next = nullptr; // copy only the item, not the rest of the links
        this->item = rvalue.item;
    }
    return *this;
}

