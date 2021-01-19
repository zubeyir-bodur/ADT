/**
 * Author: Zubeyir Bodur
 * Date: 19.1.2021
 * Description: Red Black Tree
 */
#ifndef ADT_RBTREE_H
#define ADT_RBTREE_H
#include "../../bst/header/BinarySearchTree.h"
#include "../../node/header/RBNode.h"
template<typename Key, typename Item>
class RBTree {
    friend ostream& operator<<(ostream& out, const RBTree<Key, Item>& avlTree) {
        // TODO
        return out;
    };
public:
    RBTree();
    ~RBTree();
    RBTree(const RBTree<Key, Item>& bst);
    bool isEmpty() const;
    int getSize() const;
    int getHeight() const;
    int getBalanceFactor() const;
    bool isBalanced() const;
    virtual void insert(const Key &key, const Item &item);
    virtual void remove(const Key& key);
    Item retrieve(const Key& key);
    void display();
    void preorderTraverse(void (*visit)(const Key&, const Item&));
    void inorderTraverse(void (*visit)(const Key&, const Item&));
    void postorderTraverse(void (*visit)(const Key&, const Item&));

    // static functions for traversing the tree
    static void printPair(const Key& key, const Item& item);

    RBTree<Key, Item>& operator=(const RBTree<Key, Item>& rvalue);
private:
    // properties
    RBNode<Key, Item>* root;

    // protected helper functions
    void destroyTree(RBNode<Key, Item> *& node);
    virtual void copyTree(RBNode<Key, Item>*& target, RBNode<Key, Item>*& source);
    int getSize(RBNode<Key, Item> *& node) const;
    int getHeight(RBNode<Key, Item> *& node) const;
    int getBalanceFactor(RBNode<Key, Item> *& node) const;
    virtual void insertNode(const Key &key, const Item &item, RBNode<Key, Item> *&node);
    virtual void removeFind(const Key& key, RBNode<Key, Item>*& node);
    virtual void removeNode(RBNode<Key, Item>*& node);
    RBNode<Key, Item>* findLeftmost(RBNode<Key, Item>*& node);
    RBNode<Key, Item>* findRightmost(RBNode<Key, Item>*& node);
    void leftRotate(RBNode<Key, Item>*& node);
    void rightRotate(RBNode<Key, Item>*& node);
    Item retrieve(const Key& key, RBNode<Key, Item>*& node);
    void display(RBNode<Key, Item>*& node, ostream& out) const;
    void preorder(RBNode<Key, Item>*& node, void (*visit)(const Key&, const Item&));
    void inorder(RBNode<Key, Item>*& node, void (*visit)(const Key&, const Item&));
    void postorder(RBNode<Key, Item>*& node, void (*visit)(const Key&, const Item&));
};
#endif
