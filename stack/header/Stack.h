/**
 * Author: Zubeyir Bodur
 * Date: 13.1.2021
 * Description: Stack that uses LL
 * head node is the stack top
 */
#ifndef ADT_EXERCISE_STACK_H
#define ADT_EXERCISE_STACK_H
#include "../../linkedlist/header/LinkedList.h"
#include "../../Exception.h"
#include <string>

template <typename T>
class Stack {
    friend ostream& operator<<(ostream& out, const Stack<T>& stack) {
        stack.display(out);
        return out;
    };
public:
    Stack();
    ~Stack();
    Stack(const Stack& stack);
    bool isEmpty() const;
    int getSize() const;
    void push(const T& item);
    T pop();
    T getTop() const noexcept(false);
    void display() const;

    Stack<T>& operator=(Stack<T>& rvalue);
private:
    LinkedList<T> list;

    void display(ostream& out) const;
};
#endif
