#include "Employee.hpp"

class Node
{
public:
    Employee eData;
    Node *pNext;

    Node(Employee _data, Node *_pNext);
    ~Node();
};

Node::Node(Employee _data = Employee(), Node *_pNext = nullptr)
    : eData(_data), pNext(_pNext)
{
    // nothing
}

Node::~Node()
{
}