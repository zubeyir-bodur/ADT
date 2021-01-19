/**
 * Author : Zubeyir Bodur
 * Date : 17.1.2021
 * Description : Struct for Node in ADT
 * This node consists of a key item pair
 */

#ifndef ADT_NODE_H
#define ADT_NODE_H
#include <iostream>
#include <string>
#include <cmath>
using namespace std;
template<typename Key, typename Item>
struct Node {
    Node<Key, Item>* left;
    Node<Key, Item>* right;
    Key key;
    Item item;
};
#endif
