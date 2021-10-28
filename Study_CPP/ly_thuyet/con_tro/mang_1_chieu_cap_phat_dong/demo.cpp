#include <iostream>
using namespace std;

void input_array(int *a, int n)
{
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
}
void output_array(int *a, int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << a[i] << " ";
    }
}

int main()
{
    int n;
    do
    {
        system("cls");
        cout << "Nhap so luong phan tu mang: ";
        cin >> n;
        if (n <= 0)
        {
            cout << "\nSo luong phan tu mang khong hop le! Xin kiem tra lai";
            system("pause");
        }
    } while (n <= 0);
    // ! Cách 1
    // int *a;         // Khai báo ra con trỏ a - con trỏ a này có nhiệm vụ trỏ đến ô nhớ đầu tiên của mảng
    // a = new int[n]; // KHai báo mảng động có n phần tử được quản lí bởi con trỏ a

    // ! Cách 2
    int *a = new int[n]; // Khai báo ra mảng a có n phần tử

    cout << "\n\n\t\tNHAP MANG\n";
    input_array(a, n);
    cout << "\n\n\t\tXUAT MANG\n";
    output_array(a, n);

    delete[] a;

    return 0;
}
