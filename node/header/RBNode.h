/**
 * Author : Zubeyir Bodur
 * Date : 17.1.2021
 * Description : Struct for RedBlack Tree Node in ADT
 * This node also contains colors for
 * the left and right children
 */

#ifndef ADT_RBNODE_H
#define ADT_RBNODE_H
#include "Node.h"
#include <iostream>
#include <string>
#include <cmath>
using namespace std;
enum Color {
    RED,
    BLACK
};
template<typename Key, typename Item>
struct RBNode : Node {
    RBNode* parent;
    Color leftC;
    Color rightC;
};
#endif
