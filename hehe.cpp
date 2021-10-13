#include <iostream>
#include <cmath>

// ! Chuyển số thập phân -> nhị phân
long long chuyen_thanh_nhi_phan(int n)
{
    long long x = 0; // * Biến nhị Phân
    int mu = 0;

    while (n != 0)
    {
        x += (n % 2) * pow(10, mu); // Cộng dồn lại số nhị phân
        n = n / 2;                  // Cập nhật lại n sau khi chia 2
        mu++;                       // Tăng mũ lên 1 đơn vị sau mỗi lần lặp
    }
    return x;
}

void xu_ly(int n)
{
    int i = 0;
    while (i != n)
    {
        int x;
        std::cin >> x;
        std::cout << chuyen_thanh_nhi_phan(x) << std::endl;
        i++;
    }
}

int main()
{
    int n;
    std::cin >> n;

    xu_ly(n);
    return 0;
}