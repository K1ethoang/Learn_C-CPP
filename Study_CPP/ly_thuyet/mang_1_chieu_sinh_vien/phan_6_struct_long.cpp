/* Thong tin sinh vien
+ Ho ten: toi da 30 ki tu
+ Ma so sinh vien: toi da 10 ki tu
+ Diem trung binh

1. Nhap danh sach sinh vien
2. In ra man hinh diem trung binh cao nhat
3. Xuat ra thong tin sinh vien co diem trung binh thap nhat

 */

#include <iostream>

// ! ========================== KHAI BAO CAU TRUC 1 THANG SINH VIEN ========================
struct sinh_vien
{
    std::string ho_ten;
    std::string ma_so;
    float diem_trung_binh;
};

// ! ========================== KHAI BAO CAU TRUC NHIEU THANG SINH VIEN ========================
struct danh_sach_sinh_vien
{
    sinh_vien arr[100]; // * Khai bao ra mang 1 chieu cac sinh vien chua toi da 100 sv
    int n;              // * So luong sinh vien hien co trong danh sach
};

// * Nhap 1 sinh vien
void nhap_thong_tin_1_sinh_vien(sinh_vien &sv)
{
    do
    {
        std::cout << "\nNhap Ho Ten sinh vien: ";
        fflush(stdin);
        std::getline(std::cin, sv.ho_ten);
        if (sv.ho_ten.length() > 30)
        {
            std::cout << "\n\t\tDo dai khong hop le! Xin nhap lai";
        }
    } while (sv.ho_ten.length() > 30);

    do
    {
        std::cout << "\nNhap Ma So sinh vien: ";
        fflush(stdin);
        std::getline(std::cin, sv.ma_so);
        if (sv.ma_so.length() > 10)
        {
            std::cout << "\n\t\tDo dai khong hop le! Xin nhap lai";
        }
    } while (sv.ma_so.length() > 10);

    do
    {
        std::cout << "\nNhap Diem Trung Binh: ";
        std::cin >> sv.diem_trung_binh;
        if (sv.diem_trung_binh < 0 || sv.diem_trung_binh > 10)
        {
            std::cout << "\n\t\tDiem khong hop le! Xin nhap lai";
        }
    } while (sv.diem_trung_binh < 0 || sv.diem_trung_binh > 10);
}

// * Ham xuat thong tin 1 sinh vien
void xuat_thong_tin_1_sinh_vien(sinh_vien sv)
{
    std::cout << "\nHo ten: " << sv.ho_ten;
    std::cout << "\nMa So: " << sv.ma_so;
    std::cout << "\nDiem trung binh: " << sv.diem_trung_binh;
}
// * Nhap nhap thong tin nhieu thang sinh vien
void nhap_thong_tin_nhieu_sinh_vien(danh_sach_sinh_vien &ds)
{
    for (int i = 0; i < ds.n; i++)
    {
        // * Goi lai ham nhap thong tin 1 thang sinh vien
        std::cout << "\n\n\t\tNHAP THONG TIN SINH VIEN THU " << i + 1;
        nhap_thong_tin_1_sinh_vien(ds.arr[i]);
    }
}

// * Xuat thong tin nhieu thang sinh vien
void xuat_thong_tin_nhieu_sinh_vien(danh_sach_sinh_vien ds)
{
    for (int i = 0; i < ds.n; i++)
    {
        std::cout << "\n\n\t\tTHONG TIN SINH VIEN THU " << i + 1;
        xuat_thong_tin_1_sinh_vien(ds.arr[i]);
    }
}

// ! Ham tim diem trung binh cao nhat
float tim_diem_trung_binh_cao_nhat(danh_sach_sinh_vien ds)
{
    float max = ds.arr[0].diem_trung_binh;
    for (int i = 1; i < ds.n; i++)
    {
        if (max < ds.arr[i].diem_trung_binh)
        {
            max = ds.arr[i].diem_trung_binh;
        }
    }
    return max;
}

// ! Thong tin sinh vien co diem trung binh thap nhat
void tim_sinh_vien_co_diem_trung_binh_thap_nhat(danh_sach_sinh_vien ds)
{
    // * Tim diem tb thap nhat
    float min = ds.arr[0].diem_trung_binh;
    for (int i = 1; i < ds.n; i++)
    {
        if (min > ds.arr[i].diem_trung_binh)
        {
            min = ds.arr[i].diem_trung_binh;
        }
    }

    // * Duyet danh sach sinh vien - Neu thang nao co diem tb thap nhat thi xuat ra
    int j(0);
    for (int i = 0; i < ds.n; i++)
    {
        if (ds.arr[i].diem_trung_binh == min)
        {
            j++;
            std::cout << "\n\n\t\tTHONG TIN SINH VIEN THU " << j;
            xuat_thong_tin_1_sinh_vien(ds.arr[i]);
        }
    }
}

int main()
{
    danh_sach_sinh_vien ds;
    std::cout << "\nNhap so luong sinh vien: ";
    std::cin >> ds.n;

    std::cout << "\n\n\t\t\tNHAP DANH SACH SINH VIEN\n";
    nhap_thong_tin_nhieu_sinh_vien(ds);

    std::cout << "\n\n\t\t\tXUAT DANH SACH SINH VIEN\n";
    xuat_thong_tin_nhieu_sinh_vien(ds);

    float max = tim_diem_trung_binh_cao_nhat(ds);
    std::cout << "\n\n\tDiem trung binh cao nhat la: " << max;

    std::cout << "\n\n\t\t\tDANH SACH SINH VIEN CO DIEM TRUNG BINH THAP NHAT";
    tim_sinh_vien_co_diem_trung_binh_thap_nhat(ds);

    system("pause");
    return 0;
}