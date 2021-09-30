#include <iostream>

// Nhap vao toa do 3 dinh cua 1 tam giac. Tinh do dai tung canh
struct toa_do
{
    float x; // Toa do x
    float y; // Toa do y
};

void nhap_toa_do(toa_do &td)
{
    std::cout << "\nNhap vao diem x: ";
    std::cin >> td.x;
    std::cout << "\nNhap vao diem y: ";
    std::cin >> td.y;
}

void xuat_toa_do(toa_do td)
{
    std::cout << "(" << td.x << "; " << td.y << ")";
}

int main()
{
    toa_do a;
    toa_do b;
    toa_do c;

    std::cout << "\n\n\t\tNHAP TOA DO DIEM A\n";
    nhap_toa_do(a);
    std::cout << "\n\n\t\tNHAP TOA DO DIEM B\n";
    nhap_toa_do(b);
    std::cout << "\n\n\t\tNHAP TOA DO DIEM C\n";
    nhap_toa_do(c);

    std::cout << "\n\n\t\tTOA DO DIEM A\n";
    xuat_toa_do(a);
    std::cout << "\n\n\t\tTOA DO DIEM B\n";
    xuat_toa_do(b);
    std::cout << "\n\n\t\tTOA DO DIEM C\n";
    xuat_toa_do(c);

    system("pause");
    return 0;
}