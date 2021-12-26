// ################################################################
// ###               Ban quyen thuoc ve K1ethoang                ###
// ################################################################
// ###      Ho Ten: Hoang Gia Kiet                               ###
// ###      MSSV: 6251071049                                     ###
// ###      Lop: CNTT K62                                        ###
// ###      Tool: VSCode              				             ###
// ###      BM CNTT - DH GIAO THONG VAN TAI TP.HCM              ###
// ###############################################################

#include <iostream>
#include <string>
#include <fstream>
using namespace std;

// =========== Khao báo cấu trúc============
struct Date
{
    int date, month, year;
};

struct Employee
{
    Employee()
    {
        this->fullName = "";
        this->code = 0;
        this->homeTown = "";
        this->DateOfBirth.date = 1;
        this->DateOfBirth.month = 1;
        this->DateOfBirth.year = 1;
        this->salaryAmountInDollar = 0.0;
    }
    string fullName, homeTown;
    int code;
    Date DateOfBirth;
    float salaryAmountInDollar;
};

struct Node
{
    Employee Data;
    Node *Next;
};

struct List
{
    Node *pHead;
    Node *pTail;
};

// nhập 1 nhân viên
void inputOneEmployee(Employee &e);
// nhập danh sách liên kết các nhân viên
void inputEmployeeLinkedList(List &l, int n);
// xuất 1 nhân viên
void outputOneEmployee(Employee e);
// xuất danh sách liên kết các nhân viên
void outputEmployeeLinkedList(List l);
// thêm 1 nhân viên
void addOneEmployee(List &l, int &n);
// kiểm tra mã nhân viên
bool checkHasCode(List l, int code);
// xoá 1 nhân viên theo mã số
void deleteOneEmployeeByCode(List &l, int &n);
// tách tên của nhân viên
string splitName(string fullName);
// tìm kiếm nhân viên theo mã số
void findEmployeeByCode(List l);
// tìm kiếm nhân viên theo tên
void findEmployeeByName(List l);
// hoán vị
void swap(Employee &e1, Employee &e2);
// sắp xếp danh sách giảm dần theo lương
void sortDescendingBySalary(List l);
// kiểm tra ngày tháng nhập vào
void checkDayOfBirth(Employee e);
// đọc 1 nhân viên
void readOneEmployee(ifstream &fileIn, Employee &e);
void importEmployees(ifstream &fileIn, List &l);

// ! ============== thao tác với node =============
// tạo danh sách liên kết các nhân viên
void createList(List &l);
// tạo 1 node nhân viên
Node *createNode(Employee x);

// * ===== Thêm =====
// thêm 1 node nhân viên vào cuối
void addEmployeeNodeInTail(List &l, Node *p);

// * ===== Xoá =====
// xoá node nhân nhân viên nằm đầu
void deleteEmployeeNodeInHead(List &l, int &n);
// xoá node nhân nhân viên nằm cuối
void deleteEmployeeNodeInTail(List &l, int &n);
// xoá 1 node nhân viên theo mã số
void deleteEmployeeNodeByCode(List &l, int &n, int code);

// * ===== giải phóng vùng nhớ ====
void freeMemory(List l);

// * ===== giao diện =====
void menu();
void pressAnyKey();

int main()
{
    menu();
    return 0;
}

