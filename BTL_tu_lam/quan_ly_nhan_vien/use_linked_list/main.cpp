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
#include "List.hpp"
#include <fstream>
using namespace std;

void menu(List &l);
void pressAnyKey();

int main()
{
    List l;
    ifstream filein;
    filein.open("./input.txt", ios::in);
    while (!filein.eof())
    {
        Employee e;
        e.read(filein);
        l.pushBack(e);
    }
    menu(l);
    filein.close();
    return 0;
}

void menu(List &l)
{
    int choose;
    bool exit = false;

    do
    {
        system("cls");
        cout << "\t+ ---------------- Chuong trinh quan ly nhan (Singly Liked List) ---------------- +";
        cout << "\n\t|   1. Xem danh sach nhan vien (nhanVien.txt)";
        cout << "\n\t|   2. Them 1 nhan vien vao danh sach";
        cout << "\n\t|   3. xoa 1 nhan vien theo ma so";
        cout << "\n\t|   4. Tim nhan vien theo ma so";
        cout << "\n\t|   5. Tim nhan vien theo ten";
        cout << "\n\t|   6. Danh sach nhan vien giam dan theo luong";
        cout << "\n\t|   7. Luu file";
        cout << "\n\t|   0. Thoat chuong trinh";
        cout << "\n\t+ ---------------------------------- Cam on <3 ---------------------------------- +";

        cout << "\n\t\t-> Nhap lua chon: ";
        cin >> choose;

        switch (choose)
        {

        case 1:
            cout << "\n\t\tXem danh sach nhan vien (tu file)\n";
            l.display();
            pressAnyKey();
            break;
        case 2:
            cout << "\n\t\tThem 1 nhan vien vao danh sach\n";
            l.add();
            pressAnyKey();
            break;
        case 3:
            cout << "\n\t\tXoa 1 nhan vien theo ma so\n";
            l.removeNodeByCode();
            pressAnyKey();
            break;
        case 4:
            cout << "\n\t\tTim kiem nhan vien theo ma so\n";
            l.findNodeByCode();
            pressAnyKey();
            break;
        case 5:
            cout << "\n\t\tTim kiem nhan vien theo ten\n";
            l.findNodeByName();
            pressAnyKey();
            break;
        case 6:
            cout << "\n\t\tDanh sach nhan vien giam dan theo luong\n";
            l.sortDescendingBySalary();
            l.display();
            pressAnyKey();
            break;
        case 7:
            cout << "\n\t\tLuu file\n";
            l.saveFile();
            pressAnyKey();
            break;
        case 0:
            cout << "\n\t\tThoat chuong trinh thanh cong\n";
            exit = true;
            pressAnyKey();
            break;
        default:
            cout
                << "\n\t\t(!) Khong hop le (!)\n";
            pressAnyKey();
            break;
        }
    } while (!exit);
}

void pressAnyKey()
{
    cout << endl;
    system("pause");
}