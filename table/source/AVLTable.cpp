/**
 * Author : Zubeyir Bodur
 * Date : 19.1.2021
 */
#include "../header/AVLTable.h"

template<typename Key, typename Item>
AVLTable<Key, Item>::AVLTable() = default;

template<typename Key, typename Item>
AVLTable<Key, Item>::~AVLTable() = default;

template<typename Key, typename Item>
AVLTable<Key, Item>::AVLTable(const AVLTable<Key, Item> &avlTable) {
    table = avlTable.table;
}

template<typename Key, typename Item>
bool AVLTable<Key, Item>::isEmpty() const {
    return size == 0;
}

template<typename Key, typename Item>
int AVLTable<Key, Item>::getSize() const {
    return size;
}

template<typename Key, typename Item>
Item AVLTable<Key, Item>::retrieve(const Key& key) const {
    return table.retrieve(key);
}

template<typename Key, typename Item>
void AVLTable<Key, Item>::set(const Key &key, const Item &item) {
    table.set(key, item);
}

template<typename Key, typename Item>
void AVLTable<Key, Item>::insert(const Key &key, const Item &item) {
    table.insert(key,item);
}

template<typename Key, typename Item>
void AVLTable<Key, Item>::remove(const Key &key) {
    table.remove(key);
}

template<typename Key, typename Item>
void AVLTable<Key, Item>::traverse(Function visit) {
    table.inorderTraverse(visit);
}

template<typename Key, typename Item>
void AVLTable<Key, Item>::setSize(const int &size) {
    this->sizesize = size;
}
