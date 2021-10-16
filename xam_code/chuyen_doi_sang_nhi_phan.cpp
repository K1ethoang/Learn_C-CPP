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

void menu_1()
{
    bool thoat = false;
    short lua_chon;

    do
    {
        system("cls");
        std::cout << "================ HE THAP PHAN ================";
        std::cout << "\n\t1. THAP PHAN -> NHI PHAN";
        std::cout << "\n\t2. THAP PHAN -> THAP LUC PHAN";
        std::cout << "\n\t3. QUAY LAI";
        std::cout << "\n\t0. THOAT CHUONG TRINH";
        std::cout << "\n==================== EXIT ====================";
        std::cout << "\n\nNhap lua chon cua ban: ";
        std::cin >> lua_chon;

        int n;
        switch (lua_chon)
        {
        case 0:
            thoat = true;
            std::cout << "\nThoat chuong trinh thanh cong";
            break;
        case 1:
            std::cout << "\nNHAP SO: ";
            std::cin >> n;
            std::cout << n << " -> " << chuyen_thanh_nhi_phan(n) << std::endl;
            system("pause");
            break;
        case 2:
        case 3:
            thoat = true;
            break;

        default:
            std::cout << "\nLua chon khong hop le! Nhap lai\n";
            system("pause");
            break;
        }

    } while (!thoat);
}

void menu()
{
    bool thoat = false;
    do
    {
        system("cls");
        short lua_chon;
        std::cout << "==================== MENU ==================== ";
        std::cout << "\n\t1. HE THAP PHAN";
        std::cout << "\n\t2. HE THAP LUC PHAN";
        std::cout << "\n\t3. HE NHI PHAN";
        std::cout << "\n\t4. CHU -> NHI PHAN";
        std::cout << "\n\t0. THOAT CHUONG TRINH";
        std::cout << "\n==================== EXIT ==================== ";
        std::cout << "\n\nNhap lua chon: ";
        std::cin >> lua_chon;

        switch (lua_chon)
        {
        case 0:
            std::cout << "\nThoat chuong trinh thanh cong";
            thoat = true;
            break;
        case 1:
            menu_1();
            break;
        case 2:
            system("cls");
            std::cout << "================ HE THAP LUC PHAN ================";
            std::cout << "\n\t1. THAP LUC PHAN -> NHI PHAN";
            std::cout << "\n\t2. THAP LUC PHAN -> THAP PHAN";
            std::cout << "\n\t3. QUAY LAI";
            std::cout << "\n\t0. THOAT CHUONG TRINH";
            std::cout << "\n====================== EXIT ======================";
            system("pause");

            break;

        case 3:
            system("cls");
            std::cout << "================ HE NHI PHAN ================";
            std::cout << "\n\t1. NHI PHAN -> THAP PHAN";
            std::cout << "\n\t2. NHI PHAN -> THAP LUC PHAN";
            std::cout << "\n\t3. QUAY LAI";
            std::cout << "\n\t0. THOAT CHUONG TRINH";
            std::cout << "\n================== EXIT ==================";
            system("pause");

            break;

        case 4:
            system("cls");
            std::cout << "================ CHU ================";
            std::cout << "\n\t1. CHU -> NHI PHAN";
            std::cout << "\n\t2. CHU -> THAP PHAN";
            std::cout << "\n\t3. QUAY LAI";
            std::cout << "\n\t0. THOAT CHUONG TRINH";
            std::cout << "\n================ EXIT ================";
            system("pause");

            break;

        default:
            std::cout << "\nLua chon khong hop le! Moi nhap lai\n";
            system("pause");
            break;
        }

    } while (!thoat);
    std::cout << "\n\n\tBy: Hoang Gia Kiet - IT62" << std::endl;
}
int main()
{
    menu();
    system("pause");
    return 0;
}