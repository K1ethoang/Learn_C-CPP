#pragma once

#include "Node.hpp"
#include <cstring>

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
    void removeNodeByCode();
    void removeNodeHead();
    void removeNodeTail();
    void add();
    void findNodeByCode();
    void findNodeByName();
    string splitName(const string &fullname);
    void sortDescendingBySalary();
    void swap(Employee &e1, Employee &e2);
    void saveFile();
};

List::List()
    : pHead(NULL), pTail(NULL), size(0)
{
    // nothing
}

// giải phóng vùng nhớ
List::~List()
{
    Node *t = new Node();
    while (pHead != NULL)
    {
        t = pHead;
        pHead = pHead->pNext;
        delete t;
    }
    size = 0;
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

// thêm vào cuối ds
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
                    size--;
                    return;
                }
                prev = cur;
            }
        }
    }
}

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
    size++;
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

string List::splitName(const string &fullname)
{
    string name;
    int strLength = 0;
    for (int i = fullname.length() - 1; i >= 0; i--)
    {
        strLength++;
        if (fullname[i] == ' ')
        {
            // Hoang Gia Kiet -> Kiet
            name = fullname.substr(i + 1, strLength - 1);
            break;
        }
    }
    return name;
}

void List::findNodeByName()
{
    string name;
    bool exist = false;
    cout << "\nNhap ten can tim: ";
    cin >> name;
    int i = 1;
    for (Node *cur = pHead; cur != NULL; cur = cur->pNext)
    {
        // tách tên của nhân viên
        string splitName = List::splitName(cur->eData.getFullName());
        // so sánh chuỗi ko phân biệt hoa - thường
        // c_str(): chuyển string về char
        if (stricmp(name.c_str(), splitName.c_str()) == 0)
        {
            cout << "\n\n\t\tNhan vien thu " << i++ << endl;
            cout << cur->eData;
            exist = true;
        }
    }
    if (exist == false)
        cout << "\n\n\t\tKhong tim thay!\n";
}

void List::swap(Employee &e1, Employee &e2)
{
    Employee t = e1;
    e1 = e2;
    e2 = t;
}

void List::sortDescendingBySalary()
{
    // SelectionSort
    for (Node *t = pHead; t != pTail; t = t->pNext)
    {
        Node *minPos = t;
        for (Node *k = t->pNext; k != NULL; k = k->pNext)
        {
            if (minPos->eData.getSalary() < k->eData.getSalary())
            {
                minPos = k;
            }
        }
        if (minPos != t)
        {
            swap(t->eData, minPos->eData);
        }
    }
}

void List::saveFile()
{
    string fileName, fileType, file;
    cout << "\nDat ten file can luu (viet lien - khong dau): ";
    cin >> fileName;
    cout << "\nDinh dang can luu (vd: txt,...): ";
    cin >> fileType;
    file = fileName + '.' + fileType;

    ofstream fileout;
    fileout.open(file, ios::out);
    for (Node *t = pHead; t != NULL; t = t->pNext)
    {
        t->eData.write(fileout);
        fileout << endl;
    }
    fileout.close();
}
