/**
 * Author : Zubeyir Bodur
 * Date : 17.1.2021
 * Description : Struct for AVL Tree Node in ADT
 * This node also stores the parent node
 */

#ifndef ADT_AVLNODE_H
#define ADT_AVLNODE_H
#include "Node.h"
struct AVLNode : Node {
    // we can either store the address of the parent
    // or store the height for each node
    //AVLNode* parent;

    // We might not use height as well
    // if we have a way to compute balance factor
    // for a given pointer
    //int height;
};
#endif
