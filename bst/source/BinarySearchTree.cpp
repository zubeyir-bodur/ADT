/**
 * Author: Zubeyir Bodur
 * Date: 14.1.2021
 */
#include "../header/BinarySearchTree.h"
template<typename T>
BinarySearchTree<T>::BinarySearchTree() {
    root = nullptr;
}

template<typename T>
BinarySearchTree<T>::~BinarySearchTree() {
    destroyTree(root);
}

template<typename Key>
void BinarySearchTree<Key>::destroyTree(TNode<Key> *& node) {
    if (node != nullptr) {
        destroyTree(node->leftChild);
        destroyTree(node->rightChild);
        delete node;
        node = nullptr;
    }
}

template<typename T>
BinarySearchTree<T>::BinarySearchTree(const BinarySearchTree<T> &bst) {
    root = nullptr;
    copyTree(root, bst.root);
}

template<typename Key>
void BinarySearchTree<Key>::copyTree(TNode<Key> *&target, const TNode<Key> *&source) {
    if (source != nullptr){
        target = new TNode<Key>(source);
        copyTree(target->rightChild, source->rightChild);
        copyTree(target->leftChild, source->leftChild);
    }
}

template<typename T>
BinarySearchTree<T> &BinarySearchTree<T>::operator=(const BinarySearchTree<T> &rvalue) {
    copyTree(this->root, rvalue.root);
    return *this;
}

template<typename Key>
bool BinarySearchTree<Key>::isEmpty() const {
    return root == nullptr;
}

template<typename Key>
void BinarySearchTree<Key>::insert(const Key &key) {

}

template<typename Key>
void BinarySearchTree<Key>::remove(const Key &key) {

}

template<typename Key>
int BinarySearchTree<Key>::retrieve(const Key &key) const {
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
        out << node << endl;
        printNode(node->rightChild, out);
    }
}
