/* 
    Ho Ten: Hoang Gia Kiet
    MSSV: 6251071049
    Lop: IT62
 */

#include <stdio.h>
#include <math.h>
#include <conio.h>

// ! Chuyển số thập phân -> nhị phân
long long chuyen_thanh_nhi_phan(int n)
{
    long long x = 0; // * Biến chứa nhị nhị Phân
    int mu = 0;
    gets
    while (n != 0)
    {
        x += (n % 2) * pow(10, mu); // Lấy số dư nhân cho 10^mu
        n = n / 2;                  // Cập nhật lại n sau khi chia 2
        mu++;                       // Tăng mũ lên 1 đơn vị sau mỗi lần lặp
    }
    return x;
}

int main()
{
    int n;

    printf("\nNhap so thap phan can chuyen qua nhi phan: ");
    scanf("%d", &n);

    printf("\nSo thap phan ban vua nhap: %d", n);
    printf("\n\n\t\tKET QUA\n");
    printf("\nThap phan %d -> Nhi phan %d", n, chuyen_thanh_nhi_phan(n));
    printf("\n\n\tBy: Hoang Gia Kiet - IT62");

    getch();
    return 0;
}