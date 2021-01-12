/**
 * Author: Zubeyir Bodur
 * Date: 9.1.2021
 */
#ifndef ADT_EXERCISE_NODE_H
#define ADT_EXERCISE_NODE_H

using namespace std;
#include "iostream"

template <typename T>
class Node {
    friend ostream& operator<<(ostream& out, const Node<T>& node) {
        out << node.item;
        if (node.next != nullptr)
            out << " -> ";
        return out;
    };
private:
    Node();
    ~Node();
    Node(const Node<T>& node);
    Node(const T& item, Node<T>* next = nullptr);

    Node<T>& operator=(Node<T>& rvalue);

    Node<T>* next;
    T item;

    template <typename> friend class LinkedList;
};
#endif
