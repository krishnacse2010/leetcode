#ifndef __NODE_H__
#define __NODE_H__

#include <sstream>
#include <memory>

class Node
{
    public:
        Node() { next = nullptr; value = 0; }
        //value
        int getValue() { return value;}
        void setValue(int val) { value = val; }

        //next
        void setNext(std::shared_ptr<Node> nextNode) { next = nextNode;}
        std::shared_ptr<Node> getNext() { return next;}

        //display
        void printNode(std::ostream& ss)
        {
            ss << "[" << value << "]";
            if(next!=nullptr)
                ss << "-->";
            else
                ss << "--|";
        }

    private:
    std::shared_ptr<Node> next;
    int value;
};
typedef std::shared_ptr<Node> NODE_S;
#endif
