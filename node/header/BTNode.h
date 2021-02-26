/**
 * Author : Zubeyir Bodur
 * Date : 26.2.2021
 * Description : Struct for a Binary Tree Node in ADT
 */
#ifndef ADT_BTNODE_H
#define ADT_BTNODE_H
#include <iostream>
#include <string>
#include <cmath>
using namespace std;
template<typename Item>
struct BTNode {
    BTNode<Item>* left;
    BTNode<Item>* right;
    Item item;
};
#endif