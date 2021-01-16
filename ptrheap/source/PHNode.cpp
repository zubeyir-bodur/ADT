/**
* Author: Zubeyir Bodur
* Date: 16.1.2021
*/
#include "../header/PHNode.h"

template<typename Key, typename Data>
PHNode<Key, Data>::PHNode() = default;

template<typename Key, typename Data>
PHNode<Key, Data>::~PHNode() = default;

template<typename Key, typename Data>
PHNode<Key, Data>::PHNode(const PHNode<Key> &node) {
    left = nullptr;
    right = nullptr;
    parent = nullptr;
    key = node.key;
    data = node.data;
}

template<typename Key, typename Data>
PHNode<Key, Data>::PHNode(const Key &key,
                        const Data &data,
                        PHNode<Key, Data> *left,
                        PHNode<Key, Data> *right,
                        PHNode<Key, Data>* parent) {
    this->left = left;
    this->right = right;
    this->parent = parent;
    this->key = key;
    this->data = data;
}


