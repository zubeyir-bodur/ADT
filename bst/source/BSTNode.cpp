/**
 * Author: Zubeyir Bodur
 * Date: 14.1.2021
 **/
#include "../header/BSTNode.h"

template<typename Key>
BSTNode<Key>::BSTNode() {
    leftChild = nullptr;
    rightChild = nullptr;
    key = NULL;
    count = 0;
}

template<typename Key>
BSTNode<Key>::BSTNode(const BSTNode<Key> &tNode) {
    this->leftChild = nullptr;
    this->rightChild = nullptr;
    this->key = tNode.key;
    this->count = tNode.count;
}

template<typename Key>
BSTNode<Key>::BSTNode(const Key &key, const int &count, BSTNode<Key> *leftChild, BSTNode<Key> *rightChild) {
    this->leftChild = leftChild;
    this->rightChild = rightChild;
    this->key = key;
    this->count = count;
}

template<typename Key>
bool BSTNode<Key>::isLeaf() const {
    return !(leftChild || rightChild);
}

template<typename Key>
bool BSTNode<Key>::hasTwo() const {
    return (leftChild && rightChild);
}

template<typename Key>
bool BSTNode<Key>::hasRightOnly() const {
    return (!leftChild && rightChild);
}

template<typename Key>
bool BSTNode<Key>::hasLeftOnly() const {
    return (leftChild && !rightChild);
}

template<typename Key>
BSTNode<Key> &BSTNode<Key>::operator=(const BSTNode<Key> &rvalue) {
    if (this != &rvalue) { // self assignment
        this->leftChild = nullptr;
        this->rightChild = nullptr;
        this->key = rvalue.key;
        this->count = rvalue.count;
    }
    return *this;
}

template<typename Key>
void BSTNode<Key>::display(ostream &out) const {
    out << key << " : " << count;
}
