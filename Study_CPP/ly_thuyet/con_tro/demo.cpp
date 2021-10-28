#include <iostream>

int main()
{
    int a = 5; // Khai báo ra biến a có giá trị là 5
    int *p;    // Khai báo biến con trỏ có kiểu dữ liệu trỏ đến là int - lúc này con biến p chỉ có địa chỉ thôi, chưa có vùng nhớ để chứa giá trị
    p = &a;    // Cho con trỏ p trỏ đến biến a, lúc này con trỏ p đang giữ địa  chỉ của biến a
    int *pp;   // Khai báo ra biến con trỏ pp
    pp = p;    // Con trỏ pp đang trỏ đến con trỏ p
    void *ppp; // Con trỏ vô kiểu
    ppp = &a;

    std::cout << sizeof(p);
    std::cout << "\nGia tri cua bien a: " << a;
    std::cout << "\nDia chi cua bien a: " << &a;
    /*  a++;    // Giá trị của biến a thay đổi nên p thay đỏi theo
     (*p)++; // Giá trị của biến p thay đỏi nên a thay đổi
    *p++    // Tăng vị trí vùng nhớ của a lên 1 ô vì toán tử + có độ ưu tiên cao hơn toán tử * */
    std::cout << "\n\nGia tri cua bien p: " << *p;
    std::cout << "\nDia chi cua bien p: " << &p;
    std::cout << "\nMien gia tri cua bien p: " << p;

    std::cout << "\n\nGia tri cua bien pp: " << *pp;
    std::cout << "\nDia chi cua bien pp: " << &pp;
    std::cout << "\nMien gia tri cua bien pp: " << pp;

    std::cout << "\n\n\tCON TRO VO KIEU\n";
    std::cout << "\nGia tri con tro ppp: " << *(int *)ppp;
    return 0;
}