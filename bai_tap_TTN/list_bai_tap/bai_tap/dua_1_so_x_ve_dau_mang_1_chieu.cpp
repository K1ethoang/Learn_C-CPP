// ! Viết chương trình đưa 1 số x(x nhập từ bàn phím) về ĐẦU MẢNG 1 chiều

#include <iostream>

void input(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        std::cin >> arr[i];
    }
}

void add(int arr[], int &n, int vitrithem, int socanthem)
{
    for (int i = n; i > vitrithem; i--)
    {
        arr[i] = arr[i - 1];
    }
    arr[vitrithem] = socanthem;
    n++;
}

void del(int arr[], int &n, int vitrixoa)
{
    for (int i = vitrixoa; i < n; i++)
    {
        arr[i] = arr[i + 1];
    }
    n--;
}

void dua_x_ve_dau_mang(int arr[], int n, int x)
{
    for (int i = 0; i < n; i++)
    {
        if (x == arr[i])
        {
            int temp = arr[i];
            //b1: xoa phan tu tai vi tri i (phan tu x can dua ve dau mang)
            del(arr, n, i);
            //b2: them phan tu vua xoa ve dau mang
            add(arr, n, 0, temp);
        }
    }
}

void output(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        std::cout << arr[i] << ' ';
    }
}
int main()
{
    int n;
    std::cout << "Nhap n: ";
    std::cin >> n;
    int arr[n];
    std::cout << "Nhap gia tri mang: ";
    input(arr, n);
    int x;
    std::cout << "Nhap x: ";
    std::cin >> x;

    dua_x_ve_dau_mang(arr, n, x);
    output(arr, n);

    return 0;
}