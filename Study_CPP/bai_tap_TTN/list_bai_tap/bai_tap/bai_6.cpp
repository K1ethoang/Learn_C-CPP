// ! Kiểm tra số nguyên dương n có phải là SỐ ĐỐI XỨNG hay không ?

#include <iostream>
#include <cmath>

// buoc 1: dem xem n co bao nhieu chu so - so luong cua chu so n
// ban chat cua cv nay la tim so mu trong ct
int dem_so_mu(int n)
{
    int count = 0;
    int temp = n;
    while (temp != 0)
    {

        temp /= 10;
        count++;
    }
    return count;
}

// Buoc 2: la buoc ap dung ct de tim so dao nguoc
int xu_ly(int n, int so_mu)
{
    int temp = n;
    int x = 0; // bien chua so dao nguoc
    while (temp != 0)
    {
        x += (temp % 10) * pow(10, so_mu - 1);
        temp /= 10;
        so_mu--;
    }
    return x;
}

int main()
{
    int n;
    std::cout << "Nhap so nguyen duong N: ";
    std::cin >> n;

    // Buoc 3: so sanh voi so dao nguoc ban dau
    if (n == xu_ly(n, dem_so_mu(n)))
    {
        std::cout << n << " la so dao nguoc ";
    }
    else
    {
        std::cout << n << " KHONG phai so dao nguoc";
    }

    return 0;
}