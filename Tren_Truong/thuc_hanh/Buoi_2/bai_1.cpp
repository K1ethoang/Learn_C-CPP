// Ho Ten: Hoang Gia Kiet
// MSSV: 6251071049
// Lop: IT-62

#include <stdio.h>
#include <math.h>

int main()
{
    int n, a[100], count = 0;
    do
    {
        printf("\nNhap n (0 < n <= 100): ");
        scanf("%d", &n);
    } while (n < 1 || n > 100);

    printf("\n\t\tNHAP MANG\n");
    for (int i = 0; i < n; i++)
    {
        printf("\nNhap a[%d]: ", i + 1);
        scanf("%d", &a[i]);
    }

    printf("\n\t\tMANG VUA NHAP\n");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", a[i]);
    }

    // kiểm tra số nguyên tố có trong mảng
    for (int i = 0; i < n; i++)
    {
        bool isPrime = true;
        if (a[i] < 2)
            isPrime = false;
        else
        {
            if (a[i] == 2)
                isPrime == true;
            else
            {
                for (int j = 2; j <= sqrt(a[i]); j++)
                {
                    if (a[i] % j == 0)
                    {
                        isPrime = false;
                        break;
                    }
                }
            }
        }
        if (isPrime)
            count++;
    }

    printf("\n\nTrong mang co %d so nguyen to", count);

    return 0;
}