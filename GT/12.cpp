
// !Thầy giáo Pa đến từ Bali

#include <iostream>
#include <cmath>

int dem_so_mu(int n)
{
    short dem = 0;
    while (n != 0)
    {
        n /= 10;
        dem++;
    }
    return dem;
}

int check_palindrome_number(int n)
{

    int temp = n;
    int sum = 0;
    short mu = dem_so_mu(n) - 1;
    while (temp != 0)
    {
        sum += (temp % 10) * pow(10, mu);
        temp /= 10;
        mu--;
    }
    if (sum == n)
    {
        return 1;
    }
    return 0;
}

int main()
{
    int t;
    std::cin >> t;

    return 0;
}