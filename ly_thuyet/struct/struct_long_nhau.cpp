#include <iostream>
#include <cmath>

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
// Nhap vao toa do 3 dinh cua 1 tam giac. Tinh do dai tung canh
float tinh_do_dai_canh(toa_do a, toa_do b)
{
    return sqrt(pow((b.x - a.x), 2) + pow((b.y - a.y), 2));
}

void xuat_toa_do(toa_do td)
{
    std::cout << "(" << td.x << "; " << td.y << ")";
}

// Cau truc struct tam giac
struct tam_giac
{
    toa_do a;
    toa_do b;
    toa_do c;
};

void nhap_toa_do_tam_giac(tam_giac &tg)
{

    std::cout << "\n\n\t\tNHAP TOA DO DIEM A\n";
    nhap_toa_do(tg.a);
    std::cout << "\n\n\t\tNHAP TOA DO DIEM B\n";
    nhap_toa_do(tg.b);
    std::cout << "\n\n\t\tNHAP TOA DO DIEM C\n";
    nhap_toa_do(tg.c);
}

void xuat_toa_do_tam_giac(tam_giac tg)
{
    std::cout << "\n\n\t\tTOA DO DIEM A\n";
    xuat_toa_do(tg.a);
    std::cout << "\n\n\t\tTOA DO DIEM B\n";
    xuat_toa_do(tg.b);
    std::cout << "\n\n\t\tTOA DO DIEM C\n";
    xuat_toa_do(tg.c);
}

int main()
{
    tam_giac tg;
    nhap_toa_do_tam_giac(tg);
    xuat_toa_do_tam_giac(tg);

    std::cout << "\n\n\t\tDO DAI CANH AB: ";
    std::cout << tinh_do_dai_canh(tg.a, tg.b);
    std::cout << "\n\n\t\tDO DAI CANH AC: ";
    std::cout << tinh_do_dai_canh(tg.a, tg.c);
    std::cout << "\n\n\t\tDO DAI CANH BC: ";
    std::cout << tinh_do_dai_canh(tg.b, tg.c);

    system("pause");
    return 0;
}