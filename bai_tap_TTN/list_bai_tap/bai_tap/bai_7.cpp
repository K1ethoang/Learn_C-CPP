// ! Kiểm tra số nguyên dương n có phải là SỐ SIÊU NGUYÊN TỐ hay không ?

#include <iostream>
#include <cmath>

// Thuat toan kiem tra so nguyen to
int kiem_tra_so_nguyen_to(int n)
{
    if (n < 2)
    {
        return 0; // ko phai so nt
    }
    else
    {
        if (n == 2)
        {
            return 1; // la so nguyen to
        }
        else
        {
            if (n % 2 == 0)
            {
                return 0;
            }
            else
            {
                for (int i = 2; i <= sqrt(n); i++)
                {
                    if (n % i == 0)
                    {
                        return 0;
                    }
                }
            }
        }
    }
    return 1;
}

int kiem_tra_so_sieu_nguyen_to(int n)
{
    while (n != 0)
    {
        if (kiem_tra_so_nguyen_to(n) == 0)
        {
            return 0;
        }
        n /= 10;
    }
    return 1;
}

int main()
{
    int n;
    std::cout << "Nhap so nguyen n de kiem tra: ";
    std::cin >> n;

    if (kiem_tra_so_sieu_nguyen_to(n) == 1)
    {
        std::cout << n << " La so sieu nguyen to";
    }
    else
    {
        std::cout << n << " KHONG phai so sieu nguyen to";
    }

    return 0;
}