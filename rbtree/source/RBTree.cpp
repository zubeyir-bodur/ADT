/**
 * Author: Zubeyir Bodur
 * Date: 19.1.2021
 * Description: Red Black Tree
 */
#include "../header/RBTree.h"

template<typename Key, typename Item>
RBTree<Key, Item>::RBTree() {
    root = nullptr;
}

template<typename Key, typename Item>
RBTree<Key, Item>::~RBTree() {
    // TODO
}

template<typename Key, typename Item>
RBTree<Key, Item>::RBTree(const RBTree<Key, Item> &bst) {
    // TODO
}

template<typename Key, typename Item>
bool RBTree<Key, Item>::isEmpty() const {
    // TODO
    return false;
}

template<typename Key, typename Item>
int RBTree<Key, Item>::getSize() const {
    // TODO
    return 0;
}

template<typename Key, typename Item>
int RBTree<Key, Item>::getHeight() const {
    // TODO
    return 0;
}

template<typename Key, typename Item>
int RBTree<Key, Item>::getBalanceFactor() const {
    // TODO
    return 0;
}

template<typename Key, typename Item>
bool RBTree<Key, Item>::isBalanced() const {
    // TODO
    return false;
}

template<typename Key, typename Item>
void RBTree<Key, Item>::insert(const Key &key, const Item &item) {
    // TODO
}

template<typename Key, typename Item>
void RBTree<Key, Item>::remove(const Key &key) {
    // TODO
}

template<typename Key, typename Item>
Item RBTree<Key, Item>::retrieve(const Key &key) {
    // TODO
    return nullptr;
}

template<typename Key, typename Item>
void RBTree<Key, Item>::display() {
    // TODO
}

template<typename Key, typename Item>
void RBTree<Key, Item>::preorderTraverse(void (*visit)(const Key &, const Item &)) {
    // TODO
}

template<typename Key, typename Item>
void RBTree<Key, Item>::inorderTraverse(void (*visit)(const Key &, const Item &)) {
    // TODO
}

template<typename Key, typename Item>
void RBTree<Key, Item>::postorderTraverse(void (*visit)(const Key &, const Item &)) {
    // TODO
}

template<typename Key, typename Item>
void RBTree<Key, Item>::destroyTree(RBNode<Key, Item> *&node) {
    // TODO
}

template<typename Key, typename Item>
void RBTree<Key, Item>::copyTree(RBNode<Key, Item> *&target, RBNode<Key, Item> *&source) {
    // TODO
}

template<typename Key, typename Item>
int RBTree<Key, Item>::getSize(RBNode<Key, Item> *&node) const {
    // TODO
    return 0;
}

template<typename Key, typename Item>
int RBTree<Key, Item>::getHeight(RBNode<Key, Item> *&node) const {
    // TODO
    return 0;
}

template<typename Key, typename Item>
int RBTree<Key, Item>::getBalanceFactor(RBNode<Key, Item> *&node) const {
    // TODO
    return 0;
}

template<typename Key, typename Item>
void RBTree<Key, Item>::insertNode(const Key &key, const Item &item, RBNode<Key, Item> *&node) {
    // TODO
}

template<typename Key, typename Item>
void RBTree<Key, Item>::removeFind(const Key &key, RBNode<Key, Item> *&node) {
    // TODO
}

template<typename Key, typename Item>
void RBTree<Key, Item>::removeNode(RBNode<Key, Item> *&node) {
    // TODO
}

template<typename Key, typename Item>
RBNode<Key, Item> *RBTree<Key, Item>::findLeftmost(RBNode<Key, Item> *&node) {
    // TODO
    return nullptr;
}

template<typename Key, typename Item>
RBNode<Key, Item> *RBTree<Key, Item>::findRightmost(RBNode<Key, Item> *&node) {
    // TODO
    return nullptr;
}

template<typename Key, typename Item>
void RBTree<Key, Item>::leftRotate(RBNode<Key, Item> *&node) {
    // TODO
}

template<typename Key, typename Item>
void RBTree<Key, Item>::rightRotate(RBNode<Key, Item> *&node) {
    // TODO
}

template<typename Key, typename Item>
Item RBTree<Key, Item>::retrieve(const Key &key, RBNode<Key, Item> *&node) {
    // TODO
    return nullptr;
}

template<typename Key, typename Item>
void RBTree<Key, Item>::display(RBNode<Key, Item> *&node, ostream &out) const {
    // TODO
}

template<typename Key, typename Item>
void RBTree<Key, Item>::preorder(RBNode<Key, Item> *&node, void (*visit)(const Key &, const Item &)) {
    // TODO
}

template<typename Key, typename Item>
void RBTree<Key, Item>::inorder(RBNode<Key, Item> *&node, void (*visit)(const Key &, const Item &)) {
    // TODO
}

template<typename Key, typename Item>
void RBTree<Key, Item>::postorder(RBNode<Key, Item> *&node, void (*visit)(const Key &, const Item &)) {
    // TODO
}

template<typename Key, typename Item>
void RBTree<Key, Item>::printPair(const Key &key, const Item &item) {
    // TODO
}

template<typename Key, typename Item>
RBTree<Key, Item> &RBTree<Key, Item>::operator=(const RBTree<Key, Item> &rvalue) {
    if (this != rvalue) {
        //TODO
    }
    return *this;
}
