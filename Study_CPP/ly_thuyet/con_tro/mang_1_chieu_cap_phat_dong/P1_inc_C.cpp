#include <stdio.h>

void input_array(int n, int a[])
{
    for (int i = 0; i < n; i++)
    {
        printf("Nhap a[%d]: \n", i);
        scanf("%d", &a[i]);
    }
}
void output_array(int n, int a[])
{
    for (int i = 0; i < n; i++)
    {
        printf("%d ", a[i]);
    }
}

int main()
{
    int n;
    do
    {
        printf("Nhap n phan tu can co: ");
        scanf("%d", &n);
        if (n <= 0 || n > 100)
        {
            printf("Moi ban nhap lai! (0 < n <= 100)\n\n");
        }
    } while (n <= 0 || n > 100);

    int a[n];
    input_array(n, a);
    output_array(n, a);

    return 0;
}