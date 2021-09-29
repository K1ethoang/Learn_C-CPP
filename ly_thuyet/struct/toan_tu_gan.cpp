#include <iostream>

struct sinh_vien
{
    std::string ho_ten;
    std::string mssv;
    int tuoi;
    float diem;
};

void nhap_1_sinh_vien(sinh_vien &sv)
{
    std::cout << "\nNhap ho ten sinh vien: ";
    fflush(stdin);
    std::getline(std::cin, sv.ho_ten);

    std::cout << "\nNhap ma so sinh vien: ";
    fflush(stdin);
    std::getline(std::cin, sv.mssv);

    std::cout << "\nNhap tuoi: ";
    std::cin >> sv.tuoi;

    std::cout << "\nNhap diem: ";
    std::cin >> sv.diem;
}

void xuat_1_sinh_vien(sinh_vien sv)
{
    std::cout << "\nHo ten sinh vien: " << sv.ho_ten;

    std::cout << "\nMa so sinh vien: " << sv.mssv;

    std::cout << "\nTuoi: " << sv.tuoi;

    std::cout << "\nDiem: " << sv.diem;
}

int main()
{
    sinh_vien x;
    sinh_vien y;
    std::cout << "\n\n\t\tNHAP THONG TIN 1 SINH VIEN x\n";
    nhap_1_sinh_vien(x);

    // Cach 1
    // y = x;

    // Cach 2
    y.ho_ten = x.ho_ten;
    y.mssv = x.mssv;
    y.diem = x.diem;
    y.tuoi = x.tuoi;

    std::cout << "\n\n\t\tTHONG TIN 1 SINH VIEN x\n";
    xuat_1_sinh_vien(x);

    std::cout << "\n\n\t\tTHONG TIN 1 SINH VIEN y\n";
    xuat_1_sinh_vien(y);
    return 0;
}
