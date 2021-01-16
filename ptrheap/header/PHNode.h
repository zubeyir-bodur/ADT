/**
* Author: Zubeyir Bodur
* Date: 16.1.2021
*/
#ifndef ADT_PHNODE_H
#define ADT_PHNODE_H
#include <iostream>
using namespace std;
/**
 * PHeap Node with a key item pair
 * @tparam Key will be used for placing the node
 * @tparam Data is the data associated with the key
 * default is void if the user won't specify it
 */
template<typename Key, typename Data = void>
class PHNode {
    friend ostream& operator<<(ostream& out, const PHNode<Key, Data>& node) {
        return out << node.key << " : " << node.data;
    };
private:
    PHNode();
    ~PHNode();
    PHNode(const PHNode<Key>& node);
    PHNode(const Key& key,
           const Data& data,
           PHNode<Key, Data>* left = nullptr,
           PHNode<Key, Data>* right = nullptr,
           PHNode<Key, Data>* parent = nullptr);

    /**
     * Pointer based implementation of heaps require
     * pointers for left & right child AND parent
     *
     * This is a trade off where we choose indefinite heap size
     * over consuming much more data for each item
     *
     * For each node, the size will be 4 * 3 = 12 bytes more
     * due to the left & right ptr and parent ptr attributes
     * e.g. for a heap of size 1 million, we would pay 12MB more
     */
    PHNode<Key, Data>* left;
    PHNode<Key, Data>* right;
    PHNode<Key, Data>* parent;
    Key key;
    Data data;

    template <typename> friend class Heap;
};
#endif
