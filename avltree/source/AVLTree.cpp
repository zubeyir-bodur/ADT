/**
 * Author: Zubeyir Bodur
 * Date: 17.1.2021
 */
#include "../header/AVLTree.h"

template<typename Key, typename Item>
AVLTree<Key, Item>::AVLTree() {
    super::root = nullptr;
}

template<typename Key, typename Item>
AVLTree<Key, Item>::AVLTree(const AVLTree<Key, Item> &avlTree) {
    super::root = nullptr;
    Node<Key, Item>* tmp = avlTree.root;
    super::copyTree(super::root, tmp);
}

template<typename Key, typename Item>
void AVLTree<Key, Item>::insert(const Key &key, const Item &item) {
    // insert the same as BST
    super::insert(key, item);
    // perform the proper rotate operation
}

/**
 * AVL Tree removal, the place where we actually use parent ptr
 * @tparam Key
 * @tparam Item
 * @param key
 */
template<typename Key, typename Item>
void AVLTree<Key, Item>::remove(const Key &key) {
    // remove the same as BST
    super::remove(key);
    // balance the removal position up to the parent
}

template<typename Key, typename Item>
void AVLTree<Key, Item>::printPair(const Key &key, const Item &item) {
    super::printPair(key, item);
}

template<typename Key, typename Item>
AVLTree<Key, Item> &AVLTree<Key, Item>::operator=(const AVLTree<Key, Item> &rvalue) {
    if (this != &rvalue) {
        super::destroyTree(this->root);
        super::copyTree(this->root, rvalue.root);
    }
    return *this;
}
