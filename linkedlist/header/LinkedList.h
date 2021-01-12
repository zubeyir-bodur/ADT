/**
 * Author: Zubeyir Bodur
 * Date: 9.1.2021
 */
#ifndef ADT_EXERCISE_LINKEDLIST_H
#define ADT_EXERCISE_LINKEDLIST_H
#include "Node.h"

template <typename T>
class LinkedList {
    friend ostream& operator<<(ostream& out, const LinkedList<T>& list) {
        list.display(out);
        return out;
    };
public:
    LinkedList();
    ~LinkedList();
    LinkedList(const LinkedList<T>& list);
    void display() const;
    void displayR() const;
    void displayReverse() const;
    bool isEmpty() const;
    int getSize() const;
    T get(int index) const;
    LinkedList<T> getReverse() const;
    void reverse();
    void reverseR();
    void addHead(const T& item);
    void addTail(const T& item);
    void insert(const T& item, int index);
    bool contains(const T& item);
    int indexOf(const T& item);
    bool removeHead();
    bool removeTail();
    void sort();

private:
    Node<T>* head;
    int size;

    void display(ostream& out) const;
    void display(const Node<T>*&) const;
    void displayReverse(const Node<T>*& node) const;
    Node<T>* getTail() const;
    Node<T>* getAddr(int index) const;
    void reverse(Node<T>*& node, Node<T>*& tail);
    void destroyList();
    void sort(Node<T>*& node);
};
#endif
