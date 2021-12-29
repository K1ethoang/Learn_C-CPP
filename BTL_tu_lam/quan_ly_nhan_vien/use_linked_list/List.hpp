#pragma once

#include "Node.hpp"

class List
{
private:
    Node *pHead;
    Node *pTail;
    int size;

public:
    List();
    ~List();
    Node *getHead();
    Node *getTail();
    int getSize();
    void setSize(int _newSize);
    bool isEmpty();
    bool existCode(int _code);
    void display();
    void pushBack(Employee value);
    void removeNodeHead();
    void removeNodeTail();
    void removeNodeByCode(int _code);
    void fineNodeByeCode();
    void clear();
};

List::List()
    : pHead(NULL), pTail(NULL), size(0)
{
    // nothing
}

List::~List()
{
}

Node *List::getHead()
{
    return this->pHead;
}

Node *List::getTail()
{
    return this->pTail;
}

int List::getSize()
{
    return this->size;
}

void List::setSize(int _newSize)
{
    this->size = _newSize;
}

bool List::isEmpty()
{
    if (getSize() == 0)
        return true;
    else
        return false;
}

bool List::existCode(int _code)
{
    for (Node *cur = pHead; cur != NULL; cur = cur->pNext)
    {
        if (_code == cur->eData.getCode())
            return true;
    }
    return false;
}

void List::display()
{
    int i = 1;
    Node *cur = pHead;
    while (cur != NULL)
    {
        cout << "\n\n\t\tNHAN VIEN [" << i++ << "]\n";
        cout << cur->eData;
        cur = cur->pNext;
    }
}

void List::pushBack(Employee value)
{
    Node *p = new Node(value);
    // danh sách rỗng
    if (pHead == NULL)
        pHead = pTail = p;
    else
    {
        pTail->pNext = p;
        pTail = p;
    }
    ++size;
}

void List::removeNodeHead() // xoá node đầu
{
    if (isEmpty()) // list trống
        return;
    else
    {
        Node *cur = pHead;
        pHead = pHead->pNext;
        delete cur;
    }
    --size;
}

void List::removeNodeTail() // xoá node cuối
{
    if (isEmpty())
        return;
    else if (pHead == pTail) // có 1 node
    {
        removeNodeHead();
    }
    else
    {
        for (Node *cur = pHead; cur != NULL; cur = cur->pNext)
        {
            if (cur->pNext == pTail)
            {
                delete pTail;
                cur->pNext = NULL;
                --size;
                return;
            }
        }
    }
}

void List::removeNodeByCode(int _code) // xoá theo mã số
{
    if (_code == pHead->eData.getCode())
        removeNodeHead();
    else if (_code == pTail->eData.getCode())
        removeNodeTail();
    else
    {
        Node *prev = new Node();
        for (Node *cur = pHead->pNext; cur != NULL; cur = cur->pNext)
        {
            if (_code == cur->eData.getCode())
            {
                prev->pNext = cur->pNext;
                delete cur;
                --size;
                return;
            }
            prev = cur;
        }
    }
}

void List::clear() // giải phóng bộ nhớ
{
    Node *cur = NULL;
    while (pHead != NULL)
    {
        cur = pHead;
        pHead = pHead->pNext;
        delete cur;
    }
    setSize(0);
}
