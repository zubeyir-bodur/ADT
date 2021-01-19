/**
 * Author : Zubeyir Bodur
 * Date : 19.1.2021
 * Description : Struct for 234Tree Node in ADT
 * We can't use inheritance as left, mid and
 * right children could also be a Four Node
 */
#ifndef ADT_FOURNODE_H
#define ADT_FOURNODE_H
#include <iostream>
#include <string>
#include <cmath>
using namespace std;
template<typename Key, typename Item>
struct FourNode {
    FourNode<Key, Item>* left;
    FourNode<Key, Item>* midleft;
    FourNode<Key, Item>* midright;
    FourNode<Key, Item>* right;
    Key smallKey, midKey, largeKey;
    Item smallItem, midItem, largeItem;
};
#endif
