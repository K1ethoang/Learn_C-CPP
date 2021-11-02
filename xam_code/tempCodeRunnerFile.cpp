#include <stdio.h>
#include <math.h>
int main()
{
    int a[100];
    int dem = 0;
    int n, i = 0;
    int j = 2;
    printf("nhap phan tu day: ");
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        printf("gia tri a[%d]= ", i);
        scanf("%d", &a[i]);
    }
    printf("gia tri da nhap la");
    for (int i = 0; i < n; i++)
    {
        printf("\na[%d]= %d", i, a[i]);
    }

    if (a[i] < 2)
    {
        printf("%d khong la nguyen to ", a[i]);
    }
    else
    {
        if (a[i] == 2)
        {
            printf("\n%d la so nguyen to", a[i]);
        }
        else

        {
            for (int j = 2; j < a[i - 1]; j++)
            {
                if (a[i] % j == 0)
                {
                    printf("%d khong la nguyen to", a[i]);
                    dem++;
                    break;
                }
            }
            if (dem == 0)
                printf("\n%d la so nguyen to", a[i]);
        }
        i++;
    }
}