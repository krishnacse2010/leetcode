#include "Graph.h"

Graph::Graph(std::vector<int> nodeVals)
{
    for(auto& iter : nodeVals)
    {
        NODE n = std::make_shared<Node>(iter);
        nodes.push_back(n);
    }
}

void Graph::addNode(int value)
{
    for(auto& iter : nodes)
    {
        if(iter->getValue() == value)
        {
            std::cout << "Add Failed - Duplicate node in graph" << std::endl;
            return;
        }
    }
    NODE n = std::make_shared<Node>(value);
    nodes.push_back(n);
}

void Graph::addEdge(int src, int dest)
{
    NODE source = nullptr;
    NODE destination = nullptr;
    bool flag = false;
    for(auto& iter : nodes)
    {
        if(iter->getValue() == src)
        {
            if(destination!=nullptr)
            {
                iter->addEdge(destination);
                flag = true;
            }
            else
            {
                source = iter;
            }
        }
        else if(iter->getValue() == dest)
        {
            destination = iter;
        }
    }

    if(flag == false)
    {
        if(source!=nullptr && destination!=nullptr)
            source->addEdge(destination);
    }
}

void Graph::print()
{
    for(auto& iter : nodes)
    {
        if(iter!=nullptr)
            iter->print();
    }
}

#ifdef _GRAPH_TEST_
int main()
{
    Graph g;

    g.addNode(1);
    g.addNode(2);
    g.addNode(3);
    g.addNode(4);
    g.addNode(5);

    g.addEdge(1,2);
    g.addEdge(1,3);
    g.addEdge(2,5);
    g.addEdge(3,4);
    g.addEdge(4,5);

    g.print();

    return 0;
}

#endif
