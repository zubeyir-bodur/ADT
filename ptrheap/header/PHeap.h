/**
 * Author: Zubeyir Bodur
 * Date: 16.1.2021
 * Description: Pointer based implementation for a heap
 * Can be either a minheap or a maxheap.
 * By default, it's a max heap
 * Solution is based on the post on Stackoverflow:
 * https://stackoverflow.com/questions/19720438/is-it-possible-to-make-efficient-pointer-based-binary-heap-implementations
 */
#ifndef ADT_PHEAP_H
#define ADT_PHEAP_H
#include "PHNode.h"
template<typename Key, typename Data>
class PHeap {
    friend ostream& operator<<(ostream& out, const PHeap<Key, Data>& heap) {
        auto tmp = heap.root;
        heap.display(tmp, out);
        return out;
    };
public:
    PHeap();
    ~PHeap();
    PHeap(const PHeap<Key, Data>& heap);
    PHeap(const bool& isMin = false);
    void insert(const Key& key, const Data& data);
    Data extract();
    void remove();
    void display() const;
private:
    PHNode<Key, Data>* root;
    PHNode<Key, Data>* last;
    const bool isMin;

    void destroyHeap(PHNode<Key, Data>*& node);
    void copyHeap(PHNode<Key, Data>*& targetRoot,
                  PHNode<Key, Data>*& targetLast,
                  PHNode<Key, Data>*& source);
    void insert(PHNode<Key, Data>*& node, const Key& key, const Data& data);
    void display(PHNode<Key, Data>*& node, ostream& out) const;

};
#endif
