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
    void removeNodeByCode();
    void add();
    void findNodeByCode();
    void findNodeByName();
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

<<<<<<< HEAD
void List::removeNodeByCode() // xoá theo mã số
{
    int code;
    cout << "\nNhap ma so nhan vien can xoa: ";
    cin >> code;
    if (!existCode(code))
        cout << "\nKhong ton tai ma so nhan vien nay\n";
    else
    {
        if (code == pHead->eData.getCode())
            removeNodeHead();
        else if (code == pTail->eData.getCode())
            removeNodeTail();
        else
        {
            Node *prev = new Node();
            for (Node *cur = pHead->pNext; cur != NULL; cur = cur->pNext)
            {
                if (code == cur->eData.getCode())
                {
                    prev->pNext = cur->pNext;
                    delete cur;
                    --size;
                    return;
                }
                prev = cur;
            }
            == == == =
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
>>>>>>> fabbf231852df40d6c2ed20761a25c72114aa4aa
                    }
                }
            }

<<<<<<< HEAD
            void List::add()
            {
                Employee e;
                cin >> e;
                while (existCode(e.getCode()))
                {
                    int code;
                    cout << "\n\n\t\tDa ton tai nhan vien co ma so nay!\n";
                    cout << "\nNhap lai: ";
                    cin >> code;
                    e.setCode(code);
                }
                pushBack(e);
                cout << "\n\n\t\tThem thanh cong nhan vien voi thong tin\n";
                cout << e;
            }

            void List::findNodeByCode()
            {
                int code;
                bool exist = false;
                cout << "\nNhap ma so nhan vien can tim: ";
                cin >> code;

                for (Node *cur = pHead; cur != NULL; cur = cur->pNext)
                {
                    if (code == cur->eData.getCode())
                    {
                        cout << cur->eData;
                        exist = true;
                        return;
                    }
                }
                if (exist == false)
                    cout << "\n\n\t\tKhong tim thay!\n";
            }

            void List::findNodeByName()
            {
                for (Node *cur = pHead; cur != NULL; cur = cur->pNext)
                {
                }
            }

            == == == =
>>>>>>> fabbf231852df40d6c2ed20761a25c72114aa4aa
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
