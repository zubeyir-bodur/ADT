/**
 * Author : Zubeyir Bodur
 * Date : 19.1.2021
 * Description : Struct for 23Tree Node in ADT
 * We can't use inheritance as left and
 * right children could also be a Three Node
 */
#ifndef ADT_THREENODE_H
#define ADT_THREENODE_H
#include <iostream>
#include <string>
#include <cmath>
using namespace std;
template<typename Key, typename Item>
struct ThreeNode {
    ThreeNode<Key, Item>* left;
    ThreeNode<Key, Item>* mid;
    ThreeNode<Key, Item>* right;
    Key smallKey, largeKey;
    Item smallItem, largeItem;
};
#endif
