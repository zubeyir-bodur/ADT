/**
 * Author: Zubeyir Bodur
 * Date: 9.1.2021
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
T Queue<T>::getFront() const {
    return list.get(0);
}

template<typename T>
void Queue<T>::display() const {
    display(cout);
    cout << endl;
}

template<typename T>
void Queue<T>::display(ostream &out) const {
    Queue<T> copy = Queue<T>();
    for (int i = 0; i < getSize(); i++)
        copy.enqueue(list.get(i));
    while (!copy.isEmpty()) {
        if (copy.getSize() == getSize())
            out << copy.dequeue();
        else
            out << " <- " << copy.dequeue();
    }
}
