#include <iostream>
#include <string>

struct sinh_vien;
struct danh_sach_sinh_vien;
// * Khai báo cấu trúc sinh viên
struct sinh_vien
{
    std::string ma_so;
    std::string ho_ten;
    float diem_ki_thuat_lap_trinh;
    float diem_toan_roi_rac;
    float diem_CTDL_GT;
};

// * Khai bao danh sach thong tin sinh vien
struct danh_sach_sinh_vien
{
    sinh_vien array_sv[100]; // * Khai báo mảng 1 chiều tĩnh chứa 100 sinh viên
    int n;                   // * Số lượng sinh viên hiện có trong mảng
};

void nhap_thong_tin_1_sinh_vien(sinh_vien &sv);
void xuat_thong_tin_1_sinh_vien(sinh_vien sv);
void nhap_thong_tin_nhieu_sinh_vien(danh_sach_sinh_vien &ds);
void xuat_danh_sach_sinh_vien(danh_sach_sinh_vien ds);
float tinh_diem_trung_binh(sinh_vien sv);
void xep_loai_1_sinh_vien(sinh_vien sv);
void xep_loai_danh_sach_sinh_vien(danh_sach_sinh_vien ds);
void hoan_vi(sinh_vien &x, sinh_vien &y);
void sap_xep_tang_dan_theo_diem_tb(danh_sach_sinh_vien &ds);
void sap_xep_giam_dan_theo_ten(danh_sach_sinh_vien &ds);

int main()
{
    danh_sach_sinh_vien ds_sinh_vien;
    bool thoat = false; // * Thiết lập ban đầu là không thoát

    do
    {
        system("cls");
        short lua_chon;
        std::cout << "\n=================================== MENU ===================================";
        std::cout << "\n\t1. Nhap danh sach sinh vien";
        std::cout << "\n\t2. Xuat danh sach sinh vien";
        std::cout << "\n\t3. Xep loai sinh vien";
        std::cout << "\n\t4. Sap xep danh sach sinh vien TANG DAN theo DIEM TRUNG BINH";
        std::cout << "\n\t5. Sap xep danh sach sinh vien GIAM DAN theo TEN";
        std::cout << "\n\t0. Thoat chuong trinh";
        std::cout << "\n============================================================================";
        std::cout << "\nNhap lua chon cua ban: ";

        std::cin >> lua_chon;
        switch (lua_chon)
        {
        case 0:
            std::cout << "\nBan da chon thoat chuong trinh !";
            system("pause");
            thoat = true;
            break;
        case 1:
            system("cls");
            std::cout << "\n\n\t\t\t\t1. NHAP DANH SACH SINH VIEN\n";
            do
            {
                std::cout << "\nNhap so luong sinh vien: ";
                std::cin >> ds_sinh_vien.n;
                if (ds_sinh_vien.n < 0 || ds_sinh_vien.n > 100)

                {
                    std::cout << "\n\tSo luong khong hop le! Vui long nhap lai (toi da 100 sinh vien)";
                }
            } while (ds_sinh_vien.n < 0 || ds_sinh_vien.n > 100);
            nhap_thong_tin_nhieu_sinh_vien(ds_sinh_vien);
            std::cout << "\n\n\t\t\t\tDANH SACH SINH VIEN VUA NHAP\n";
            xuat_danh_sach_sinh_vien(ds_sinh_vien);
            system("pause");

            break;
        case 2:
            system("cls");
            std::cout << "\n\n\t\t\t\t2. XUAT DANH SACH SINH VIEN\n";
            xuat_danh_sach_sinh_vien(ds_sinh_vien);
            system("pause");
            break;
        case 3:
            system("cls");
            std::cout << "\n\n\t\t\t\t3. XEP LOAI SINH VIEN\n";
            xep_loai_danh_sach_sinh_vien(ds_sinh_vien);
            system("pause");
            break;
        case 4:
            system("cls");
            std::cout << "\n\n\t\t\t\t4. DANH SACH SINH VIEN SAP XEP TANG DAN THEO DIEM TB\n";
            sap_xep_tang_dan_theo_diem_tb(ds_sinh_vien);
            xuat_danh_sach_sinh_vien(ds_sinh_vien);
            system("pause");
            break;
        case 5:
            system("cls");
            std::cout << "\n\n\t\t\t\t5. DANH SACH SAU KHI SAP XEP GIAM DAN THEO TEN\n";
            sap_xep_giam_dan_theo_ten(ds_sinh_vien);
            xuat_danh_sach_sinh_vien(ds_sinh_vien);
            system("pause");
            break;
        default:
            std::cout << "\nLua chon cua ban khon hop le !";
            system("pause");
            break;
        }
    } while (!thoat);

    return 0;
}

