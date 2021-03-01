#include "../header/BinaryTree.h"

template<typename Item>
BinaryTree<Item>::BinaryTree() {
    root = nullptr;
}

template<typename Item>
BinaryTree<Item>::BinaryTree(const BinaryTree<Item> &copy) {
    copyTree(root, copy.root);
}

template<typename Item>
BinaryTree<Item>::BinaryTree(const Item &rootItem) {
    root = new btn;
    root->item = rootItem;
    root->left = nullptr;
    root->right = nullptr;
}

template<typename Item>
BinaryTree<Item>::BinaryTree(const Item &root, const BinaryTree<Item> &left, const BinaryTree<Item> &right) {
    this->root = new btn;
    this->root->item = root;
    bt::copyTree(this->root->left, left.root);
    bt::copyTree(this->root->right, right.root);
}

template<typename Item>
BinaryTree<Item>::~BinaryTree() {
    bt::destroyTree(root);
}

template<typename Item>
bool BinaryTree<Item>::isEmpty() const {
    return root == nullptr;
}

template<typename Item>
int BinaryTree<Item>::size() {
    return bt::size(root);
}

template<typename Item>
int BinaryTree<Item>::size(btn *&node) {
    if (node == nullptr)
        return 0;
    else
        return 1 + bt::size(node->left) + bt::size(node->right);
}

template<typename Item>
Item BinaryTree<Item>::getRoot() noexcept(false) {
    if (root != nullptr)
        return root->item;
    else
        throw "Null Pointer Exception";
}

template<typename Item>
void BinaryTree<Item>::setRoot(Item newItem) noexcept(false) {
    if (root == nullptr)
        throw "Null Pointer Exception";
    root->item = newItem;
}

template<typename Item>
void BinaryTree<Item>::insertLeft(const Item& newItem) {
    if (root && !root->left) {
        root->left = new btn;
        root->left->item = newItem;
    }
}

template<typename Item>
void BinaryTree<Item>::insertRight(const Item& newItem) {
    if (root && !root->right) {
        root->right = new btn;
        root->right->item = newItem;
    }
}

/**
 * If the current T_left is empty, attach a BinaryTree object
 * into this tree. Since this is a move operation, the tree
 * being attached will be empty
 * @tparam Item
 * @param leftST
 */
template<typename Item>
void BinaryTree<Item>::attachLeftSubtree(BinaryTree<Item> &leftST) {
    if (root != nullptr && root->left == nullptr) {
        root->left = leftST.root;
        leftST.root = nullptr;
    }
}

template<typename Item>
void BinaryTree<Item>::attachRightSubtree(BinaryTree<Item> &rightST) {
    if (root != nullptr && root->right == nullptr) {
        root->right = rightST.root;
        rightST.root = nullptr;
    }
}

/**
 * Move the current left subtree into given binary tree object
 * Provided that target is empty
 * @tparam Item
 */
template<typename Item>
void BinaryTree<Item>::detachLeftSubtree(BinaryTree<Item> &target) {
    if (root != nullptr && target.root == nullptr) {
        target.root = root->left;
        root->left = nullptr;
    }
}

/**
 * Move the current right subtree into given binary tree object
 * Provided that target is empty
 * @tparam Item
 */
template<typename Item>
void BinaryTree<Item>::detachRightSubtree(BinaryTree<Item> &target) {
    if (root != nullptr && target.root == nullptr) {
        target.root = root->right;
        root->right = nullptr;
    }
}

template<typename Item>
BinaryTree<Item> BinaryTree<Item>::leftTree() {
    auto temp = BinaryTree<Item>();
    bt::copyTree(temp.root, root->left);
    return temp;
}

template<typename Item>
BinaryTree<Item> BinaryTree<Item>::rightTree() {
    auto temp = BinaryTree<Item>();
    bt::copyTree(temp.root, root->right);
    return temp;
}

