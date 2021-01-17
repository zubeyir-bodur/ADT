/**
 * Author: Zubeyir Bodur
 * Date: 14.1.2021
 */
#include "../header/BinarySearchTree.h"

template<typename Key, typename Item>
BinarySearchTree<Key, Item>::BinarySearchTree() {
    root = nullptr;
}

template<typename Key, typename Item>
BinarySearchTree<Key, Item>::~BinarySearchTree() {
    destroyTree(root);
}

template<typename Key, typename Item>
void BinarySearchTree<Key, Item>::destroyTree(Node<Key, Item>*& node) {
    if (node != nullptr) {
        destroyTree(node->left);
        destroyTree(node->right);
        delete node;
        node = nullptr;
    }
}

template<typename Key, typename Item>
BinarySearchTree<Key, Item>::BinarySearchTree(const BinarySearchTree<Key, Item> &bst) {
    root = nullptr;
    Node<Key, Item>* tmp = bst.root;
    copyTree(root, tmp);
}

template<typename Key, typename Item>
void BinarySearchTree<Key, Item>::copyTree(Node<Key, Item> *&target, Node<Key, Item> *&source) {
    if (source != nullptr) {
        target = new Node<Key, Item>;
        target->key = source->key;
        target->item = source->item;
        target->left = nullptr;
        target->right = nullptr;
        copyTree(target->left, source->left);
        copyTree(target->right, source->right);
    }
}

template<typename Key, typename Item>
BinarySearchTree<Key, Item> &BinarySearchTree<Key, Item>::operator=(const BinarySearchTree<Key, Item> &rvalue) {
    if (this != &rvalue) {
        destroyTree(this->root);
        copyTree(this->root, rvalue.root);
    }
    return *this;
}

template<typename Key, typename Item>
bool BinarySearchTree<Key, Item>::isEmpty() const {
    return root == nullptr;
}

template<typename Key, typename Item>
int BinarySearchTree<Key, Item>::getSize() const {
    return 0;
}

template<typename Key, typename Item>
void BinarySearchTree<Key, Item>::insert(const Key &key, const Item &item) {
    insert(key, item, root);
}

template<typename Key, typename Item>
void BinarySearchTree<Key, Item>::insert(const Key &key, const Item &item, Node<Key, Item> *&node) {
    if (node == nullptr) {
        node = new Node<Key, Item>;
        node->key = key;
        node->item = item;
        node->left = nullptr;
        node->right = nullptr;
    }
    else if (key < node->key)
        insert(key, item, node->left);
    else if (key > node->key)
        insert(key, item, node->right);
}

/**
 * Removes the given key from the BST
 * @tparam Key
 * @param key
 */
template<typename Key, typename Item>
void BinarySearchTree<Key, Item>::remove(const Key &key) {
    remove(key, root);
}

/**
 * Private recursive function that finds the
 * removal position for a given key and removes the Node
 * @tparam Key
 * @param key
 * @param node
 */
template<typename Key, typename Item>
Node<Key, Item>* BinarySearchTree<Key, Item>::remove(const Key &key, Node<Key, Item> *&node) {
    if (node != nullptr) {
        if (key < node->key)
            return remove(key, node->left);
        else if (key > node->key)
            return remove(key, node->right);
        else
            return removeNode(node);
    }
    return node;
}

/**
 * Private recursive function that
 * removes a given node in bst and returns
 * the new value of it
 * if it's a leaf node it will be null
 * if it has a single child it will return that child
 * if it has two children it will return the node,
 *      thou this won't be used at all
 *      since the case for two children that
 *      the node to be removed is
 *          either a leaf node
 *          or has only right child
 * @tparam Key
 * @param node
 */
template<typename Key, typename Item>
Node<Key, Item> * BinarySearchTree<Key, Item>::removeNode(Node<Key, Item> *&node) {
    Node<Key, Item>* tmp;
    if (node->left == nullptr && node->right == nullptr) {
        delete node;
        node = nullptr;
    }
    else if (node->left != nullptr && node->right == nullptr) {
        tmp = node->left;
        delete node;
        node = tmp;
    }
    else if (node->left == nullptr && node->right != nullptr) {
        tmp = node->right;
        delete node;
        node = tmp;
    }
    else {
        // inorder successor is leftmost child of the right child
        tmp = findLeftmost(node->right);
        node->key = tmp->key;
        node->item = tmp->item;
        // remove the target and link the right child
        node->right = removeNode(tmp);
    }
    return node;
}

