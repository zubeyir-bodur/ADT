/**
 * Author : Zubeyir Bodur
 * Date : 19.1.2021
 * Description : Table that is designed for
 * faster lookups
 */
#ifndef ADT_AVLTABLE_H
#define ADT_AVLTABLE_H
#include "../../avltree/header/AVLTree.h"
template <typename Key, typename Item>
class AVLTable {
    typedef typename BinarySearchTree<Key, Item>::Function Function;
public:
    AVLTable();
    ~AVLTable();
    AVLTable(const AVLTable<Key, Item>& avlTable);
    bool isEmpty() const;
    int getSize() const;
    Item retrieve(const Key& key) const;
    void set(const Key& key, const Item& item);
    void insert(const Key& key, const Item& item);
    void remove(const Key& key);
    void traverse(Function visit);
protected:
    void setSize(const int& size);
private:
    AVLTree<Key, Item> table;
    int size;
};
#endif
