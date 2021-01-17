/**
 * Author: Zubeyir Bodur
 * Date: 16.1.2021
 */
#include "../header/PHeap.h"
#include "node/header/PHNode.h"

template<typename Key, typename Data>
PHeap<Key, Data>::PHeap() : isMin(false) {
    root = nullptr;
    last = nullptr;
}

template<typename Key, typename Data>
PHeap<Key, Data>::~PHeap() {
    destroyHeap(root);
    last = nullptr;
}

template<typename Key, typename Data>
void PHeap<Key, Data>::destroyHeap(PHNode<Key, Data>*& node) {
    if (node != nullptr) {
        destroyHeap(node->left);
        destroyHeap(node->right);
        delete node;
        node = nullptr;
    }
}

template<typename Key, typename Data>
PHeap<Key, Data>::PHeap(const PHeap<Key, Data> &heap) {
    root = nullptr;
    last = nullptr;
    copyHeap(root, last,  heap.root);
}

template<typename Key, typename Data>
void PHeap<Key, Data>::copyHeap(PHNode<Key, Data> *&targetRoot,
                                PHNode<Key, Data> *&targetLast,
                                PHNode<Key, Data> *&source) {
    if (source != nullptr) {
        targetRoot = new PHNode<Key, Data>(*source);
        targetLast = targetRoot;
        copyHeap(targetRoot->left, targetLast, source->left);
        copyHeap(targetRoot->right, targetLast, source->right);
    }
}

template<typename Key, typename Data>
PHeap<Key, Data>::PHeap(const bool &isMin) : isMin(isMin) {
    root = nullptr;
    last = nullptr;
}

/**
 * Inserts an item with given pair
 * @tparam Key
 * @tparam Data
 * @param key
 */
template<typename Key, typename Data>
void PHeap<Key, Data>::insert(const Key &key, const Data& data) {
    // TODO
}

template<typename Key, typename Data>
void PHeap<Key, Data>::insert(PHNode<Key, Data> *&node, const Key &key, const Data &data) {
    // TODO
//    if (node != nullptr) {
//        if (node->index == (size - 1) / 2) { // found the parent node of the insertion
//            // find which child  to insert
//            if (node->left == nullptr)
//                node->left = new HNode<Key, Item>(key, data, size);
//            else
//                node->right = new HNode<Key, Item>(key, data, size);
//            size++;
//        }
//        else {
//            if (size)
//            insert(node->left, key, data);
//            insert(node->right, key, data);
//        }
//    }
//            if (node->getLeftIndex() == size) {
//                node->left = new HNode<Key, Item>(key, data, size);
//                size++;
//            }
//            else if (node->getRightIndex() == size) {
//                node->right = new HNode<Key, Item>(key, data, size);
//                size++;
//            }
//            else {
//                insert(node->left, key, data);
//                insert(node->right, key, data);
//            }
}

/**
 * Retrieves and removes the root of the heap
 * @tparam Key
 * @tparam Data
 * @return
 */
template<typename Key, typename Data>
Data PHeap<Key, Data>::extract() {
    Data data = root->data;
    remove();
    return data;
}

/**
 * Removes the pair in the root
 * and connects the disjoint heaps
 * @tparam Key
 * @tparam Data
 * @param key
 */
template<typename Key, typename Data>
void PHeap<Key, Data>::remove() {
    // TODO
}

/**
 * Prints the heap in preorder
 * @tparam Key
 * @tparam Data
 */
template<typename Key, typename Data>
void PHeap<Key, Data>::display() const {
    display(root, cout);
}

/**
 * Prints the given node of the heap
 * in preorder traversal
 * @tparam Key
 * @tparam Data
 * @param node
 * @param out
 */
template<typename Key, typename Data>
void PHeap<Key, Data>::display(PHNode<Key, Data> *&node, ostream &out) const {
    if (node != nullptr) {
        out << *node << endl;
        display(node->left, out);
        display(node->right, out);
    }
}
