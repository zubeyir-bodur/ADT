/**
 * Author: Zubeyir Bodur
 * Date: 17.1.2021
 */
#include "../header/AVLTree.h"

template<typename Key, typename Item>
AVLTree<Key, Item>::AVLTree() {
    super::root = nullptr;
}

template<typename Key, typename Item>
AVLTree<Key, Item>::AVLTree(const AVLTree<Key, Item> &avlTree) {
    super::root = nullptr;
    Node<Key, Item>* tmp = avlTree.root;
    super::copyTree(super::root, tmp);
}

template<typename Key, typename Item>
void AVLTree<Key, Item>::insertNode(const Key &key, const Item &item, Node<Key, Item> *&node) {
    // Perform the insertion as in BST
    super::insertNode(key, item, node);
    // restore the balance
    restoreBalance(node);
}

template<typename Key, typename Item>
void AVLTree<Key, Item>::removeNode(Node<Key, Item> *&node) {
    // remove as same as BST
    super::removeNode(node);
    // restore the balance of the node
    restoreBalance(node);
}
/**
 * Restores the balance of a tree with given root
 * Complexity: O(h), where h is appx. log(n)
 * This code can be referred to the source:
 * https://www.geeksforgeeks.org/avl-tree-set-2-deletion/
 * @tparam Key
 * @tparam Item
 * @param node
 */
template<typename Key, typename Item>
void AVLTree<Key, Item>::restoreBalance(Node<Key, Item>*& node) {
    // if the removal position DNE, i.e. tree is empty
    // don't perform any rotation
    if (node != nullptr) {
        // Perform the proper rotation on the place of the insertion
        // if positive, the node is right heavy
        // if negative, the node is left heavy
        // if diff is larger than 1, it's unbalanced
        int balance = super::getBalanceFactor(node);
        int leftBalance = super::getBalanceFactor(node->left);
        int rightBalance = super::getBalanceFactor(node->right);

        // Left Left Case = Single Right Rotate
        if (balance < -1 && leftBalance <= 0)
            rightRotate(node);

        // Right Right Case = Single Left Rotate
        if (balance > 1 && rightBalance >= 0)
            leftRotate(node);

        // Left Right Case  = Double Left-Right Rotate
        if (balance < -1 && leftBalance > 0) {
            leftRotate(node->left);
            rightRotate(node);
        }

        // Right Left Case  = Double Right-Left Rotate
        if (balance > 1 && rightBalance < 0) {
            rightRotate(node->right);
            leftRotate(node);
        }
    }
}

/**
 * Left rotates the tree with root "node"
 * also assigns the new root
 * @tparam Key
 * @tparam Item
 * @param node
 * @return
 */
template<typename Key, typename Item>
void AVLTree<Key, Item>::leftRotate(Node<Key, Item> *&node) {
    Node<Key, Item>* right = node->right;
    Node<Key, Item>* rightLeft = node->right->left;
    node->right->left = node;
    node->right = rightLeft;
    node = right;
}

template<typename Key, typename Item>
void AVLTree<Key, Item>::rightRotate(Node<Key, Item> *&node) {
    Node<Key, Item>* left = node->left;
    Node<Key, Item>* leftRight = node->left->right;
    node->left->right = node;
    node->left = leftRight;
    node = left;
}

template<typename Key, typename Item>
void AVLTree<Key, Item>::printPair(const Key &key, const Item &item) {
    super::printPair(key, item);
}

template<typename Key, typename Item>
AVLTree<Key, Item>& AVLTree<Key, Item>::operator=(const AVLTree<Key, Item> &rvalue) {
    if (this != &rvalue) {
        super::destroyTree(this->root);
        super::copyTree(this->root, rvalue.root);
    }
    return *this;
}
