/**
 * Author : Zubeyir Bodur
 * Date : 17.1.2021
 * Description : Struct for RedBlack Tree Node in ADT
 * This node consists of a key item pair
 */

#ifndef ADT_RBNODE_H
#define ADT_RBNODE_H
#include <iostream>
#include <string>
#include <cmath>
using namespace std;
enum Color {RED, BLACK};
template<typename Key, typename Item>
struct RBNode : Node {
    Color leftC;
    Color rightC;
};
#endif
