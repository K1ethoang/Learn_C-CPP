#include <iostream>

void nhap_mang(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        std::cout << "\nNhap a[" << i << "]: ";
        std::cin >> arr[i];
    }
}

void xuat_mang(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        std::cout << arr[i] << ' ';
    }
}

void xoa_phan_tu_bat_ki_trong_mang(int arr[], int &n, int vi_tri_can_xoa)
{
    for (int i = vi_tri_can_xoa + 1; i < n; i++)
    {
        arr[i - 1] = arr[i];
    }
    n--;
}

void them_phan_tu_bat_ki_vao_mang(int arr[], int &n, int vi_tri_them, int gia_tri_them)
{
    for (int i = n; i > vi_tri_them; i--)
    {
        arr[i] = arr[i - 1];
    }
    arr[vi_tri_them] = gia_tri_them;
    n++;
}

void chuyen_phan_tu_len_dau_mang(int arr[], int n, int x)
{
    int temp;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] == x)
        {
            temp = arr[i];
            xoa_phan_tu_bat_ki_trong_mang(arr, n, i);
            them_phan_tu_bat_ki_vao_mang(arr, n, 0, temp);
        }
    }
}

int main()
{
    int n;
    std::cout << "Nhap so phan tu: ";
    std::cin >> n;
    int arr[n];
    std::cout << "\n\tNhap mang: ";
    nhap_mang(arr, n);

    std::cout << "\n\tMang da nhap: " << std::endl;
    xuat_mang(arr, n);
    int x;
    std::cout << "\nNhap x can chuyen len dau mang: ";
    std::cin >> x;

    chuyen_phan_tu_len_dau_mang(arr, n, x);
    std::cout << "\n\tSau khi xu ly: " << std::endl;
    xuat_mang(arr, n);
    return 0;
}