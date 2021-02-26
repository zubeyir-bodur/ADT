#ifndef ADT_BINARYTREE_H
#define ADT_BINARYTREE_H
#include "../../node/header/BTNode.h"
template<typename Item>
class BinaryTree {
public:
    using bt = BinaryTree<Item>;
    using btn = BTNode<Item>;
    typedef void(*Function)(const Item&);

    BinaryTree();
    BinaryTree(const BinaryTree<Item>& copy);
    BinaryTree(const Item& rootItem);
    BinaryTree(const Item& root, const BinaryTree<Item>& left, const BinaryTree<Item>& right);
    ~BinaryTree();
    bool isEmpty() const;
    int size();
    Item getRoot() noexcept(false);
    void setRoot(Item) noexcept(false);
    void insertLeft(const Item&);
    void insertRight(const Item&);
    void attachLeftSubtree(BinaryTree<Item> &);
    void attachRightSubtree(BinaryTree<Item> &);
    void detachLeftSubtree(BinaryTree<Item> &);
    void detachRightSubtree(BinaryTree<Item> &);
    BinaryTree<Item> leftTree();
    BinaryTree<Item> rightTree();
    void preorderTraverse(Function);
    void inorderTraverse(Function);
    void postorderTraverse(Function);
    bool hasPath(int start, int end);
    bool isBalanced();
    int height();
    bool isBST();

    static void print(const Item&);
private:
    btn* root;

    static void copyTree(btn*& target, const btn*& source);
    static void destroyTree(btn*& target);
    static int size(btn*& node);
    static void preorder(btn*&, Function);
    static void inorder(btn*&, Function);
    static void postorder(btn*&, Function);
    static bool hasPath(btn*& node, int start, int end);
    static bool isBalanced(btn*& node);
    static int height(btn*& node);
    static bool isBST(btn*& node);
};
#endif