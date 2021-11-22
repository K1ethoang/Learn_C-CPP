#include <iostream>
using namespace std;

int kiemTraMaSo(int a[], int n, int maSo)
{
    for (int i = 0; i < n; i++)
    {
        if (maSo == a[i])
        {
            return i;
        }
    }
    return -1; // không có mã số trùng khớp
}
int main()
{
    char kiet;
    cin >> kiet;
    if (kiet == 'y')
    {
        cout << "dung";
    }
    else
        cout << "sai";

    return 0;
}