/**
 * Author: Zubeyir Bodur
 * Date: 17.1.2021
 * Description: heap based implementation for
 * the priority queue
 */
#ifndef ADT_PRIORITYQUEUE_H
#define ADT_PRIORITYQUEUE_H
#include "../../heap/header/Heap.h"
template<typename Key, typename Item>
class PriorityQueue {
public:
    PriorityQueue();
    ~PriorityQueue();
    PriorityQueue(const PriorityQueue<Key, Item>& priorityQueue);
    bool isEmpty() const;
    int getSize() const;
    void enqueue(const Key& key, const Item& item) noexcept(false);
    Item dequeue();
    Item getFront() const;
    void display() const;
private:
    Heap<Key, Item> maxHeap;
};
#endif
