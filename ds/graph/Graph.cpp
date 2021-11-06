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

bool isNodePresent(std::vector<NODE>& nodes, int nodeVal)
{
    for(auto iter=nodes.begin();iter!=nodes.end();iter++)
    {
        NODE n = *iter;
        if(n!=nullptr && n->getValue() == nodeVal)
            return true;
    }
    return false;
}

void Graph::printBFS(int start)
{
    NODE startNode = nullptr;
    for(auto& iter : nodes)
    {
        if(iter->getValue() == start)
        {
            startNode = iter; 
            break;
        }
    }

    if(startNode==nullptr)
    {
        std::cout << "No node with value " << start << " found" << std::endl;
        return;
    }

    std::cout << "Printing BFS" << std::endl;
    std::vector<NODE> travel;
    int index = 0;
    travel.push_back(startNode);

    bool repeat = false;
    while(index < travel.size())
    {
        NODE n = travel[index]; 
        if(n!=nullptr)
        {
            n->printShort();
            std::vector<NODE> edgeNodes;
            n->getEdgeNodes(edgeNodes);
            for(auto& nodeIter : edgeNodes)
            {
                NODE temp = nodeIter;
                if(isNodePresent(travel,temp->getValue()) == false)
                {
                    travel.push_back(temp);
                }
            }
            edgeNodes.erase(edgeNodes.begin(),edgeNodes.end());
            edgeNodes.clear();
        }
        index++;
    }
    std::cout << std::endl;
}

void traverse(NODE n)
{
    if(n!=nullptr)
    {
        if(n->isVisited() == false)
        {
            n->printShort();
            n->setVisited();

            std::vector<NODE> reach;
            n->getEdgeNodes(reach);

            for(auto& iter : reach)
            {
                NODE temp = iter;
                traverse(temp); 
            }
        }
    }
}

void Graph::printDFS(int start)
{
    std::cout << "Printing DFS" << std::endl;
    NODE startNode = nullptr;
    for(auto& iter : nodes)
    {
        if(iter->getValue() == start)
        {
            startNode = iter; 
            break;
        }
    }

    if(startNode==nullptr)
    {
        std::cout << "No node with value " << start << " found" << std::endl;
        return;
    }

    traverse(startNode);
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
    g.addEdge(2,1);
    g.addEdge(4,2);

    g.print();
    g.printBFS(4);
    g.printDFS(4);

    return 0;
}

#endif
