#include <iostream>
#include <fstream>
using namespace std;

/*
seekg(x, y)
- x: số byte cần dịch chuyển (luôn luôn là 1 con số nguyên)
    + âm: dịch về bên tay trái
    + dương: dịch về bên tay phải
- y: vị trí bắt đầu dịch
    + y = 0: đầu file
    + y = 1: vị trí hiện tại
    + y = 2: cuối file
*/

int main()
{
    ifstream filein;
    filein.open("input.txt", ios_base::in);
    filein.seekg(-3, ios::beg); // Bắt đầu dịch từ đầu file sang phải 3 byte
    int n;
    filein >> n;
    cout << n;
    filein.close();
    return 0;
}