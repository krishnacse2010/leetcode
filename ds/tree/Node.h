#ifndef __NODE_H__
#define __NODE_H__

#include <iostream>
#include <sstream>
#include <vector>
#include <memory>

#define BINARY_TREE_MAX_CHILDREN 2

class Node
{
    public:
        Node() { value = 0; }
        Node(int val) {value = val;} 
        //value
        int getValue() { return value;}
        void setValue(int val) { value = val; }

        //children
        int getNumChildren();
        std::shared_ptr<Node> getChildNode(int index);
        void addChildNode(int value);

        //display
        virtual void printNode(std::ostream& ss)
        {
            ss << "[" << value << "]";
            if(!children.empty())
            {
                ss << "-->";
                ss << "[ ";
                for(auto iter=children.begin();iter!=children.end();iter++)
                {
                    auto child = *iter;
                    ss << child->getValue() << " ";
                }
                ss << "]";
            }
            ss << std::endl;            
        }

    private:
    std::vector<std::shared_ptr<Node>> children;
    int value;
};
typedef std::shared_ptr<Node> NODE_S;

class BinaryNode : public Node
{
    public:
        BinaryNode() {left=nullptr; right=nullptr;}
        BinaryNode(int val):Node(val) {left=nullptr; right=nullptr;}

        std::shared_ptr<BinaryNode> getLeft() {return left;}
        void setLeft(std::shared_ptr<BinaryNode> node) { left = node;}
        std::shared_ptr<BinaryNode> getRight() {return right;}
        void setRight(std::shared_ptr<BinaryNode> node) { right = node;}

        void printNode(std::ostream& ss);

    private:
        std::shared_ptr<BinaryNode> left;
        std::shared_ptr<BinaryNode> right;
};
typedef std::shared_ptr<BinaryNode> BINARYNODE_S;

#endif
