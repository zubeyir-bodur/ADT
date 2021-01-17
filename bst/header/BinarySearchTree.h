/**
 * Author: Zubeyir Bodur
 * Date: 14.1.2021
 * Description: BST with a key-item pair
 */
#ifndef ADT_EXERCISE_BINARYSEARCHTREE_H
#define ADT_EXERCISE_BINARYSEARCHTREE_H
#include "exception/header/Exception.h"
#include "../../node/header/Node.h"
template<typename Key, typename Item>
class BinarySearchTree {
    friend ostream& operator<<(ostream& out, const BinarySearchTree<Key, Item>& bst) {
        Node<Key, Item>* tmp = bst.root;
        bst.display(tmp, out);
        return out;
    };
public:
    BinarySearchTree();
    ~BinarySearchTree();
    BinarySearchTree(const BinarySearchTree<Key, Item>& bst);
    bool isEmpty() const;
    int getSize() const;
    virtual void insert(const Key &key, const Item &item);
    virtual void remove(const Key& key);
    Item retrieve(const Key& key);
    void display();
    void preorderTraverse(void (*)(const Key&, const Item&));
    void inorderTraverse(void (*)(const Key&, const Item&));
    void postorderTraverse(void (*)(const Key&, const Item&));

    // static functions for traversing the tree
    static void printPair(const Key& key, const Item& item);

    // overloaded operators
    BinarySearchTree<Key, Item>& operator=(const BinarySearchTree<Key, Item>& rvalue);
protected:
    // properties
    Node<Key, Item>* root;

    // private helper functions
    void destroyTree(Node<Key, Item> *& node);
    void copyTree(Node<Key, Item>*& target, Node<Key, Item>*& source);
    void insert(const Key &key, const Item &item, Node<Key, Item> *&node);
    Node<Key, Item>* remove(const Key& key, Node<Key, Item>*& node);
    Node<Key, Item>* removeNode(Node<Key, Item>*& node);
    Node<Key, Item>* findLeftmost(Node<Key, Item>*& node);
    Item retrieve(const Key& key, Node<Key, Item>*& node);
    void display(Node<Key, Item>*& node, ostream& out) const;
    void preorder(Node<Key, Item>*& node, void (*)(const Key&, const Item&));
    void inorder(Node<Key, Item>*& node, void (*)(const Key&, const Item&));
    void postorder(Node<Key, Item>*& node, void (*)(const Key&, const Item&));
};
#endif
