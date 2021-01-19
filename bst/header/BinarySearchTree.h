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
    typedef  void (*Function)(const Key&, const Item&);
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
    int getHeight() const;
    int getBalanceFactor() const;
    bool isBalanced() const;
    virtual void insert(const Key &key, const Item &item);
    virtual void remove(const Key& key);
    Item retrieve(const Key& key) const;
    void set(const Key& key, const Item& item);
    void display();
    void preorderTraverse(Function visit);
    void inorderTraverse(Function visit);
    void postorderTraverse(Function visit);

    // static functions for traversing the tree
    static void printPair(const Key& key, const Item& item);

    // overloaded operators
    BinarySearchTree<Key, Item>& operator=(const BinarySearchTree<Key, Item>& rvalue);
protected:
    // properties
    Node<Key, Item>* root;

    // protected helper functions
    void destroyTree(Node<Key, Item> *& node);
    void copyTree(Node<Key, Item>*& target, Node<Key, Item>*& source);
    int getSize(Node<Key, Item> *& node) const;
    int getHeight(Node<Key, Item> *& node) const;
    int getBalanceFactor(Node<Key, Item> *& node) const;
    virtual void insertNode(const Key &key, const Item &item, Node<Key, Item> *&node);
    virtual void removeFind(const Key& key, Node<Key, Item>*& node);
    virtual void removeNode(Node<Key, Item>*& node);
    Node<Key, Item>* findLeftmost(Node<Key, Item>*& node);
    Node<Key, Item>* findRightmost(Node<Key, Item>*& node);
    Item retrieve(const Key& key, Node<Key, Item>*& node);
    void set(const Key& key, const Item& item, Node<Key, Item>*& node);
    void display(Node<Key, Item>*& node, ostream& out) const;
    void preorder(Node<Key, Item>*& node, Function visit);
    void inorder(Node<Key, Item>*& node, Function visit);
    void postorder(Node<Key, Item>*& node, Function visit);
};
#endif
