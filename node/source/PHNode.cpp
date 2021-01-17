/**
* Author: Zubeyir Bodur
* Date: 16.1.2021
*/
#include "node/header/PHNode.h"

template<typename Key, typename Item>
PHNode<Key, Item>::PHNode() = default;

template<typename Key, typename Item>
PHNode<Key, Item>::~PHNode() = default;

template<typename Key, typename Item>
PHNode<Key, Item>::PHNode(const PHNode<Key, Item> &node) {
    left = nullptr;
    right = nullptr;
    parent = nullptr;
    key = node.key;
    data = node.data;
}

template<typename Key, typename Item>
PHNode<Key, Item>::PHNode(const Key &key,
                        const Item &data,
                        PHNode<Key, Item> *left,
                        PHNode<Key, Item> *right,
                        PHNode<Key, Item>* parent) {
    this->left = left;
    this->right = right;
    this->parent = parent;
    this->key = key;
    this->data = data;
}


