/**
 * Author: Zubeyir Bodur
 * Date: 16.1.2021
 */
#include <exception/header/Exception.h>
#include "../header/Heap.h"
#include <cmath>

template<typename Key, typename Item>
Heap<Key, Item>::Heap() : isMin(false){}

template<typename Key, typename Item>
Heap<Key, Item>::~Heap() = default;

template<typename Key, typename Item>
Heap<Key, Item>::Heap(const Heap<Key, Item> &heap) : isMin(heap.isMin) {
    size = heap.size;
    for (int i = 0; i < size; i++)
        data[i] = heap.data[i];
}

template<typename Key, typename Item>
Heap<Key, Item>::Heap(const bool &isMin) : isMin(isMin) {
    size = 0;
}

template<typename Key, typename Item>
bool Heap<Key, Item>::isEmpty() const {
    return size == 0;
}

template<typename Key, typename Item>
bool Heap<Key, Item>::isMax() const {
    return !isMin;
}

template<typename Key, typename Item>
int Heap<Key, Item>::getSize() const {
    return size;
}

template<typename Key, typename Item>
void Heap<Key, Item>::insert(const Key &key, const Item &item) noexcept(false) {
    if (size < MAX_HEAP) {
        data[size].key = key;
        data[size].item = item;
        size++;
        heapifyUp(size - 1);
    }
    else
        throw Exception("Max. number of items exceeded, insertion failed");
}

template<typename Key, typename Item>
Item Heap<Key, Item>::retrieve() const {
    return data[0].item;
}

template<typename Key, typename Item>
Item Heap<Key, Item>::extract() {
    Item item = retrieve();
    remove();
    return item;
}

template<typename Key, typename Item>
void Heap<Key, Item>::remove() noexcept(false) {
    if (size == 0)
        throw Exception("Heap is empty");
    else {
        data[0] = data[size - 1];
        size--;
        heapifyDown(0);
    }
}

template<typename Key, typename Item>
void Heap<Key, Item>::heapifyUp(const int &child) {
    if (child > 0) {
        int parent = (child - 1) / 2;
        bool unbalanced = isMin ?
                data[child].key < data[parent].key:
                data[child].key > data[parent].key;
        if (unbalanced) {
            Pair tmp = data[child];
            data[child] = data[parent];
            data[parent] = tmp;
            heapifyUp(parent);
        }
    }
}

template<typename Key, typename Item>
void Heap<Key, Item>::heapifyDown(const int &parent) {
    int leftChild = 2 * parent + 1;
    if (leftChild < size) {
        int rightChild = leftChild + 1;
        // find the larger child for max heap
        // find the smaller child for min heap
        bool unbalancedRight = isMin ?
                    (data[rightChild].key < data[leftChild].key) :
                    (data[rightChild].key > data[leftChild].key);
        int targetChild;
        if (rightChild < size && unbalancedRight)
            targetChild = rightChild;
        else
            targetChild = leftChild;
        // swap values if target child smaller for min heap
        // swap values if target child larger for max heap
        bool unbalanced = isMin ?
            (data[targetChild].key < data[parent].key) :
            (data[targetChild].key > data[parent].key);
        if (unbalanced) {
            Pair tmp = data[targetChild];
            data[targetChild] = data[parent];
            data[parent] = tmp;
            heapifyDown(targetChild);
        }
    }
}

template<typename Key, typename Item>
void Heap<Key, Item>::display() const {
    display(0);
}

template<typename Key, typename Item>
void Heap<Key, Item>::display(const int &node) const {
    display(node, cout);
}

template<typename Key, typename Item>
void Heap<Key, Item>::display(const int &node, ostream &out) const {
    if (node < size) {
        int curLvl = (int)(log(node + 1) / log(2));
        string tab = "";
        while (curLvl > 0) {
            tab += "\t";
            curLvl--;
        }
        cout << tab << data[node].key << " : " << data[node].item << endl;
        display(2 * node + 1, out);
        display(2 * node + 2, out);
    }
}

template<typename Key, typename Item>
void Heap<Key, Item>::displayVisual() const {
    int maxLvl = log(size) / log(2);
    int maxLvlSize = pow(2, maxLvl);
    for (int curLvlSize = 1; curLvlSize <= maxLvlSize; curLvlSize *= 2) {
        int offset = curLvlSize - 1;
        int curLvl = log(curLvlSize) / log(2);
        int diff = (maxLvl - curLvl);
        int initSpaceSize = diff * (8.5 * diff + 7);
        int btwSpaceSize = 16 * pow(2.4, diff);
        string initSpace = "";
        string btwSpace = "";
        for (int i = 0; i < initSpaceSize; i++)
            initSpace += " ";
        for (int i = 0; i < btwSpaceSize; i++)
            btwSpace += " ";
        cout << initSpace;
        for (int i = 0; i < curLvlSize; i++) {
            if (i + offset < size)
                cout << data[i + offset].key << "--" << data[i + offset].item << btwSpace;
        }
        cout << endl;
    }
}

template<typename Key, typename Item>
Heap<Key, Item> &Heap<Key, Item>::operator=(const Heap<Key, Item> &rvalue) {
    if (this != &rvalue) {
        size = rvalue.size;
        for (int i = 0; i < size; i++)
            data[i] = rvalue.data[i];
    }
    return *this;
}

