#ifndef __NODE_H__
#define __NODE_H__

#include <memory>
#include <iostream>
#include <vector>

class Edge;
class Node;

class Node : public std::enable_shared_from_this<Node>
{
    public:
        Node(int value) { val = value; }
        void addEdge(std::shared_ptr<Node> dest);

        int getValue() { return val;}

        void print();
        void printShort();
        void getEdgeNodes(std::vector<std::shared_ptr<Node>>& nodes);

    private:
        std::vector<std::shared_ptr<Edge>> edges;
        int val;
};
typedef std::shared_ptr<Node> NODE;

class Edge
{
    public:
        Edge(NODE source, NODE destination)
        {
            src = source;
            dest = destination;
        }
        
        NODE getSource() {return src;}
        NODE getDestination() {return dest;}

    private:
        NODE src;
        NODE dest;
};
typedef std::shared_ptr<Edge> EDGE;


#endif
