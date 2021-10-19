#ifndef __LIST_H__
#define __LIST_H__

#include <sstream>
#include "Node.h"

class List
{
    public:
        List();
        NODE_S addToList(int value);
        NODE_S removeFromList(int value);
        NODE_S removeFromListAtPos(int pos);
        unsigned int getSize();

        void printList(std::ostream& ss);
    private:
        NODE_S head; 
};

#endif
