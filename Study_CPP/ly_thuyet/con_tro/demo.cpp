#include <iostream>

int main()
{
    int a = 5; // Khai báo ra biến a có giá trị là 5
    int *p;    // Khai báo biến con trỏ có kiểu dữ liệu trỏ đến là int
    p = &a; // Cho con trỏ p trỏ đến biến a, lúc này con trỏ p đang giữ địa  chỉ của biến a
    *p = 9;
    return 0;
}