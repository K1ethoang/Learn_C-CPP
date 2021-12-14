#include <iostream>
#include <string>
#include <cmath>

// Chuyen sang he nhi phan
long long chuyen_thanh_nhi_phan(char c)
{
    int n = (int)(c); // Ep kieu ki tu thanh kieu so nguyen
    int so_mu = 0;
    long long x = 0; // Bien luu he nhi phan
    while (n != 0)
    {
        x += (n % 2) * pow(10, so_mu);
        n /= 2;
        so_mu++;
    }
    return x;
}

// Xep lai vao chuoi
void xuat(long long x)
{
    std::cout << x;
}

int main()
{

    int n = 0;
    std::cout << "Nhap so chuoi can chuyen -> Nhi phan: ";
    std::cin >> n;

    int j = 0;
    while (n--)
    {
        std::string str;
        std::cout << "Nhap Chuoi " << j + 1 << " : ";
        fflush(stdin);
        std::getline(std::cin, str);
        for (int i = 0; i < str.length(); i++)
        {
            xuat(chuyen_thanh_nhi_phan(str[i]));
            std::cout << " ";
        }
        std::cout << "\n\n";
        j++;
    }

    system("pause");
    return 0;
}