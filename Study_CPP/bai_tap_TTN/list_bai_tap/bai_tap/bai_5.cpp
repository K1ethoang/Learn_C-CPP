// ! Đếm số lần xuất hiện của từng phần tử phân biệt trong mảng 1 chiều

#include <iostream>
#define MAX 100

void nhap_mang(int a[], int n)
{
    for (int i = 0; i < n; i++)
    {
        std::cout << "\nNhap phan tu a[" << i << "]: ";
        std::cin >> a[i];
    }
}

void xuat_mang(int a[], int n)
{
    for (int i = 0; i < n; i++)
    {
        std::cout << a[i] << ' ';
    }
}

void tim_phan_tu_phan_biet(int a[], int b[], int n, int &m)
{
    m = 0; // Phan tu dau tien cua mang a chinh la phan tu phan biet
    b[m] = a[0];
    m++;
    // * vong lap duyet tung phan tu cua mang a
    for (int i = 1; i < n; i++)
    {
        // * Duyet tung phan tu cua mang a, duyet tu vi tri i - 1 den 0
        // * <=> Duyet tu vi tri i - 1 ve dau mang, de tim xem a[i] truoc do co ton tai hay chua
        // * Neu a[i] duyet ve truoc do ma chua co ton tai -> a[i] chinh la phan tu phan biet
        bool kiem_tra = true; // gia su a[i] se la phan tu phan biet
        for (int j = i - 1; j >= 0; j--)
        {
            // * neu a[i] bang a[j] <=> a[i] da ton tai truoc do
            if (a[i] == a[j])
            {
                kiem_tra = false; // *  cap nhap lai a[i] khong phai phan tu phan biet
                break;            // dung viec kiem tra
            }
        }
        if (kiem_tra == true)
        {
            b[m] = a[i]; // * Dua phan tu phan biet vao mang b
            m++;
        }
    }
}

void xu_li(int a[], int b[], int n, int m)
{
    // * buoc 1: Tim phan tu phan biet
    tim_phan_tu_phan_biet(a, b, n, m);

    // * buoc 2: Di tim so lan xuat hien cua tung phan tu phan biet trong mang
    for (int i = 0; i < m; i++)
    {
        int dem = 0;
        // * Duyet tung phan tu cua mang b voi toan bo mang a de dem so lan xuat hien
        for (int j = 0; j < n; j++)
        {
            if (b[i] == a[j])
            {
                dem++;
            }
        }
        std::cout << "\nPhan tu " << b[i] << " xuat hien: " << dem << " lan " << std::endl;
    }
}

int main()
{
    int n; // so luong phan tu mang a
    int m; // so luong phan tu mang b
    int a[MAX];
    int b[MAX]; // mang b chinh la mang phu chua cac phan tu phan biet

    std::cout << "\nNhap so luong phan tu mang: ";
    std::cin >> n;
    std::cout << "\n\tNHAP MANG A: \n";
    nhap_mang(a, n);
    std::cout << "\n\tXUAT MANG A: \n";
    xuat_mang(a, n);

    xu_li(a, b, n, m);
    return 0;
}