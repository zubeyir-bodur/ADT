/**
 * Author: Zubeyir Bodur
 * Date: 17.1.2021
 * Description : AVL Tree with a key-item pair
 */
#ifndef ADT_AVLTREE_H
#define ADT_AVLTREE_H
#include <iostream>
#include <string>
using namespace std;
template<typename Key, typename Item>
class AVLTree {
    friend ostream& operator<<(ostream& out, const AVLTree<Key, Item>& avlTree) {
        // TODO
        return out;
    };
public:
    AVLTree();
    ~AVLTree();
    AVLTree(const AVLTree<Key, Item>& avlTree);
    void insert(const Key& key, const Item& item);
    void remove(const Key& key);
    Item retrieve(const Key& key);
    void display();
    template<typename Function> void preorderTraverse(Function visit);
    template<typename Function> void inorderTraverse(Function visit);
    template<typename Function> void postorderTraverse(Function visit);
    AVLTree& operator=(AVLTree<Key, Item>& rvalue);

    // static functions for traversing the tree
    static void printPair(const Key& key, const int& count);
private:
    struct AVLNode {
        AVLNode* left;
        AVLNode* right;
        Key key;
        Item item;
    };
    AVLNode* root;

    void destroyTree(AVLNode<Key, Item> *& node);
    void copyTree(AVLNode<Key, Item>*& target, AVLNode<Key, Item>*& source) const;
    template<typename Function> void preorder(AVLNode<Key, Item>*& node, Function visit);
    template<typename Function> void inorder(AVLNode<Key, Item>*& node, Function visit);
    template<typename Function> void postorder(AVLNode<Key, Item>*& node, Function visit);
};
#endif
