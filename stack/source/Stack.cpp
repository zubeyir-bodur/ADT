/**
 * Author: Zubeyir Bodur
 * Date: 13.1.2021
 */
#include "../header/Stack.h"

template<typename T>
Stack<T>::Stack() {}

template<typename T>
Stack<T>::~Stack() {}

template<typename T>
Stack<T>::Stack(const Stack &stack) {
    list = LinkedList<T>(stack.list);
}

template<typename T>
bool Stack<T>::isEmpty() const {
    return list.isEmpty();
}

template<typename T>
int Stack<T>::getSize() const {
    return list.getSize();
}

template<typename T>
void Stack<T>::push(const T &item) {
    list.addHead(item);
}

template<typename T>
T Stack<T>::pop() {
    T top = getTop();
    list.removeHead();
    return top;
}

template<typename T>
T Stack<T>::getTop() const noexcept(false) {
    try {
        T top = list.get(0);
        return top;
    }
    catch (Exception exception) {
        throw Exception("No top exists, stack is empty");
    }
}

template<typename T>
Stack<T> &Stack<T>::operator=(Stack<T>& rvalue) {
    if (this == &rvalue) // self assignment
        return *this;
    else
        this->list = rvalue.list; // assignment for LL is done so this works
    return *this;
}

template<typename T>
void Stack<T>::display() const {
    display(cout);
    cout << endl;
}

template<typename T>
void Stack<T>::display(ostream &out) const {
    Stack<T> copy = *this;
    while (!copy.isEmpty()) {
        if (copy.getSize() == getSize())
            out << copy.pop() << " <- Stack Top" << endl;
        else
            out << copy.pop() << endl;
    }
}
