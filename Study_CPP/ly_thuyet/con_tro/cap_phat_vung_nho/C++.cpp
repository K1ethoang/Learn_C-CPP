#include <iostream>

int main()
{
    int *p = new int;
    *p = 23;
    std::cout << "\nGia tri con tro a: " << *p;

    delete p; // Giải phóng vùng nhớ cho con trỏ p

    return 0;
}