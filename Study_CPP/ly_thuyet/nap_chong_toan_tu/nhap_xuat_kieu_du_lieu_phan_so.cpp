#include <iostream>
#include <fstream>
using namespace std;
/*
Nạp chồng toán tử (OPERATOR OVERLOADING)
Toan tu: +, -, *, /, %, ++. --, &, &&, ||, >> , <<...
*/

// khai bao cau truc phan so
struct PhanSo
{
    int tuSo;
    int mauSo;
};

void input(PhanSo ps);
void output(PhanSo ps);
PhanSo adding(PhanSo x, PhanSo y);

// nạp chồng lại toán tử >> để nhập dữ liệu từ bàn phím vào cho kiểu dữ liệu cấu trúc
istream &
operator>>(istream &is, PhanSo &obj);

// nạp chồng lại toán tử << để xuất dữ liệu ra màn hình
ostream &operator<<(ostream &os, PhanSo obj);

// nạp chồng toán tử + để cộng trực tiếp 2 struct phân số
PhanSo operator+(PhanSo x, PhanSo y);
int main()
{
    PhanSo a;
    PhanSo b;

    cout << "\n\t\tNhap phan so" << endl;
    cin >> a;
    cout << "\n\t\tNhap phan so" << endl;
    cin >> b;
    cout << "\nKet qua" << endl;
    PhanSo c = a + b;
    cout << c;

    return 0;
}

void input(PhanSo ps)
{
    cout << "\nNhap tu so: ";
    cin >> ps.tuSo;
    cout << "\nNhap mau so: ";
    cin >> ps.mauSo;
}

void output(PhanSo ps)
{
    cout << ps.tuSo << "/" << ps.mauSo;
}

PhanSo adding(PhanSo x, PhanSo y)
{
    PhanSo z;
    if (x.mauSo == y.mauSo)
    {
        z.tuSo = x.tuSo + y.tuSo;
        z.mauSo = x.mauSo;
    }
    else
    {
        z.tuSo = (x.tuSo * y.mauSo) + (y.tuSo * x.mauSo);
        z.mauSo = x.mauSo * y.mauSo;
    }
    return z;
}

istream &operator>>(istream &is, PhanSo &obj)
{
    cout << "\nNhap tu so: ";
    is >> obj.tuSo;
    cout << "\nNhap mau so: ";
    is >> obj.mauSo;
    return is;
}

ostream &operator<<(ostream &os, PhanSo obj)
{
    os << obj.tuSo << "/" << obj.mauSo;
}

PhanSo operator+(PhanSo x, PhanSo y)
{
    PhanSo z;
    if (x.mauSo == y.mauSo)
    {
        z.tuSo = x.tuSo + y.tuSo;
        z.mauSo = x.mauSo;
    }
    else
    {
        z.tuSo = (x.tuSo * y.mauSo) + (y.tuSo * x.mauSo);
        z.mauSo = x.mauSo * y.mauSo;
    }
    return z;
}