/**
 * Author: Zubeyir Bodur
 * Date: 16.1.2021
 * Description: array based implementation for a heap
 * Can be either a minheap or a maxheap.
 * By default, it's a max heap
 */
#ifndef ADT_HEAP_H
#define ADT_HEAP_H
#include <iostream>
using namespace std;
const int MAX_HEAP = 1000;
template<typename Key, typename Item>
class Heap {

    friend ostream& operator<<(ostream& out, const Heap<Key, Item>& heap) {
        heap.display(0, out);
        return out;
    };
public:
    Heap();
    ~Heap();
    Heap(const Heap<Key, Item>& heap);
    Heap(const bool& isMin);
    bool isEmpty() const;
    bool isMax() const;
    int getSize() const;
    void insert(const Key& key, const Item& item) noexcept(false);
    Item retrieve() const;
    Item extract();
    void remove();
    void display() const;
    void displayVisual() const;

    Heap<Key, Item>& operator=(const Heap<Key, Item>& rvalue);
private:
    struct Pair {
        Key key;
        Item item;
    };

    Pair data[MAX_HEAP];
    int size;
    const bool isMin;

    void heapifyUp(const int &child);
    void heapifyDown(const int &parent);
    void display(const int &root) const;
    void display(const int &root, ostream& out) const;
};
#endif
