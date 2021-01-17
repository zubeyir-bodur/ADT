/**
 * Author: Zubeyir Bodur
 * Date: 17.1.2021
 * Description: heap based implementation for
 * the priority queue
 */
#include "../header/PriorityQueue.h"

template<typename Key, typename Item>
PriorityQueue<Key, Item>::PriorityQueue() = default;

template<typename Key, typename Item>
PriorityQueue<Key, Item>::~PriorityQueue() = default;

template<typename Key, typename Item>
PriorityQueue<Key, Item>::PriorityQueue(const PriorityQueue<Key, Item> &priorityQueue) {
    maxHeap = priorityQueue.maxHeap;
}

template<typename Key, typename Item>
bool PriorityQueue<Key, Item>::isEmpty() const {
    return maxHeap.isEmpty();
}

template<typename Key, typename Item>
int PriorityQueue<Key, Item>::getSize() const {
    return maxHeap.getSize();
}

template<typename Key, typename Item>
void PriorityQueue<Key, Item>::enqueue(const Key &key, const Item &item) noexcept(false) {
    maxHeap.insert(key, item);
}

template<typename Key, typename Item>
Item PriorityQueue<Key, Item>::dequeue() {
    return maxHeap.extract();
}

template<typename Key, typename Item>
Item PriorityQueue<Key, Item>::getFront() const {
    return maxHeap.retrieve();
}

template<typename Key, typename Item>
void PriorityQueue<Key, Item>::display() const {
    maxHeap.display();
}
