#include <stdio.h>
#include <stdlib.h> // Thư viện này hỗ trợ dùng các hàm cấp phất bộ nhớ cho con trỏ

int main()
{
    int *p; // Khai báo con trỏ p, lúc này con trỏ chưa có vùng nhớ, vì vây ta phải cấp phát cho nó

    // !Cấp phát vùng nhớ cho con trỏ p bằng hàm malloc
    //// Cấp phát vùng nhớ cho con trỏ p bằng hàm malloc
    //// malloc là 1 cái hàm yêu cầu hệ điều hành cấp phát ra 1 vùng nhớ trong bộ nhớ máy tính
    // p = (int *)malloc(sizeof(int *));
    //*p = 23;

    // ! Cấp phát vùng nhớ cho con trỏ p bằng hàm calloc
    // p = (int *)calloc(1, sizeof(int *));
    // *p = 69;

    // ! Cấp phát vùng nhớ cho con trỏ p bằng hàm realloc
    p = (int *)realloc(0, sizeof(int *));
    *p = 2807;
    printf("\nGia tri cua bien con tro p: %d", *p);

    free(p); // Giải phóng vùng nhớ cho con trỏ p
    return 0;
}
