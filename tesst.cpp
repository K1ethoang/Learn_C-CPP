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
    int a[] = {1, 4, 5, 7};

    cout << kiemTraMaSo(a, 4, 2);
    cout << kiemTraMaSo(a, 4, 4);

    return 0;
}