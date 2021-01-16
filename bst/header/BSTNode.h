/**
 * Author: Zubeyir Bodur
 * Date: 14.1.2021
 * Description: A BST node with a count value
 */
#ifndef ADT_EXERCISE_TNODE_H
#define ADT_EXERCISE_TNODE_H
#include <iostream>
#include <string>
using namespace std;

template <typename Key>
class BSTNode {
    friend ostream& operator<<(ostream& out, const BSTNode<Key>& node) {
        node.display(out);
        return out;
    };
private:
    BSTNode();
    BSTNode(const BSTNode<Key>& tNode);
    BSTNode(const Key& key,
            const int& count = 1,
            BSTNode<Key>* leftChild = nullptr,
            BSTNode<Key>* rightChild = nullptr);
    bool isLeaf() const;
    bool hasTwo() const;
    bool hasRightOnly() const;
    bool hasLeftOnly() const;
    void display(ostream& out) const;
    BSTNode<Key>& operator=(const BSTNode<Key>& rvalue);

    BSTNode<Key>* leftChild;
    BSTNode<Key>* rightChild;
    Key key;
    int count;

    template <typename> friend class BinarySearchTree;
};
#endif
