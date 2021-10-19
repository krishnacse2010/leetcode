#include <iostream>
#include <string>

#include "Node.h"
#include "List.h"

List::List()
{
    head = nullptr;
}

NODE_S
List::addToList(int value)
{
    auto spNode = std::make_shared<Node>();
    if(spNode!=nullptr)
    {
        spNode->setValue(value);
        if(head != nullptr)
        {
            NODE_S temp = head;
            while(temp->getNext()!=nullptr)
            {
                temp = temp->getNext();
            }
            temp->setNext(spNode); 
        }
        else
        {
            head = spNode;
        }
    }
    return head;
}

NODE_S
List::removeFromList(int value)
{
    NODE_S temp = head;
    NODE_S prev = nullptr;
    if(temp!=nullptr)
    {
        if(temp->getValue() == value)
        {
            head = temp->getNext();
            temp->setNext(nullptr);
            return head;
        }
        while(temp->getNext()!=nullptr)
        {
            prev = temp;
            temp = temp->getNext(); 
            if(temp->getValue() == value)
            {
                prev->setNext(temp->getNext());
                temp->setNext(nullptr);
            }
        }
    }
    else
    {
        //Empty List
    } 

    return head;
}

NODE_S
List::removeFromListAtPos(int pos)
{
    NODE_S temp = head;
    NODE_S prev = nullptr;
    int count = 0;
    if(temp!=nullptr)
    {
        if(pos == 1)
        {
            head = temp->getNext();
            temp->setNext(nullptr);
            return head;
        }
        count++;
        while(temp->getNext()!=nullptr)
        {
            count++;
            prev = temp;
            temp = temp->getNext();
            if(count == pos)
            {
                prev->setNext(temp->getNext());
                temp->setNext(nullptr);
            }
        }
    }
    return head;
}

unsigned int
List::getSize()
{
    unsigned int count = 0;
    NODE_S temp = head;
    while(temp!=nullptr)
    {
        count++;
        temp = temp->getNext();
    }
    return count;
}

void
List::printList(std::ostream& ss)
{
    if(head!=nullptr)
    {
        ss << "Printing List:";
        NODE_S temp = head;
        while(temp!=nullptr)
        {   
            temp->printNode(ss);
            temp = temp->getNext();
        }
    }
    else
    {
        ss << "Empty List" << std::endl;
    }
    ss << std::endl;
}

int main()
{
    List myList;
    myList.printList(std::cout);
    myList.addToList(1);
    myList.addToList(2);
    myList.addToList(3);
    myList.addToList(4);
    myList.addToList(8);
    myList.printList(std::cout);
    std::cout << "Size of list is " << myList.getSize() << std::endl;
    myList.removeFromList(1);
    myList.printList(std::cout);
    myList.removeFromListAtPos(4);
    myList.printList(std::cout);
    return 0;
}
