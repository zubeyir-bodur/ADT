/**
 * Author: Zubeyir Bodur
 * Date: 9.1.2021
 */
#ifndef ADT_EXERCISE_LNODE_H
#define ADT_EXERCISE_LNODE_H

using namespace std;
#include <iostream>

template <typename T>
class LNode {
    friend ostream& operator<<(ostream& out, const LNode<T>& node) {
        out << node.item;
        if (node.next != nullptr)
            out << " -> ";
        return out;
    };
private:
    LNode();
    ~LNode();
    LNode(const LNode<T>& node);
    LNode(const T& item, LNode<T>* next = nullptr);

    LNode<T>& operator=(const LNode<T>& rvalue);

    LNode<T>* next;
    T item;

    template <typename> friend class LinkedList;
};
#endif
