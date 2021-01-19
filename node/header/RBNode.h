/**
 * Author : Zubeyir Bodur
 * Date : 17.1.2021
 * Description : Struct for RedBlack Tree Node in ADT
 * This node also contains colors for
 * the left and right children
 *
 *      We can't use inheritance for RB Trees
 * because we can't be sure if the children are actually RBTree Nodes
 *      Thus, we can see that polymorphism don't work much when
 * the struct has a pointer which points to another instance of the
 * same struct
 *      https://stackoverflow.com/questions/5313322/c-cast-to-derived-class
 *          This wasn't possible, so we wouldn't be able to cast Node* into RBNode*
 *
 *      In fact, there is no other workaround for using same functions with
 *      different parameters. Even thou the overridden function's
 *      parameter is a derived class, C++ compiler treats them as different prototypes.
 *
 * Below source is a solution for such problem, thou it's skipped in this implementation
 * https://stackoverflow.com/questions/18671062/override-function-parameter-type-with-type-of-derived-class
 *
 * If BinarySearchTree class was added a derived parameter template,
 * it wouldn't quite work in par with AVL Tree
 *
 * Even if it was somehow possible to inherit RBTree as
 * derived class of BST, it would consume unnecessary data
 * since left & right pointers for Node are masked in RBNode struct
 * making stack to overflow easier for large amount of data
 */
#ifndef ADT_RBNODE_H
#define ADT_RBNODE_H
#include <iostream>
#include <string>
#include <cmath>
using namespace std;
enum Color {
    RED,
    BLACK
};
template<typename Key, typename Item>
struct RBNode {
    RBNode<Key, Item>* left;
    RBNode<Key, Item>* right;
    Key key;
    Item item;
    // having parent pointer makes operations faster
    // but if Bilkent University Professors would ask you to implement
    // this, they wouldn't want you to use a pointer to the parent :)
    // ...even if your time complexity is reduced and computations gets faster
    //RBNode<Key, Item>* parent;
    Color leftC, rightC;
};
#endif
