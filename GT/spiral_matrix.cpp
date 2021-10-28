#include <iostream>
#include <io
using namespace std;
int a[100][100];

void ma_tran_xoan_oc(int n)
{
    // 1 2 3 4 5
    // 16 17 18 19 6
    // 15 24 25 20 7
    // 14 23 22 21 8
    // 13 12 11 10 9

    int dem = 0;
    int vi_tri = 0;
    int kiem_tra = n * n; // kiem_tra == n thì out
    while (1)
    {
        for (int i = vi_tri; i < n - vi_tri; i++)
        // hàng ngang trên
        {
            dem++;
            a[vi_tri][i] = dem;
            if (kiem_tra == n)
                return;
        }
        for (int i = vi_tri + 1; i < n - vi_tri - 1; i++)
        // cột dọc bên phải
        {
            dem++;
            a[i][n - vi_tri - 1] = dem;
            if (kiem_tra == n)
                return;
        }
        for (int i = n - vi_tri - 1; i >= vi_tri; i--)
        // hàng ngang dưới
        {
            dem++;
            a[n - vi_tri - 1][i] = dem;
            if (kiem_tra == n)
                return;
        }
        for (int i = n - vi_tri - 2; i > vi_tri; i--)
        // cột dọc bên trái
        {
            dem++;
            a[i][vi_tri] = dem;
            if (kiem_tra == n)
                return;
        }
        vi_tri++;
    }
}

int main()
{
    int n;
    cin >> n;
    ma_tran_xoan_oc(n);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << a[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}