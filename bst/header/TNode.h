/**
 * Author: Zubeyir Bodur
 * Date: 14.1.2021
 */
#ifndef ADT_EXERCISE_TNODE_H
#define ADT_EXERCISE_TNODE_H
#include <iostream>
#include <string>
using namespace std;

template <typename Key>
class TNode {
private:
    friend ostream& operator<<(ostream& out, const TNode<Key>& node) {
        return node.display(out);
    };
private:
    TNode();
    ~TNode();
    TNode(const TNode<Key>& tNode);
    TNode(const Key& key,
          const int& count = 1,
          TNode<Key>* leftChild = nullptr,
          TNode<Key>* rightChild = nullptr);
    bool isLeaf() const;
    bool hasTwo() const;
    bool hasRightOnly() const;
    bool hasLeftOnly() const;
    void display(ostream& out) const;
    TNode<Key>& operator=(const TNode<Key>& rvalue);

    TNode<Key>* leftChild;
    TNode<Key>* rightChild;
    Key key;
    int count;

    template <typename> friend class BinarySearchTree;
};
#endif