/**
 * Private recursive function that
 * finds & returns the leftmost node
 * of a given node
 * @tparam Key
 * @param node
 * @return
 */
template<typename Key, typename Item>
Node<Key, Item>* BinarySearchTree<Key, Item>::findLeftmost(
        Node<Key, Item> *&node) {
    if (node != nullptr && node->left != nullptr)
        return findLeftmost(node->left);
    else
        return node;
}

/**
 * Since we don't have a data field in this BST
 * retrieve will just output the count of a key
 * @tparam Key
 * @param key
 * @return
 */
template<typename Key, typename Item>
Item BinarySearchTree<Key, Item>::retrieve(const Key &key) {
    try {
        return retrieve(key, root);
    }
    catch (Exception& e) {
        cout << e.what() << endl;
        return NULL;
    }
}

template<typename Key, typename Item>
Item BinarySearchTree<Key, Item>::retrieve(const Key &key, Node<Key, Item>*& node) {
    if (node != nullptr) {
        if (key < node->key)
            return retrieve(key, node->left);
        else if (key > node->key)
            return retrieve(key, node->right);
        else
            return node->item;
    }
    throw Exception("Key not found");
}

/**
 * Prints the contents of the tree in sorted order
 * @tparam Key
 */
template<typename Key, typename Item>
void BinarySearchTree<Key, Item>::display() {
    inorderTraverse(&printPair);
}

template<typename Key, typename Item>
void BinarySearchTree<Key, Item>::preorderTraverse(
        void (*visit)(const Key&, const Item&)) {
    preorder(root, visit);
}

/**
 * Traverses the BTS in inorder traversal
 * Applies visit function for each node like the following:
 *      visit(node->key, node->data)
 * To use it, pass the address of the function to be applied:
 *      inorderTraverse(&myFunction);
 * Note: myFunction must have the prototype:
 *      void myFunction(const Key&, const Item&);
 * Therefore, the contents of a node can't be changed using traversals:
 *      it's read only
 * @tparam Key
 * @tparam Function
 * @param visit
 */
template<typename Key, typename Item>
void BinarySearchTree<Key, Item>::inorderTraverse( void(*visit)(const Key&, const Item&) ) {
    inorder(root, visit);
}

template<typename Key, typename Item>
void BinarySearchTree<Key, Item>::postorderTraverse(void (*visit)(const Key&, const Item&)) {
    postorder(root, visit);
}

template<typename Key, typename Item>
void BinarySearchTree<Key, Item>::preorder(Node<Key, Item>*& node, void (*visit)(const Key&, const Item&)) {
    if (node != nullptr) {
        visit(node->key, node->item);
        preorder(node->left, visit);
        preorder(node->right, visit);
    }
}

template<typename Key, typename Item>
void BinarySearchTree<Key, Item>::inorder(Node<Key, Item>*& node, void (*visit)(const Key&, const Item&) ) {
    if (node != nullptr) {
        inorder(node->left, visit);
        visit(node->key, node->item);
        inorder(node->right, visit);
    }
}

template<typename Key, typename Item>
void BinarySearchTree<Key, Item>::postorder(Node<Key, Item>*& node, void (*visit)(const Key&, const Item&) ) {
    if (node != nullptr) {
        postorder(node->left, visit);
        postorder(node->right, visit);
        visit(node->key, node->item);
    }
}

template<typename Key, typename Item>
void BinarySearchTree<Key, Item>::printPair(const Key &key, const Item &item) {
    cout << key << " : " << item << endl;
}

template<typename Key, typename Item>
void BinarySearchTree<Key, Item>::display(Node<Key, Item>*& node, ostream &out) const {
    if (node != nullptr) {
        display(node->left, out);
        out << node->key << " : " << node->item << endl;
        display(node->right, out);
    }
}


