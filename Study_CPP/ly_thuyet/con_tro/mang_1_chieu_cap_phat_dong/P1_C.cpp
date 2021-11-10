#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

void input_array(int n, int a[])
{
    for (int i = 0; i < n; i++)
    {
        printf("\nNhap a[%d]: ", i);
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

void add_one_element(int &n, int a[], int pos, int x)
{
    // * trước khi thêm ptu x vào pos - chúng ta cần nới rộng vùng mới ban đầu ra thêm 1 ô
    realloc(a, (n + 1) * sizeof(int));
    for (int i = n - 1; i >= pos; i--)
    {
        a[i + 1] = a[i];
    }
    a[pos] = x;
    n++;
}
void delete_one_element(int &n, int a[], int pos)
{
    for (int i = pos + 1; i < n; i++)
    {
        a[i - 1] = a[i];
    }
    // * Sau khi xoá ptu tai x, thì mình mới thu hẹp vùng nhơ
    realloc(a, (n - 1) * sizeof(int));
    n--;
}

int main()
{
    int *a; // * Con trỏ a sẽ quản lí cái mảng động của chúng ta
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

    // * Cấp phát vùng nhớ để con trỏ quản lí <=> tạo mảng động
    // a = (int *)malloc(sizeof(int) * n); // * Cấp phát vùng nhớ cho mảng

    // * Cấp phát vùng nhớ để con trỏ quản lí <=> tạo mảng động
    // a = (int *)calloc(n, sizeof(int)); // * Nếu ko nhập giá trị mặc định là số 0

    // * Cấp phát vùng nhớ để con trỏ quản lí <=> tạo mảng động
    a = (int *)realloc(NULL, n * sizeof(int));

    printf("\n\n\tNHAP MANG\n");
    input_array(n, a);
    printf("\n\n\tXUAT MANG DA NHAP\n");
    output_array(n, a);

    int pos, x;
    printf("\nNhap vi tri can them: ");
    scanf("%d", &pos);
    printf("\nNhap gia tri can them: ");
    scanf("%d", &x);

    printf("\n\n\tMANG SAU KHI THEM\n");
    add_one_element(n, a, pos, x);
    output_array(n, a);

    free(a); // * Giải phóng vùng nhớ cho con trỏ a

    getch();
    return 0;
}