void menu()
{
    int choose, n;
    List l;
    createList(l);
    bool isEnteredList = false, exit = false;

    ifstream fileIn;
    fileIn.open("./nhanVien.txt", ios::in);

    do
    {
        system("cls");
        cout << "\t+ ---------------- Chuong trinh quan ly nhan (Singly Liked List) ---------------- +";
        cout << "\n\t|   1. Them danh sach nhan vien";
        cout << "\n\t|   2. Xem danh sach nhan vien (nhanVien.txt)";
        cout << "\n\t|   3. Them 1 nhan vien vao danh sach";
        cout << "\n\t|   4. xoa 1 nhan vien theo ma so";
        cout << "\n\t|   5. Tim nhan vien theo ma so";
        cout << "\n\t|   6. Tim nhan vien theo ten";
        cout << "\n\t|   7. Danh sach nhan vien giam dan theo luong";
        cout << "\n\t|   0. Thoat chuong trinh";
        cout << "\n\t+ --------------------------------- Cam on <3 --------------------------------- +";

        cout << "\n\t\t-> Nhap lua chon: ";
        cin >> choose;

        switch (choose)
        {
        case 0:
            cout << "\n\t\tThoat chuong trinh thanh cong\n";
            exit = true;
            pressAnyKey();
            break;
        case 1:

            // while (isEnteredList)
            // {
            //     char checkAgain;
            //     cout << "\n\t\t(!) Hay chac la ban da luu lai danh sach vua nhap (!)\n";
            //     do
            //     {
            //         cout << "\n\tBan co chac la nhap lai danh sach khong? (y/n): ";
            //         cin >> checkAgain;
            //         if ((checkAgain != 'y') && (checkAgain != 'n'))
            //         {
            //             cout << "\n\tKhong hop le !";
            //             pressAnyKey();
            //         }
            //     } while ((checkAgain != 'y') && (checkAgain != 'n'));

            //     if (checkAgain == 'y')
            //         isEnteredList = false;
            //     else
            //     {
            //         isEnteredList = true;
            //         break;
            //     }
            // }

            // if (!isEnteredList) // chưa nhập danh sách
            // {
            //     isEnteredList = true;
            //     cout << "\n\t\tThem danh sach nhan vien\n";
            //     do
            //     {
            //         cout << "\nNhap so nhan vien: ";
            //         cin >> n;
            //         if (n < 1)
            //             cout << "\n\t\t(!) Nhap lai (!)\n";
            //     } while (n < 1);
            //     inputEmployeeLinkedList(l, n);
            // }
            // pressAnyKey();
            // break;
            importEmployees(fileIn, l);
            break;
        case 2:
            if (isEnteredList)
            {
                cout << "\n\t\tXem danh sach nhan vien\n";
                outputEmployeeLinkedList(l);
            }
            else
            {
                cout << "\n\t\t(!) Ban chua nhap danh sach (!)\n";
            }
            pressAnyKey();
            break;
        case 3:
            if (isEnteredList)
            {
                cout << "\n\t\tThem 1 nhan vien vao danh sach\n";
                addOneEmployee(l, n);
            }
            else
            {
                cout << "\n\t\t(!) Ban chua nhap danh sach (!)\n";
            }
            pressAnyKey();
            break;
        case 4:
            if (isEnteredList)
            {
                cout << "\n\t\tXoa 1 nhan vien theo ma so\n";
                deleteOneEmployeeByCode(l, n);
            }
            else
            {
                cout << "\n\t\t(!) Ban chua nhap danh sach (!)\n";
            }
            pressAnyKey();
            break;
        case 5:
            if (isEnteredList)
            {
                cout << "\n\t\tTim kiem nhan vien theo ma so\n";
                findEmployeeByCode(l);
            }
            else
            {
                cout << "\n\t\t(!) Ban chua nhap danh sach (!)\n";
            }
            pressAnyKey();
            break;
        case 6:
            if (isEnteredList)
            {
                cout << "\n\t\tTim kiem nhan vien theo ten\n";
                findEmployeeByName(l);
            }
            else
            {
                cout << "\n\t\t(!) Ban chua nhap danh sach (!)\n";
            }
            pressAnyKey();
            break;
        case 7:
            if (isEnteredList)
            {
                cout << "\n\t\tDanh sach nhan vien giam dan theo luong\n";
                sortDescendingBySalary(l);
                outputEmployeeLinkedList(l);
            }
            else
            {
                cout << "\n\t\t(!) Ban chua nhap danh sach (!)\n";
            }
            pressAnyKey();
            break;

        default:
            cout
                << "\n\t\t(!) Khong hop le (!)\n";
            pressAnyKey();
            break;
        }
    } while (!exit);
    fileIn.close();
    freeMemory(l);
}

void pressAnyKey()
{
    cout << "\n\n";
    system("pause");
    cout << endl;
}

void inputOneEmployee(Employee &e)
{
    cout << "\nNhap ma so nhan vien: ";
    cin >> e.code;
    fflush(stdin);
    cout << "\nNhap ho va ten: ";
    getline(cin, e.fullName);
    cout << "\nNhap que quan: ";
    getline(cin, e.homeTown);
    cout << "\nNgay sinh (dd/mm/yyyy - cach nhau boi khoang trang): ";
    cin >> e.DateOfBirth.date >> e.DateOfBirth.month >> e.DateOfBirth.year;
    cout << "\nNhap luong (don vi nghin $): ";
    cin >> e.salaryAmountInDollar;
}

