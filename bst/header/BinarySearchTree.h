/**
 * Author: Zubeyir Bodur
 * Date: 14.1.2021
 * Description: BST that stores the frequency of the keys
 */
#ifndef ADT_EXERCISE_BINARYSEARCHTREE_H
#define ADT_EXERCISE_BINARYSEARCHTREE_H
#include "TNode.h"
#include "../../Exception.h"
template<typename Key>
class BinarySearchTree {
    friend ostream& operator<<(ostream& out, const BinarySearchTree<Key>& bst) {
        TNode<Key>* tmp = bst.root;
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
    TNode<Key>* root;

    // private helper functions
    void destroyTree(TNode<Key> *& node);
    void copyTree(TNode<Key>*& target, TNode<Key>*& source) const;
    void insert(const Key& key, TNode<Key>*& node);
    void remove(const Key& key, TNode<Key>*& node);
    void removeNode(TNode<Key>*& node);
    TNode<Key>* findLeftmost(TNode<Key>*& node, TNode<Key>*& parent);
    int retrieve(const Key& key, TNode<Key>*& node);
    void printNode(TNode<Key>*& node, ostream& out) const;
    template<typename Function> void preorder(TNode<Key>*& node, Function visit);
    template<typename Function> void inorder(TNode<Key>*& node, Function visit);
    template<typename Function> void postorder(TNode<Key>*& node, Function visit);
};
#endif