// * Hàm nhập thông tin 1 sinh viên
void nhap_thong_tin_1_sinh_vien(sinh_vien &sv)
{

    do
    {
        std::cout << "\nNhap Ma So sinh vien: ";
        fflush(stdin);
        std::getline(std::cin, sv.ma_so);
        if (sv.ma_so.length() > 20)
        {
            std::cout << "\nMa so khong hop le! Vui long nhap lai\a";
        }
    } while (sv.ma_so.length() > 20);

    do
    {
        std::cout << "\nNhap Ho Ten sinh vien: ";
        fflush(stdin);
        std::getline(std::cin, sv.ho_ten);
        if (sv.ho_ten.length() > 30)
        {
            std::cout << "\n\tMa so khong hop le! Vui long nhap lai\a";
        }
    } while (sv.ho_ten.length() > 30);

    do
    {
        std::cout << "\nNhap Diem Ky Thuat Lap Trinh: ";
        std::cin >> sv.diem_ki_thuat_lap_trinh;
        if (sv.diem_ki_thuat_lap_trinh < 0 || sv.diem_ki_thuat_lap_trinh > 10)
        {
            std::cout << "\n\tDiem khong hop le! Vui long nhap lai\a";
        }
    } while (sv.diem_ki_thuat_lap_trinh < 0 || sv.diem_ki_thuat_lap_trinh > 10);

    do
    {
        std::cout << "\nNhap Diem Toan Roi Rac: ";
        std::cin >> sv.diem_toan_roi_rac;
        if (sv.diem_toan_roi_rac < 0 || sv.diem_toan_roi_rac > 10)
        {
            std::cout << "\n\tDiem khong hop le! Vui long nhap lai\a";
        }
    } while (sv.diem_toan_roi_rac < 0 || sv.diem_toan_roi_rac > 10);

    do
    {
        std::cout << "\nNhap Diem Cau Truc Du Lieu & Giai Thuat: ";
        std::cin >> sv.diem_CTDL_GT;
        if (sv.diem_CTDL_GT < 0 || sv.diem_CTDL_GT > 10)
        {
            std::cout << "\n\tDiem khong hop le! Vui long nhap lai\a";
        }
    } while (sv.diem_CTDL_GT < 0 || sv.diem_CTDL_GT > 10);
}

// * Hàm xuất thông tin 1 sinh viên
void xuat_thong_tin_1_sinh_vien(sinh_vien sv)
{
    std::cout << "\nMa So sinh vien: " << sv.ma_so;
    std::cout << "\nHo Ten sinh vien: " << sv.ho_ten;
    std::cout << "\nDiem Ky Thuat Lap Trinh: " << sv.diem_ki_thuat_lap_trinh;
    std::cout << "\nDiem Toan Roi Rac: " << sv.diem_toan_roi_rac;
    std::cout << "\nDiem Cau Truc Du Lieu & Giai Thuat: " << sv.diem_CTDL_GT;
}

// ! Ham nhap danh sach thong tin sinh vien
void nhap_thong_tin_nhieu_sinh_vien(danh_sach_sinh_vien &ds)
{
    for (int i = 0; i < ds.n; i++)
    {
        std::cout << "\n\n\t\tNHAP THONG TIN SINH VIEN THU " << i + 1 << std::endl;
        nhap_thong_tin_1_sinh_vien(ds.array_sv[i]);
    }
}

// ! Ham xuat danh sach thong tin sinh vien
void xuat_danh_sach_sinh_vien(danh_sach_sinh_vien ds)
{
    int j(0);
    for (int i = 0; i < ds.n; i++)
    {
        j++;
        std::cout << "\n\n\t\tTHONG TIN SINH VIEN THU " << j << std::endl;
        xuat_thong_tin_1_sinh_vien(ds.array_sv[i]);
    }
}

// * Hàm tính điểm trung bình
float tinh_diem_trung_binh(sinh_vien sv)
{
    return (sv.diem_ki_thuat_lap_trinh + sv.diem_toan_roi_rac + sv.diem_CTDL_GT) / 3;
}

// * Hàm xếp loại 1 sinh viên
void xep_loai_1_sinh_vien(sinh_vien sv)
{
    if (tinh_diem_trung_binh(sv) > 9.8)
    {
        std::cout << "\n\t--> Xuat Sac <--";
    }
    else if (tinh_diem_trung_binh(sv) >= 8)
    {
        std::cout << "\n\t--> Gioi <--";
    }
    else if (tinh_diem_trung_binh(sv) >= 6.5)
    {
        std::cout << "\n\t--> Kha <--";
    }
    else if (tinh_diem_trung_binh(sv) >= 4)
    {
        std::cout << "\n\t--> Trung Binh <--";
    }
    else
    {
        std::cout << "\n\t--> Yeu <--";
    }
}

// ! Hàm xếp loai các sinh viên
void xep_loai_danh_sach_sinh_vien(danh_sach_sinh_vien ds)
{
    for (int i = 0; i < ds.n; i++)
    {
        std::cout << "\n\n"
                  << i + 1
                  << ". MSSV: " << ds.array_sv[i].ma_so << " - "
                  << "Ho Ten: " << ds.array_sv[i].ho_ten;
        xep_loai_1_sinh_vien(ds.array_sv[i]);
    }
}

// * Hàm hoán vị
void hoan_vi(sinh_vien &x, sinh_vien &y)
{
    sinh_vien temp;
    temp = x;
    x = y;
    y = temp;
}

// ! Hàm sắp xếp sinh viên tăng dần theo điểm trung bình
void sap_xep_tang_dan_theo_diem_tb(danh_sach_sinh_vien &ds)
{
    for (int i = 0; i < ds.n - 1; i++)
    {
        for (int j = i + 1; j < ds.n; j++)
        {
            if (tinh_diem_trung_binh(ds.array_sv[i]) > tinh_diem_trung_binh(ds.array_sv[j]))
            {
                hoan_vi(ds.array_sv[i], ds.array_sv[j]);
            }
        }
    }
}

// ! Hàm sắp xếp sinh viên giảm dần theo tên
void sap_xep_giam_dan_theo_ten(danh_sach_sinh_vien &ds)
{
    for (int i = 0; i < ds.n - 1; i++)
    {
        for (int j = i + 1; j < ds.n; j++)
        {
            if (ds.array_sv[i].ho_ten.substr() < ds.array_sv[j].ho_ten.substr())
            {
                hoan_vi(ds.array_sv[i], ds.array_sv[j]);
            }
        }
    }
}
