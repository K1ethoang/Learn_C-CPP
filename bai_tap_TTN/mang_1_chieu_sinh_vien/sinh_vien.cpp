#include <iostream>
#include <string>

struct sinh_vien
{
    std::string ma_so;
    std::string ho_ten;
    float diem_KTLT;
    float diem_TRR;
    float diem_CTGT_GT;
};

void nhap_thong_tin_1_sinh_vien(sinh_vien &sv)
{
    // Bat dieu kien nhap ma so
    do
    {
        std::cout << "\nNhap Ma So sinh vien: ";
        fflush(stdin);
        std::getline(std::cin, sv.ma_so);
        if (sv.ma_so.length() > 20)
        {
            std::cout << "\n\tDo dai khong hop le!";
            system("pause");
        }
    } while (sv.ma_so.length() > 20);

    // Bat dieu kien nhap ho ten
    do
    {
        std::cout << "\nNhap Ho Ten sinh vien: ";
        fflush(stdin);
        std::getline(std::cin, sv.ho_ten);
        if (sv.ho_ten.length() > 30)
        {
            std::cout << "\n\tDo dai khong hop le!";
            system("pause");
        }
    } while (sv.ho_ten.length() > 30);

    do
    {
        std::cout << "\nNhap diem Ki Thuat Lap Trinh: ";
        std::cin >> sv.diem_KTLT;
        if (sv.diem_KTLT < 0 || sv.diem_KTLT > 10)
        {
            std::cout << "\n\tDiem so khong hop le !";
            system("pause");
        }
    } while (sv.diem_KTLT < 0 || sv.diem_KTLT > 10);

    do
    {
        std::cout << "\nNhap diem Toan Roi Rac: ";
        std::cin >> sv.diem_TRR;
        if (sv.diem_TRR < 0 || sv.diem_TRR > 10)
        {
            std::cout << "\n\tDiem so khong hop le !";
            system("pause");
        }
    } while (sv.diem_TRR < 0 || sv.diem_TRR > 10);

    do
    {
        std::cout << "\nNhap diem Cau Truc Du Lieu & Giai Thuat: ";
        std::cin >> sv.diem_CTGT_GT;
        if (sv.diem_CTGT_GT < 0 || sv.diem_CTGT_GT > 10)
        {
            std::cout << "\n\tDiem so khong hop le !";
            system("pause");
        }
    } while (sv.diem_CTGT_GT < 0 || sv.diem_CTGT_GT > 10);
}

void xuat_thong_tin_1_sinh_vien(sinh_vien sv)
{
    std::cout << "\nMa So sinh vien: " << sv.ma_so;
    std::cout << "\nHo Ten sinh vien: " << sv.ho_ten;
    std::cout << "\nDiem Ki Thuat Lap Trinh: " << sv.diem_KTLT;
    std::cout << "\nDiem Toan Roi Rac: " << sv.diem_TRR;
    std::cout << "\nDiem Cau Truc Du Lieu & Giai Thuat: " << sv.diem_CTGT_GT;
}

struct danh_sach
{
    sinh_vien *ds_sv[100]; // Khai bao mang 1 chieu cac con tro sinh vien
    int n;
};

// Ham xuat danh sach sinh vien
void xuat_danh_sach_sinh_vien(danh_sach ds)
{
    for (int i = 0; i < ds.n; i++)
    {
        std::cout << "\n\n\t\tTHONG TIN SINH VIEN THU " << i + 1 << std::endl;
        xuat_thong_tin_1_sinh_vien(*ds.ds_sv[i]);
    }
}

// Ham quan li danh sach sinh vien
void menu(danh_sach &ds)
{
    int lua_chon;
    while (true)
    {
        system("cls");
        std::cout << "\n\n\t\t======== QUAN LY SINH VIEN ========\n";
        std::cout << "\n\t1. Them thong tin sinh vien";
        std::cout << "\n\t2. Xuat danh sach sinh vien";
        std::cout << "\n\t0. Ket thuc";
        std::cout << "\n\n\t\t============= END =============\n";

        std::cout << "\nNhap lua chon: ";
        std::cin >> lua_chon;
        if (lua_chon == 0)
        {
            break;
        }
        else if (lua_chon == 1)
        {
            sinh_vien *x = new sinh_vien;
            std::cout << "\n\n\t\tNHAP THONG TIN SINH VIEN\n";
            nhap_thong_tin_1_sinh_vien(*x);
            ds.ds_sv[ds.n] = x; // Them sinh vien x vao mang 1 chieu cac con tro sinh vien
            ds.n++;
        }
        else if (lua_chon == 2)
        {
            std::cout << "\n\n\t\t\tDANH SACH SINH VIEN\n";
            xuat_danh_sach_sinh_vien(ds);
            system("pause");
        }
    }
}

int main()
{
    danh_sach ds;
    ds.n = 0;
    menu(ds);

    // Ham giai phong vung nho cho mang 1 chieu cac con tro
    for (int i = 0; i < ds.n; i++)
    {
        delete ds.ds_sv[i];
    }

    system("pause");
    return 0;
}