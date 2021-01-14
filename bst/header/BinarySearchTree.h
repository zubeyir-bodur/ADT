/**
 * Author: Zubeyir Bodur
 * Date: 14.1.2021
 * Description: BST that stores the frequency of the keys
 */
#ifndef ADT_EXERCISE_BINARYSEARCHTREE_H
#define ADT_EXERCISE_BINARYSEARCHTREE_H
#include "TNode.h"
template<typename Key>
class BinarySearchTree {
    friend ostream& operator<<(ostream& out, const BinarySearchTree<Key>& bst) {
        void (*visit)(const Key&, const int&, ostream&) = bst.display;
        TNode<Key>* tmp = bst.root;
        bst.inorder(tmp, visit, out);
        return out;
    };
public:
    BinarySearchTree();
    ~BinarySearchTree();
    BinarySearchTree(const BinarySearchTree<Key>& bst);
    bool isEmpty() const;
    void insert(const Key& key);
    void remove(const Key& key);
    Key retrieve() const;
    void display() const;
    template<typename Function> void preorderTraverse(Function visit);
    template<typename Function> void inorderTraverse(Function visit);
    template<typename Function> void postorderTraverse(Function visit);

    static void display(const Key& key, const int& count, ostream& out);
    static void display(const Key& key, const int& count);
    BinarySearchTree<Key>& operator=(const BinarySearchTree<Key>& rvalue);
private:
    TNode<Key>* root;
    template<typename Function> void preorder(TNode<Key>*& node, Function visit, ostream& out) const;
    template<typename Function> void inorder(TNode<Key>*& node, Function visit, ostream& out) const;
    template<typename Function> void postorder(TNode<Key>*& node, Function visit, ostream& out) const;
};
#endif
