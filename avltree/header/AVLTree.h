/**
 * Author: Zubeyir Bodur
 * Date: 17.1.2021
 * Description : AVL Tree with a key-item pair
 */
#ifndef ADT_AVLTREE_H
#define ADT_AVLTREE_H
#include "../../bst/header/BinarySearchTree.h"
#include "../../node/header/Node.h"
/**
 * AVL Tree is a BST whose balance
 * is maintained by rotation operations
 * so we can make use of inheritance
 * @tparam Key
 * @tparam Item
 */
template<typename Key, typename Item>
class AVLTree : public BinarySearchTree<Key, Item> {
    using super = BinarySearchTree<Key, Item>;
    friend ostream& operator<<(ostream& out, const AVLTree<Key, Item>& avlTree) {
        avlTree.display(super::root, out);
        return out;
    };
public:
    AVLTree();
    AVLTree(const AVLTree<Key, Item>& avlTree);

    // static functions for traversing the tree
    static void printPair(const Key& key, const Item& item);

    AVLTree<Key, Item>& operator=(const AVLTree<Key, Item>& rvalue);
private:
    // add helper functions
    void insertNode(const Key &key, const Item &item, Node<Key, Item> *&node) override;
    void removeNode(Node<Key, Item>*& node) override;
    void restoreBalance(Node<Key, Item>*& node);
    void leftRotate(Node<Key, Item>*& node);
    void rightRotate(Node<Key, Item>*& node);
};
#endif
