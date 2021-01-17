/**
 * LinkedList.cpp
 * Author: Zubeyir Bodur
 * Date: 9.1.2021
 */
#include "../header/LinkedList.h"
#include "node/source/LNode.cpp"

template <typename T>
LinkedList<T>::LinkedList() {
    head = nullptr;
    size = 0;
}

template <typename T>
LinkedList<T>::~LinkedList() {
    destroyList();
}

/**
 * Private function that deletes the LL
 * Complexity: O(n)
 * @tparam T
 */
template <typename T>
void LinkedList<T>::destroyList() {
    while (removeHead()) {}
}

/**
 * Private fn that finds the tail of the LL
 * Complexity: O(n)
 * @tparam T
 * @return the address of the tail node, nullptr if LL is empty
 */
template<typename T>
LNode<T>* LinkedList<T>::getTail() const {
    if (head == nullptr)
        return nullptr;
    for (LNode<T>* cur = head; cur != nullptr; cur = cur->next) {
        if (cur->next == nullptr)
            return cur;
    }
    return nullptr;
}

/**
 * Copy constructor
 * Complexity: O(n^2)
 * @tparam T
 * @param list
 */
template <typename T>
LinkedList<T>::LinkedList(const LinkedList<T>& list) {
    head = nullptr;
    size = 0;
    if (!list.isEmpty()) {
        for (LNode<T>* cur = list.head; cur != nullptr; cur = cur->next)
            addTail(cur->item);
    }
}

/**
 * Display LL iteratively
 * @tparam T
 */
template<typename T>
void LinkedList<T>::display() const {
    display(cout);
    cout << endl;
}

template<typename T>
void LinkedList<T>::display(ostream& out) const {
    for (LNode<T>* cur = head; cur != nullptr; cur = cur->next)
        out << *cur;
}

/**
 * Display LL recursively
 * @tparam T
 */
template<typename T>
void LinkedList<T>::displayR() const {
    const LNode<T>* tmp = head;
    display(tmp);
    cout << endl;
}

/**
 * Helper recursive function for displaying LL
 * @tparam T
 */
template<typename T>
void LinkedList<T>::display(const LNode<T>*& node) const {
    if (node != nullptr) {
        cout << *node;
        const LNode<T>* tmp = node->next;
        display(tmp);
    }
}

/**
 * Display LL reverse recursively
 * @tparam T
 */
template<typename T>
void LinkedList<T>::displayReverse() const {
    const LNode<T>* tmp = head;
    displayReverse(tmp);
    cout << endl;
}

/**
 * Helper recursive function for displaying LL
 * @tparam T
 */
template<typename T>
void LinkedList<T>::displayReverse(const LNode<T>*& node) const {
    if (node != nullptr) {
        // Since the parameter is constant we need to
        // initialize a new local variable for the next item
        // since we can't dereference & assign constant pointers...
        const LNode<T>* tmp = node->next;
        displayReverse(tmp);
        if (node->next == nullptr) cout << node->item;
        else cout << " <- " << node->item;
    }
}

/**
 * Check if LL is empty
 * @tparam T
 * @return true if head is nullptr
 */
template<typename T>
bool LinkedList<T>::isEmpty() const {
    return (head == nullptr) && (size == 0);
}

/**
 * Get size of LL iteratively
 * @tparam T
 * @return size of the LL
 */
template<typename T>
int LinkedList<T>::getSize() const {
    return size;
}

/**
 * Gets the item at given index
 * @tparam T
 * @param index
 * @return the value at index
 */
template<typename T>
T LinkedList<T>::get(int index) const noexcept(false) {
    LNode<T>* addr = getAddr(index);
    if (addr == nullptr) {
        throw Exception("OutOfBoundsException");
    }
    else {
        return addr->item;
    }
}

template<typename T>
LNode<T> *LinkedList<T>::getAddr(int index) const {
    if (index < getSize() && index > -1) {
        LNode<T> *target = head;
        for (int i = 0; i < index; i++)
            target = target->next;
        return target;
    }
    return nullptr;
}

/**
 * Gives a copy of the LL in reverse order
 * @tparam T type of the item
 * @return the new reverse LL
 */
template<typename T>
LinkedList<T> LinkedList<T>::getReverse() const {
    auto list = LinkedList<T>();
    for (LNode<T>* cur = head; cur != nullptr; cur = cur->next)
        list.addHead(cur->item);
    return list;
}

/**
 * Reverses the linked list iteratively
 * @tparam T
 */
template<typename T>
void LinkedList<T>::reverse() {
    LNode<T>* tail = getTail();
    LNode<T>* tmp = head;
    while (head != tail) {
        head = head->next;
        LNode<T>* tailNext = tail->next;
        tmp->next = tailNext;
        tail->next = tmp;
        tmp = head;
    }
}

/**
 * Reverse this linked list recursively
 * @tparam T type of the item
 */