void inputEmployeeLinkedList(List &l, int n)
{
    for (int i = 0; i < n; i++)
    {
        Employee e;
        cout << "\n\n\tNhan vien [" << i + 1 << "]\n";
        inputOneEmployee(e);
        do
        {
            if (checkHasCode(l, e.code)) // đã tồn tại
            {
                cout << "\n\t\t(!) Da co nhan vien voi ma so nay (!)\n";
                cout << "\n\t\t\t(!) Nhap lai (!)\n";
                cin >> e.code;
            }
        } while (checkHasCode(l, e.code));
        Node *p = createNode(e);
        addEmployeeNodeInTail(l, p);
    }
}

void outputOneEmployee(Employee e)
{
    cout << "\nMa so nhan vien: " << e.code;
    cout << "\nHo va ten: " << e.fullName;
    cout << "\nQue quan: " << e.homeTown;
    cout << "\nNgay sinh: " << e.DateOfBirth.date << "/" << e.DateOfBirth.month << "/" << e.DateOfBirth.year;
    cout << "\nLuong (dollar): " << e.salaryAmountInDollar;
}

void outputEmployeeLinkedList(List l)
{
    int i = 1;
    for (Node *t = l.pHead; t != NULL; t = t->Next)
    {
        cout << "\n\n\tNhan vien [" << i << "]\n";
        outputOneEmployee(t->Data);
        i++;
    }
}

void addOneEmployee(List &l, int &n)
{
    cout << "\n\n\tNhap thong tin nhan vien can them\n";
    Employee e;
    inputOneEmployee(e);
    do
    {
        if (checkHasCode(l, e.code))
            cout << "\n\t\t(!) Da ton tai nhan vien voi ma so nay (!)\n";
        cout << "\nNhap lai: ";
        cin >> e.code;
    } while (checkHasCode(l, e.code));

    Node *p = createNode(e);
    addEmployeeNodeInTail(l, p);
}

bool checkHasCode(List l, int code)
{
    for (Node *t = l.pHead; t != NULL; t = t->Next)
    {
        if (t->Data.code == code)
            return true;
    }
    return false;
}

void deleteOneEmployeeByCode(List &l, int &n)
{
    int code;
    cout << "\nNhap ma so nhan vien can xoa: ";
    cin >> code;
    if (checkHasCode(l, code)) // nếu có mã số này
    {
        deleteEmployeeNodeByCode(l, n, code);
        cout << "\n\n\tDa xoa thanh cong\n";
    }
    else
        cout << "\n\n\tKhong co nhan vien trung khop voi ma so nay\n";
}

void findEmployeeByCode(List l)
{
    int code;
    cout << "\nNhap ma so nhan vien can tim kiem: ";
    cin >> code;
    // duyệt qua từng node
    for (Node *t = l.pHead; t != NULL; t = t->Next)
    {
        if (t->Data.code == code)
        {
            outputOneEmployee(t->Data);
            return;
        }
    }
    cout << "\n\n\tKhong co nhan vien trung khop\n";
}

string splitName(string fullName)
{
    // vd: hoang gia kiet -> kiet
    string name = "";
    for (int i = fullName.length() - 1; i >= 0; i--) // duyệt từ cuối chuỗi
    {
        if (fullName[i - 1] == ' ') // phát hiện đằng trước là khoảng trắng
        {
            name = fullName.substr(i); // lấy chuỗi con từ vị trí i đén cuói chuỗi
            break;
        }
    }
    return name;
}

void findEmployeeByName(List l)
{
    bool isFinded = false;
    string nameNeedFind;
    cout << "\nNhap ten nhan vien can tim: ";
    cin >> nameNeedFind;

    // duyệt qua từng node
    int i = 1;
    for (Node *t = l.pHead; t != NULL; t = t->Next)
    {
        if (splitName(t->Data.fullName) == nameNeedFind)
        {
            isFinded = true;
            cout << "\n\n\tNhan vien [" << i << "]\n";
            outputOneEmployee(t->Data);
        }
        i++;
    }

    if (!isFinded)
        cout << "\n\n\tKhong tim thay nhan vien\n";
}

