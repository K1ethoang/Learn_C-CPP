#include <iostream>
#include <iomanip> // for std::hex, std::oct, std::dec

using namespace std;

int main()
{

    int n;
    cout << "Enter n (hexadecimal): ";
    cin >> hex >> n; // nhập số thập lục phân (hệ 16)

    cout << "Octal: " << oct << n << endl;   // xuất số bát phân (hệ 8)
    cout << "Decimal: " << dec << n << endl; // xuất số thập phân (hệ 10)

    cout << setw(5) << left << "ID";                // độ rộng 5 ký tự, canh trái ID
    cout << setw(30) << left << "Name";             // độ rộng 30 ký tự, canh trái Name
    cout << setw(20) << right << "Address" << endl; // độ rộng 20 ký tự, canh phải Address

    cout << setfill('-');            // set fill bằng ký tự '-' thay vì ' '
    cout << setw(55) << "-" << endl; // fill 55 ký tự '-'

    // reset fill bằng ký tự ' '
    cout << setfill(' ');

    // in thông tin theo format như trên
    cout << setw(5) << left << 1;
    cout << setw(30) << left << "Hoang Gia Kiet2";
    cout << setw(20) << right << "Dong Nai2" << endl;

    cout << setw(5) << left << 2;
    cout << setw(30) << left << "Hoang Gia Kiet1";
    cout << setw(20) << right << "Dong Nai1" << endl;

    cout << setw(5) << left << 3;
    cout << setw(30) << left << "Hoang Gia Kiet";
    cout << setw(20) << right << "Dong Nai" << endl;
    return 0;
}