template<typename Item>
void BinaryTree<Item>::preorderTraverse(Function visit) {
    bt::preorder(root, visit);
}

template<typename Item>
void BinaryTree<Item>::inorderTraverse(Function visit) {
    bt::inorder(root, visit);
}

template<typename Item>
void BinaryTree<Item>::postorderTraverse(Function visit) {
    bt::postorder(root, visit);
}

template<typename Item>
void BinaryTree<Item>::preorder(btn *&node, Function visit) {
    if (node) {
        visit(node->item);
        bt::preorder(node->left, visit);
        bt::preorder(node->right, visit);
    }
}

template<typename Item>
void BinaryTree<Item>::inorder(btn *&node, Function visit) {
    if (node) {
        bt::inorder(node->left, visit);
        visit(node->item);
        bt::inorder(node->right, visit);
    }
}

template<typename Item>
void BinaryTree<Item>::postorder(btn *&node, Function visit) {
    if (node) {
        bt::postorder(node->left, visit);
        bt::postorder(node->right, visit);
        visit(node->item);
    }
}

template<typename Item>
bool BinaryTree<Item>::hasPath(int start, int end) {
    return bt::hasPath(root, start, end);
}

/**
* Checks whether a given binary tree has a path from top to bottom
* that starts from int start and ends with int end
* @tparam Item
* @param node
* @param start
* @param end
* @return
*/
template<typename Item>
bool BinaryTree<Item>::hasPath(btn *&node, int start, int end) {
    if (!node)
        return false;
    else if (node && node->item == start && node->item==end)
        return true;
    else if (node->item != start) {
        return (node->left && hasPath(node->left, start, end) )
               || (node->right && hasPath(node->right, start, end) );
    }
    else if (node->item == start) {
        return (node->left && hasPath(node->left, node->left->item, end) )
               || (node->right && hasPath(node->right, node->right->item, end) );
    }
    return false;
}

template<typename Item>
void BinaryTree<Item>::copyTree(btn *&target, btn *&source) {
    if (source) {
        target = new btn;
        target->item = source->item;
        target->left = nullptr;
        target->right = nullptr;
        copyTree(target->left, source->left);
        copyTree(target->right, source->right);
    }
}

template<typename Item>
void BinaryTree<Item>::destroyTree(btn *&target) {
    if (target) {
        destroyTree(target->left);
        destroyTree(target->right);
        delete target;
        target = nullptr;
    }
}

template<typename Item>
void BinaryTree<Item>::print(const Item & item) {
    cout << item << " ";
}

template<typename Item>
int BinaryTree<Item>::height() {
    return bt::height(root);
}

template<typename Item>
int BinaryTree<Item>::height(btn *&node) {
    if (!node)
        return 0;
    else if (!node->left && !node->right)
        return 1;
    else
        return max( height(node->left), height(node->right) ) + 1;
}

template<typename Item>
bool BinaryTree<Item>::isBalanced() {
    return bt::isBalanced(root);
}

template<typename Item>
bool BinaryTree<Item>::isBalanced(btn*& node) {
    if (!node)
        return true;
    return ( abs( height(node->left) - height(node->right) ) < 2)
           && isBalanced(node->left)
           && isBalanced(node->right);
}

template<typename Item>
bool BinaryTree<Item>::isBST() {
    return bt::isBST(root, INT_MIN, INT_MAX);
}

template<typename Item>
bool BinaryTree<Item>::isBST(btn *&node, int min, int max) {
    // an empty tree is always a BST
    if (!node)
        return true;
    return (node->item > min && node->item < max)
           && isBST(node->left, min, node->item)
           && isBST(node->right, node->item, max);
}

template<typename Item>
void BinaryTree<Item>::display() {
    inorderTraverse(&print);
    cout << endl;
}

template<typename Item>
void BinaryTree<Item>::display(ostream &out, btn*& node) {
    if (node) {
        display(out, node->left);
        out << node->item << " ";
        display(out, node->right);
    }
}
