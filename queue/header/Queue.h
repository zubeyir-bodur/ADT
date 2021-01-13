/**
 * Author: Zubeyir Bodur
 * Date: 12.1.2021
 * Description: Queue that uses LL
 * head node is the front of the Q
 */
#ifndef ADT_EXERCISE_QUEUE_H
#define ADT_EXERCISE_QUEUE_H
#include "../../linkedlist/header/LinkedList.h"
template <typename T>
class Queue {
    friend ostream& operator<<(ostream& out, const Queue<T>& queue) {
        queue.display(out);
        return out;
    };
public:
    Queue();
    ~Queue();
    Queue(const Queue& queue);
    bool isEmpty() const;
    int getSize() const;
    void enqueue(const T& item);
    T dequeue();
    T getFront() const noexcept(false);
    void display() const;

    Queue<T>& operator=(const Queue<T>& rvalue);
private:
    LinkedList<T> list;

    void display(ostream &out) const;
};
#endif
