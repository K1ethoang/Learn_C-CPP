// Ho Ten: Hoang Gia Kiet
// MSSV: 6251071049
// Lop: IT-62

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void inputArray(int a[], int n);
void outputArray(int a[], int n);
void menu();
void pressAnyKey();

int main()
{
    menu();
    return 0;
}

void menu()
{
    int n = 5, a[100];
    short choose;
    bool exit = false;
    do
    {
        printf("----------------------------- MENU -----------------------------");
        printf("\n  1. Nhap mang");
        printf("\n  2. Xuat mang");
        printf("\n  0. Thoat chuong trinh");
        printf("\n---------------------------- <3<3<3 ----------------------------");

        printf("\n  Nhap lua chon: ");
        scanf("%d", &choose);

        switch (choose)
        {
        case 1:
            inputArray(a, n);
            break;
        case 2:
            outputArray(a, n);
            pressAnyKey();
            break;
        default:
            break;
        }
    } while (!exit);
}

void pressAnyKey()
{
    printf("\n");
    system("pause");
    printf("\n");
}

void inputArray(int a[], int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("\nNhap a[%d]: ", i + 1);
        scanf("%d", &a[i]);
    }
}

void outputArray(int a[], int n)
{
    int count = 0;
    for (int i = 0; i < n; i++)
    {
        count++;
        printf("%d ", a[i]);
        if (count == 10)
        {
            printf("\n");
            count = 0;
        }
    }
}

