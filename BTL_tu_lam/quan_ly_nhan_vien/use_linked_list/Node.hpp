#include "Employee.hpp"

class Node
{
public:
    Employee eData;
    Node *pNext;

    Node(Employee _data);
    ~Node();
};

Node::Node(Employee _data = Employee())
    : eData(_data), pNext(NULL)
{
    // nothing
}

Node::~Node()
{
}