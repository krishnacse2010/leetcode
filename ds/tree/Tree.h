#ifndef __TREE_H__
#define __TREE_H__

#include "Node.h"

class BinaryTree
{
    public:
        BinaryTree() {root = nullptr;}
        
        void setRoot(BINARYNODE_S node) {root = node;}
        BINARYNODE_S getRoot() { return root;}

        void insertNode(int val);

        void removeNode(int val);

        void printTree(std::ostream& ss);
        void inorder(BINARYNODE_S node, std::ostream& ss);

        //traversals

    private:
        BINARYNODE_S root;
};

#endif
