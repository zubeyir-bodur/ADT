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
 * so we could make use of inheritance
 * @tparam Key
 * @tparam Item
 */
template<typename Key, typename Item>
class AVLTree : public BinarySearchTree<Key, Item> {
    using super = BinarySearchTree<Key, Item>;
    friend ostream& operator<<(ostream& out, const AVLTree<Key, Item>& avlTree) {
        // TODO
        return out;
    };
public:
    AVLTree();
    AVLTree(const AVLTree<Key, Item>& avlTree);
    void insert(const Key& key, const Item& item) override;
    void remove(const Key& key) override;

    // static functions for traversing the tree
    static void printPair(const Key& key, const Item& item);

    AVLTree<Key, Item>& operator=(const AVLTree<Key, Item>& rvalue);
private:
    // add helper functions
};
#endif
