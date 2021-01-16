/**
 * Author: Zubeyir Bodur
 * Date: 14.1.2021
 * Description: BST that stores the frequency of the keys
 */
#ifndef ADT_EXERCISE_BINARYSEARCHTREE_H
#define ADT_EXERCISE_BINARYSEARCHTREE_H
#include "BSTNode.h"
#include "exception/header/Exception.h"
template<typename Key>
class BinarySearchTree {
    friend ostream& operator<<(ostream& out, const BinarySearchTree<Key>& bst) {
        BSTNode<Key>* tmp = bst.root;
        bst.printNode(tmp, out);
        return out;
    };
public:
    BinarySearchTree();
    ~BinarySearchTree();
    BinarySearchTree(const BinarySearchTree<Key>& bst);
    bool isEmpty() const;
    void insert(const Key& key);
    void remove(const Key& key);
    int retrieve(const Key& key);
    void display();
    template<typename Function> void preorderTraverse(Function visit);
    template<typename Function> void inorderTraverse(Function visit);
    template<typename Function> void postorderTraverse(Function visit);

    // static functions for traversing the tree
    static void printPair(const Key& key, const int& count);

    // overloaded operators
    BinarySearchTree<Key>& operator=(const BinarySearchTree<Key>& rvalue);
private:
    // properties
    BSTNode<Key>* root;

    // private helper functions
    void destroyTree(BSTNode<Key> *& node);
    void copyTree(BSTNode<Key>*& target, BSTNode<Key>*& source) const;
    void insert(const Key& key, BSTNode<Key>*& node);
    void remove(const Key& key, BSTNode<Key>*& node);
    void removeNode(BSTNode<Key>*& node);
    BSTNode<Key>* findLeftmost(BSTNode<Key>*& node, BSTNode<Key>*& parent);
    int retrieve(const Key& key, BSTNode<Key>*& node);
    void printNode(BSTNode<Key>*& node, ostream& out) const;
    template<typename Function> void preorder(BSTNode<Key>*& node, Function visit);
    template<typename Function> void inorder(BSTNode<Key>*& node, Function visit);
    template<typename Function> void postorder(BSTNode<Key>*& node, Function visit);
};
#endif