void swap(Employee &e1, Employee &e2)
{
    Employee temp = e1;
    e1 = e2;
    e2 = temp;
}

void sortDescendingBySalary(List l)
{
    // selection sort
    for (Node *t = l.pHead; t != NULL; t = t->Next)
    {
        Node *maxIndex = t;
        for (Node *k = t->Next; k != NULL; k = k->Next)
        {
            if (maxIndex->Data.salaryAmountInDollar < k->Data.salaryAmountInDollar)
                maxIndex = k;
        }
        if (maxIndex != t)
            swap(t->Data, maxIndex->Data);
    }
}

void checkDayOfBirth(Employee e)
{
}

void readOneEmployee(ifstream &fileIn, Employee &e)
{
    fileIn >> e.code;
    fileIn.seekg(2, ios::cur); // dịch con trỏ chỉ vị qua 2 byte

    getline(fileIn, e.fullName, ',');
    fileIn.seekg(1, ios::cur);

    getline(fileIn, e.homeTown, ',');

    fileIn >> e.DateOfBirth.date;
    fileIn.seekg(1, ios::cur);

    fileIn >> e.DateOfBirth.month;
    fileIn.seekg(1, ios::cur);

    fileIn >> e.DateOfBirth.year;
    fileIn.seekg(1, ios::cur);

    fileIn >> e.salaryAmountInDollar;
}

void importEmployees(ifstream &fileIn, List &l)
{
    while (!fileIn.eof()) // eof(): đến cuối file hay chưa -> end of file
    {
        Employee e;
        readOneEmployee(fileIn, e);
        Node *p = createNode(e);
        addEmployeeNodeInTail(l, p);
    }
}

// * ================== Node ==================

void createList(List &l)
{
    l.pHead = NULL;
    l.pTail = NULL;
}

Node *createNode(Employee x)
{
    Node *p = new Node;
    if (p == NULL)
    {
        cout << "\nKhong du bo nho de cap phat";
        return NULL;
    }
    else
    {
        p->Data = x;
        p->Next = NULL;
    }
    return p;
}

void addEmployeeNodeInTail(List &l, Node *p)
{
    if (l.pHead == NULL) // danh sách đang rỗng
        l.pHead = l.pTail = p;
    else
    {
        l.pTail->Next = p;
        l.pTail = p;
    }
}

void deleteEmployeeNodeInHead(List &l, int &n)
{
    if (l.pHead == NULL) // không có node nào
        return;          // không làm gì hết
    else
    {
        Node *g = l.pHead;       // node cần xoá
        l.pHead = l.pHead->Next; // cập nhật lại node đầu là node kế tiếp
        delete g;
        n--;
    }
}

void deleteEmployeeNodeInTail(List &l, int &n)
{
    if (l.pTail == l.pHead) // node cuối cũng là node đầu
        deleteEmployeeNodeInHead(l, n);
    else
    {
        for (Node *t = l.pHead; t != NULL; t = t->Next)
        {
            if (t->Next == l.pTail)
            {
                delete l.pTail;
                t->Next = NULL;
                l.pTail = t; // cập nhật lại node cuối là node trước node xoá
                n--;
                return;
            }
        }
    }
}

void deleteEmployeeNodeByCode(List &l, int &n, int code)
{
    if (l.pHead->Data.code == code) // node cần xoá nằm đầu
        deleteEmployeeNodeInHead(l, n);
    else if (l.pTail->Data.code == code) // node cần xoá nằm cuối
        deleteEmployeeNodeInTail(l, n);
    else // node nằm trong khoảng giữa đầu và cuôi
    {
        // duyệt qua từng node
        Node *g = new Node;
        for (Node *t = l.pHead; t != NULL; t = t->Next)
        {
            if (t->Data.code == code) // vị trí node cần xoá
            {
                Node *h = t;       // node h giữ vị trí của node càn xoá
                g->Next = h->Next; // cập nhật lại liên kết của node trước node xoá - liên kết đến node sau nó
                delete t;
                n--;
                return;
            }
            g = t; // vị trí node trước node cần xoá
        }
    }
}

void freeMemory(List l)
{
    Node *t = NULL;
    while (l.pHead != NULL)
    {
        t = l.pHead;
        l.pHead = l.pHead->Next;
        delete t;
    }
}