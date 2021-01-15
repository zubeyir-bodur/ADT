/**
 * Author: Zubeyir Bodur
 * Date: 14.1.2021
 */
#include "../header/TNode.h"
#include "TNode.cpp"
#include "../header/BinarySearchTree.h"
template<typename Key>
BinarySearchTree<Key>::BinarySearchTree() {
    root = nullptr;
}

template<typename Key>
BinarySearchTree<Key>::~BinarySearchTree() {
    destroyTree(root);
}

template<typename Key>
void BinarySearchTree<Key>::destroyTree(TNode<Key>*& node) {
    if (node != nullptr) {
        destroyTree(node->leftChild);
        destroyTree(node->rightChild);
        delete node;
        node = nullptr;
    }
}

template<typename Key>
BinarySearchTree<Key>::BinarySearchTree(const BinarySearchTree<Key> &bst) {
    root = nullptr;
    TNode<Key>* tmp = bst.root;
    copyTree(root, tmp);
}

template<typename Key>
void BinarySearchTree<Key>::copyTree(TNode<Key> *&target, TNode<Key> *&source) const {
    if (source != nullptr) {
        target = new TNode<Key>(*source);
        copyTree(target->rightChild, source->rightChild);
        copyTree(target->leftChild, source->leftChild);
    }
}

template<typename Key>
BinarySearchTree<Key> &BinarySearchTree<Key>::operator=(const BinarySearchTree<Key> &rvalue) {
    copyTree(this->root, rvalue.root);
    return *this;
}

template<typename Key>
bool BinarySearchTree<Key>::isEmpty() const {
    return root == nullptr;
}

template<typename Key>
void BinarySearchTree<Key>::insert(const Key &key) {
    insert(key, root);
}

template<typename Key>
void BinarySearchTree<Key>::insert(const Key &key, TNode<Key> *&node) {
    if (node == nullptr)
        node = new TNode<Key>(key);
    else if (key < node->key)
        insert(key, node->leftChild);
    else if (key > node->key)
        insert(key, node->rightChild);
    else
        node->count++;
}

template<typename Key>
void BinarySearchTree<Key>::remove(const Key &key) {
    remove(key, root);
}

template<typename Key>
void BinarySearchTree<Key>::remove(const Key &key, TNode<Key> *&node) {
    if (node != nullptr) {
        if (key < node->key)
            remove(key, node->leftChild);
        else if (key > node->key)
            remove(key, node->rightChild);
        else
            removeNode(node);
    }
}

template<typename Key>
void BinarySearchTree<Key>::removeNode(TNode<Key> *&node) {
    TNode<Key>* tmp;
    if (node->isLeaf()) {
        delete node;
        node = nullptr;
    }
    else if (node->hasLeftOnly()) {
        tmp = node->leftChild;
        delete node;
        node = tmp;
    }
    else if (node->hasRightOnly()) {
        tmp = node->rightChild;
        delete node;
        node = tmp;
    }
    else if (node->hasTwo()) {
        tmp = findLeftmost(node->rightChild);
        node->key = tmp->key;
        delete tmp;
        tmp = nullptr;
    }
}

template<typename Key>
TNode<Key> *BinarySearchTree<Key>::findLeftmost(TNode<Key> *&node) {
    if (node->leftChild != nullptr)
        findLeftmost(node->leftChild);
    else
        return node;
}

/**
 * Since we don't have a data field in this BST
 * retrieve will just output the count of a key
 * @tparam Key
 * @param key
 * @return
 */
template<typename Key>
int BinarySearchTree<Key>::retrieve(const Key &key) {
    return retrieve(key, root);
}

template<typename Key>
int BinarySearchTree<Key>::retrieve(const Key &key, TNode<Key> *&node) {
    if (node != nullptr) {
        if (key < node->key)
            return retrieve(key, node->leftChild);
        else if (key > node->key)
            return retrieve(key, node->rightChild);
        else
            return node->count;
    }
    return 0;
}

/**
 * Prints the contents of the tree in sorted order
 * @tparam Key
 */
template<typename Key>
void BinarySearchTree<Key>::display() {
    void (*visit)(const Key&,const int&) = printPair;
    inorderTraverse(visit);
}

template<typename Key>
template<typename Function>
void BinarySearchTree<Key>::preorderTraverse(Function visit) {
    preorder(root, visit);
}

template<typename Key>
template<typename Function>
void BinarySearchTree<Key>::inorderTraverse(Function visit) {
    inorder(root, visit);
}

template<typename Key>
template<typename Function>
void BinarySearchTree<Key>::postorderTraverse(Function visit) {
    postorder(root, visit);
}

template<typename Key>
template<typename Function>
void BinarySearchTree<Key>::preorder(TNode<Key>*& node, Function visit) {
    if (node != nullptr) {
        visit(node->key, node->count);
        preorder(node->leftChild, visit);
        preorder(node->rightChild, visit);
    }
}

template<typename Key>
template<typename Function>
void BinarySearchTree<Key>::inorder(TNode<Key>*& node, Function visit) {
    if (node != nullptr) {
        inorder(node->leftChild, visit);
        visit(node->key, node->count);
        inorder(node->rightChild, visit);
    }
}

template<typename Key>
template<typename Function>
void BinarySearchTree<Key>::postorder(TNode<Key>*& node, Function visit) {
    if (node != nullptr) {
        postorder(node->leftChild, visit);
        postorder(node->rightChild, visit);
        visit(node->key, node->count);
    }
}

template<typename Key>
void BinarySearchTree<Key>::printPair(const Key &key, const int &count) {
    cout << key << " : " << count << endl;
}

template<typename Key>
void BinarySearchTree<Key>::printNode(TNode<Key>*& node, ostream &out) const {
    if (node != nullptr) {
        printNode(node->leftChild, out);
        out << *node << endl;
        printNode(node->rightChild, out);
    }
}

