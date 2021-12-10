#include <stdio.h>

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
            count = 0;
            printf("\n");
        }
    }
}

int main()
{
    int n, a[100];
    scanf("%d", &n);

    inputArray(a, n);
    outputArray(a, n);
    return 0;
}