template<typename T>
void LinkedList<T>::reverseR() {
    LNode<T>* tmp = head;
    LNode<T>* tail = getTail();
    reverse(tmp, tail);
    head = tail;
}

/**
 * Recursive helper function that reverses a given linked list
 * @tparam T
 * @param node
 * @param tail
 */
template<typename T>
void LinkedList<T>::reverse(LNode<T> *&node, LNode<T> *&tail) {
    if (node != tail) {
        LNode<T>* tailNext = tail->next;
        tail->next = node;
        reverse(node->next, tail);
        node->next = tailNext;
    }
}

/**
 * Insert item from the head node
 * @tparam T T type of the item
 * @param item item to be inserted
 * @return true in successful insertion
 */
template<typename T>
void LinkedList<T>::addHead(const T &item) {
    if (head == nullptr)
        head = new LNode<T>(item);
    else {
        LNode<T>* oldHead = head;
        head = new LNode<T>(item, oldHead);
    }
    size++;
}

/**
 * Add an item to LL from its tail
 * Complexity: O(n)
 * @tparam T
 * @param item
 */
template <typename T>
void LinkedList<T>::addTail(const T &item) {
    LNode<T>* tail = getTail();
    if (tail != nullptr) // if the list is not empty
        tail->next = new LNode<T>(item);
    else
        head = new LNode<T>(item);
    size++;
}

/**
 * Inserts an item at an index
 * @tparam T
 * @param item
 * @param index
 */
template <typename T>
void LinkedList<T>::insert(const T &item, int index) noexcept(false) {
    if (index == 0) {
        LNode<T>* tmp = head;
        head = new LNode<T>(item, tmp);
    }
    else if (index < getSize() + 1 && index > 0) {
        LNode<T> *targetPrev = getAddr(index - 1);
        LNode<T> *newNode = new LNode<T>(item, targetPrev->next);
        targetPrev->next = newNode;
    }
    else
        throw Exception("OutOfBoundsException");
    size++;
}

/**
 * Checks if LL contains an item
 * @tparam T
 * @param item
 * @return
 */
template<typename T>
bool LinkedList<T>::contains(const T &item) {
    int index = indexOf(item);
    return (index > - 1) && (index < getSize());
}

/**
 * Gets the index of the first occurrence of the item
 * @tparam T
 * @param item
 * @return
 */
template<typename T>
int LinkedList<T>::indexOf(const T &item) {
    int index = 0;
    for (LNode<T>* cur = head; cur != nullptr; cur = cur->next) {
        if (cur->item == item)
            return index;
        index++;
    }
    return -1;
}

/**
 * Removes the head node
 * @tparam T
 * @return
 */
template<typename T>
bool LinkedList<T>::removeHead() {
    if (head == nullptr)
        return false;
    else if (head->next == nullptr) {
        delete head;
        head = nullptr; // solve the dangling ptr problem
        size--;
        return true;
    }
    else {
        LNode<T>* tmp = head;
        head = head->next;
        delete tmp;
        size--;
        return true;
    }
}

/**
 * Removes the tail node
 * @tparam T
 * @return
 */
template<typename T>
bool LinkedList<T>::removeTail() {
    if (size > 1) {
        LNode<T> *tailPrev = getAddr(size - 2);
        delete tailPrev->next;
        tailPrev->next = nullptr;
        size--;
        return true;
    }
    else
        return removeHead();
}

/**
 * Sorts the LL recursively using selection sort
 * @tparam T
 */
template<typename T>
void LinkedList<T>::sort() {
    sort(head);
}

/**
 * Recursive private function that sorts the LL
 * in increasing order
 * @tparam T
 */
template<typename T>
void LinkedList<T>::sort(LNode<T>*& node) {
    if (node != nullptr && node->next != nullptr) { // don't sort an empty LL or one item LL
        // find min
        LNode<T>* min = node;
        for (LNode<T>* cur = node; cur != nullptr; cur = cur->next) {
            if (cur->item < min->item)
                min = cur;
        }
        // find the node before min
        LNode<T>* minPrev = nullptr;
        for (LNode<T>* cur = node; cur != nullptr; cur = cur->next) {
            if (cur->next == min)
                minPrev = cur;
        }
        if (min != nullptr) {
            if (minPrev != nullptr) {
                LNode<T>* tmp = min->next;
                min->next = node;
                minPrev->next = tmp;
            }
            sort(min->next);
        }
        node = min; // new head node is the min node
    }
}

template<typename T>
LinkedList<T> &LinkedList<T>::operator=(const LinkedList<T> &rvalue) {
    if (this == &rvalue) // self assignment
        return *this;
    else {
        head = nullptr;
        size = 0;
        if (!rvalue.isEmpty()) {
            for (LNode<T> *cur = rvalue.head; cur != nullptr; cur = cur->next)
                addTail(cur->item);
        }
        return *this;
    }
}

