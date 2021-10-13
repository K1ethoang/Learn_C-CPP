/* 
    Ho Ten: Hoang Gia Kiet
    MSSV: 6251071049
    Lop: IT62
 */

#include <iostream>
#include <cmath>
#include <string>

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

// ! Chuyển số nhị phân -> thập phân
int chuyen_thanh_thap_phan(long long n)
{
    int x = 0; // * Biến thập phân
    int mu = 0;

    while (n != 0)
    {
        x += (n % 10) * pow(2, mu);
        n /= 10;
        mu++;
    }
    return x;
}

// ! Menu
void menu()
{
    bool thoat = false;
    do
    {
        short lua_chon;

    } while;
}
int main()
{

    std::cout << "\n\n\tBy: Hoang Gia Kiet - IT62" << std::endl;

    system("pause");
    return 0;
}