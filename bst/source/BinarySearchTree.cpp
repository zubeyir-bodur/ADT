/**
 * Author: Zubeyir Bodur
 * Date: 14.1.2021
 */
#include "../header/BinarySearchTree.h"
template<typename T>
BinarySearchTree<T>::BinarySearchTree() {

}

template<typename T>
BinarySearchTree<T>::~BinarySearchTree() {

}

template<typename T>
BinarySearchTree<T>::BinarySearchTree(const BinarySearchTree<T> &bst) {

}

template<typename T>
BinarySearchTree<T> &BinarySearchTree<T>::operator=(const BinarySearchTree<T> &rvalue) {
    return NULL;
}

template<typename Key>
bool BinarySearchTree<Key>::isEmpty() const {
    return false;
}

template<typename Key>
void BinarySearchTree<Key>::insert(const Key &key) {

}

template<typename Key>
void BinarySearchTree<Key>::remove(const Key &key) {

}

template<typename Key>
Key BinarySearchTree<Key>::retrieve() const {
    return nullptr;
}

/**
 * Prints the contents of the tree in sorted order
 * @tparam Key
 */
template<typename Key>
void BinarySearchTree<Key>::display() const {

}

template<typename Key>
template<typename Function>
void BinarySearchTree<Key>::preorderTraverse(Function visit) {
    preorder(root, visit, cout);
    cout << endl;
}

template<typename Key>
template<typename Function>
void BinarySearchTree<Key>::inorderTraverse(Function visit) {
    inorder(root, visit, cout);
    cout << endl;
}

template<typename Key>
template<typename Function>
void BinarySearchTree<Key>::postorderTraverse(Function visit) {
    postorder(root, visit, cout);
    cout << endl;
}

template<typename Key>
template<typename Function>
void BinarySearchTree<Key>::preorder(TNode<Key>*& node, Function visit, ostream& out) const {
    if (node != nullptr) {
        visit(node->key, node->count, out);
        preorder(node->leftChild, visit, out);
        preorder(node->rightChild, visit, out);
    }
}

template<typename Key>
template<typename Function>
void BinarySearchTree<Key>::inorder(TNode<Key>*& node,
                                    Function visit, ostream& out) const{
    if (node != nullptr) {
        inorder(node->leftChild, visit, out);
        visit(node->key, node->count, out);
        inorder(node->rightChild, visit, out);
    }
}

template<typename Key>
template<typename Function>
void BinarySearchTree<Key>::postorder(TNode<Key>*& node, Function visit, ostream& out) const {
    if (node != nullptr) {
        postorder(node->leftChild, visit, out);
        postorder(node->rightChild, visit, out);
        visit(node->key, node->count, out);
    }
}

template<typename Key>
void BinarySearchTree<Key>::display(const Key& key, const int& count, ostream& out) {
    out << key << " : " << count << endl;
}

template<typename Key>
void BinarySearchTree<Key>::display(const Key &key, const int &count) {
    cout << key << " : " << count << endl;
}


