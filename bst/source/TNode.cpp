/**
 * Author: Zubeyir Bodur
 * Date: 14.1.2021
 **/
#include "../header/TNode.h"

template<typename Key>
TNode<Key>::TNode() {
    leftChild = nullptr;
    rightChild = nullptr;
    key = NULL;
    count = 0;
}

template<typename Key>
TNode<Key>::~TNode() {
    if (leftChild) delete leftChild;
    if (rightChild) delete rightChild;
}

template<typename Key>
TNode<Key>::TNode(const TNode<Key> &tNode) {
    this->leftChild = nullptr;
    this->rightChild = nullptr;
    this->key = tNode.key;
    this->count = tNode.count;
}

template<typename Key>
TNode<Key>::TNode(const Key &key, const int &count, TNode<Key> *leftChild, TNode<Key> *rightChild) {
    this->leftChild = leftChild;
    this->rightChild = rightChild;
    this->key = key;
    this->count = count;
}

template<typename Key>
bool TNode<Key>::isLeaf() const {
    return !(leftChild || rightChild);
}

template<typename Key>
bool TNode<Key>::hasTwo() const {
    return (leftChild && rightChild);
}

template<typename Key>
bool TNode<Key>::hasRightOnly() const {
    return (!leftChild && rightChild);
}

template<typename Key>
bool TNode<Key>::hasLeftOnly() const {
    return (leftChild && !rightChild);
}

template<typename Key>
TNode<Key> &TNode<Key>::operator=(const TNode<Key> &rvalue) {
    if (this != &rvalue) { // self assignment
        this->leftChild = nullptr;
        this->rightChild = nullptr;
        this->key = rvalue.key;
        this->count = rvalue.count;
    }
    return *this;
}

template<typename Key>
void TNode<Key>::display(ostream &out) const {
    out << key << " : " << count;
}
