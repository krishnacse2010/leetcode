#include "Node.h"

void
Node::addEdge(NODE dest)
{
    if(dest != nullptr)
    {
        //check if already exists
        for(auto& edge : edges)
        {
            if(edge!=nullptr)
            {
                if(edge->getDestination() == dest)
                {
                    //Duplicate edge
                    std::cout << "Duplicate edge insertion" << std::endl;
                    return;
                }
            }
        }
        //add new edge
        EDGE edge = std::make_shared<Edge>(shared_from_this(),dest);
        edges.push_back(edge);
    }
}

void
Node::print()
{
    std::cout << "Node " << val << ":" << std::endl;
    for(auto& edge : edges)
    {
        std::cout << "   " << edge->getDestination()->getValue() << std::endl;
    }
}

void
Node::printShort()
{
    std::cout << val << " ";
}

void Node::getEdgeNodes(std::vector<NODE>& nodes)
{
    for(auto& edge : edges)
    {
        nodes.push_back(edge->getDestination());
    }
}


#ifdef _NODE_H_TEST_
int main()
{
    //Create nodes
    NODE n1 = std::make_shared<Node>(1);
    NODE n2 = std::make_shared<Node>(2);
    NODE n3 = std::make_shared<Node>(3);
    NODE n4 = std::make_shared<Node>(4);
    NODE n5 = std::make_shared<Node>(5);

    //Add edges
    //n1
    n1->addEdge(n2);
    n1->addEdge(n3);

    //n2
    n2->addEdge(n5);
    
    //n3
    n3->addEdge(n4);
    
    //n4
    n4->addEdge(n5);

    n1->print();
    n2->print();
    n3->print();
    n4->print();
    n5->print();
    
    return 0;
}
#endif
