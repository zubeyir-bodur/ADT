/**
 * Author: Zubeyir Bodur
 * Date: 12.1.2021
 */
#include "../header/Queue.h"

template<typename T>
Queue<T>::Queue() {}

template<typename T>
Queue<T>::~Queue() {}

template<typename T>
Queue<T>::Queue(const Queue &queue) {
    list = LinkedList<T>(queue.list);
}

template<typename T>
bool Queue<T>::isEmpty() const {
    return list.isEmpty();
}

template<typename T>
int Queue<T>::getSize() const {
    return list.getSize();
}

template<typename T>
void Queue<T>::enqueue(const T &item) {
    list.addTail(item);
}

template<typename T>
T Queue<T>::dequeue() {
    T front = getFront();
    list.removeHead();
    return front;
}

template<typename T>
T Queue<T>::getFront() const noexcept(false) {
    try {
        T top = list.get(0);
        return top;
    }
    catch (Exception exception) {
        throw Exception("No front exists, queue is empty");
    }
}

template<typename T>
void Queue<T>::display() const {
    display(cout);
    cout << endl;
}

template<typename T>
void Queue<T>::display(ostream &out) const {
    Queue<T> copy = *this;
    while (!copy.isEmpty()) {
        if (copy.getSize() == getSize())
            out << copy.dequeue();
        else
            out << " <- " << copy.dequeue();
    }
}

template<typename T>
Queue<T> &Queue<T>::operator=(const Queue<T> &rvalue) {
    if (this == &rvalue) // self assignment
        return *this;
    else
        this->list = rvalue.list; // assignment for LL is done so this works
    return *this;
}
