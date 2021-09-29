#include <iostream>

struct sinh_vien
{
    std::string ho_ten;
    std::string mssv;
    int tuoi;
    int diem;
};

void nhap_1_sinh_vien(sinh_vien sv)
{
    std::cout << "\nNhap ho ten sinh vien: ";
    std::cin.ignore();
    std::getline(std::cin, sv.ho_ten);

    std::cout << "\nNhap ma so sinh vien: ";
    std::cin.ignore();
    std::getline(std::cin, sv.mssv);

    std::cout << "\nNhap tuoi: ";
    std::cin >> sv.tuoi;

    std::cout << "\nNhap diem: ";
    std::cin >> sv.diem;
}

int main()
{

    return 0;
}