#include "Tree.h"

void BinaryTree::insertNode(int val)
{
    auto spBinaryNode = std::make_shared<BinaryNode>(val);
    if(spBinaryNode!=nullptr)
    {
        if(root!=nullptr)
        {
            BINARYNODE_S temp = root;
            BINARYNODE_S prev = nullptr;
            bool flag;
            while(temp!=nullptr)
            {
                prev = temp;
                if(val >= temp->getValue())
                {
                    temp=temp->getRight();
                    flag = true;
                }
                else
                {
                    temp=temp->getLeft();
                    flag = false;
                }
            }
            if(prev!=nullptr)
            {
                if(flag)
                    prev->setRight(spBinaryNode);
                else
                    prev->setLeft(spBinaryNode);
            }
        }
        else
        {
            root = spBinaryNode;
        }
    }
}

void BinaryTree::inorder(BINARYNODE_S node, std::ostream& ss)
{
    if(node!=nullptr)
    {
        ss << "[" << node->getValue() << "]";
        inorder(node->getLeft(),ss);
        inorder(node->getRight(),ss);
    }
}

void BinaryTree::printTree(std::ostream& ss)
{
    if(root!=nullptr)
        inorder(root,ss);
}

#ifdef __TEST_TREE__

int main()
{
    BinaryTree bt;
    bt.insertNode(10);
    bt.insertNode(5);
    bt.insertNode(20);
    bt.insertNode(22);
    bt.insertNode(19);
    bt.printTree(std::cout);

    return 0;
}

#endif
