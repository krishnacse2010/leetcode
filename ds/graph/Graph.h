#ifndef _GRAPH_H_
#define _GRAPH_H_
#include "Node.h"

class Graph
{
    public:
        Graph() {} 

        Graph(std::vector<int> nodeVals);

        void addNode(int val);
        void addEdge(int src,int dest);
        void print();

    private:
        std::vector<NODE> nodes;
};

#endif
