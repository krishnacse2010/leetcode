#include <iostream>
#include "Node.h"

////////////
// NODE  ///
////////////

void Node::addChildNode(int val)
{
    if(!children.empty())
    {
        //check for duplicate values
        for(auto &child : children)
        {
            if(child!=nullptr)
            {
                if(child->value == val)
                {
                    std::cout << "Duplicate child with value '"<< val << ". Adding Child failed" << std::endl;
                    return;
                }
            }
        }
    }
    auto spChild = std::make_shared<Node>(val);
    if(spChild!=nullptr)
        children.push_back(spChild);
}

int Node::getNumChildren()
{
    return children.size();
}

///////////////////
// BINARY NODE  ///
///////////////////

void BinaryNode::printNode(std::ostream& ss)
{
    ss << "[" << getValue() << "]" << std::endl;
    if(getLeft()!=nullptr)
        ss << "   Left-->[" << getLeft()->getValue() << "]" << std::endl;
    if(getRight()!=nullptr)
        ss << "   Right-->[" << getRight()->getValue() << "]" << std::endl;
}

#ifdef __TEST_NODE__
int main()
{
    Node n(10);
    n.printNode(std::cout);

    n.addChildNode(20);
    n.addChildNode(21);
    n.addChildNode(22);
    n.printNode(std::cout);

    std::cout << "Num Children : " << n.getNumChildren() << std::endl;

    return 0;
}

#endif

#ifdef __TEST_BINARY_NODE__
int main()
{
    BinaryNode bn(10);
    bn.addChildNode(20);
    bn.addChildNode(30);
    bn.addChildNode(40);
    bn.printNode(std::cout);
    std::cout << "Num Children : " << bn.getNumChildren() << std::endl;

    return 0;
}
#endif

