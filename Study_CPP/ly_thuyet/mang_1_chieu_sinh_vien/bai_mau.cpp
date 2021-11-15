#include <iostream>
#include <string>

/*
Thiet ke chuong trinh luu tru thong tin sinh vien
biet thong tin sinh vien gom:
- Ma so
- Ho ten
- Nam sinh
- Diem trung binh
1. Khai bao cau truc sinh vien
2. Nhap danh sach sinh vien
3. Xuat danh sach sinh vien
4. Tim kiem thong tin sinh vien dua vao diem trung binh
5. Them 1 sinh vien vao vi tri bat ki
6. Xoa 1 sinh vien co diem trung binh duoi 5
7. Sap xep sinh vien tang dan theo diem trung binh
*/

// ! Khai bao cau truc 1 sinh vien
struct sinh_vien
{
    std::string ma_so;
    std::string ho_ten;
    short nam_sinh;
    float diem_trung_binh;
};

// * Nhap 1 sinh vien
void nhap_thong_tin_1_sinh_vien(sinh_vien &sv)
{
    while (getchar() != '\n')
        ; // rewind(stdin)
    do
    {
        std::cout << "\nNhap Ma So sinh vien: ";
        std::getline(std::cin, sv.ma_so);
        if (sv.ma_so.length() > 20)
        {
            std::cout << "\nDo dai khong hop le !";
            system("pause");
        }
    } while (sv.ma_so.length() > 20);

    do
    {
        std::cout << "\nNhap Ho Ten sinh vien: ";
        std::getline(std::cin, sv.ho_ten);
        if (sv.ho_ten.length() > 30)
        {
            std::cout << "\nDo dai khong hop le !";
            system("pause");
        }
    } while (sv.ho_ten.length() > 30);

    std::cout << "\nNhap Nam Sinh: ";
    std::cin >> sv.nam_sinh;
    do
    {
        std::cout << "\nNhap Diem Trung Binh: ";
        std::cin >> sv.diem_trung_binh;
        if (sv.diem_trung_binh < 0 || sv.diem_trung_binh > 10)
        {
            std::cout << "\nDiem khong hop le !";
            system("pause");
        }
    } while (sv.diem_trung_binh < 0 || sv.diem_trung_binh > 10);
}

// * Ham xuat thong tin 1 sinh vien
void xuat_thong_tin_1_sinh_vien(sinh_vien sv)
{
    std::cout << "\nMa So: " << sv.ma_so;
    std::cout << "\nHo ten: " << sv.ho_ten;
    std::cout << "\nNam sinh: " << sv.nam_sinh;
    std::cout << "\nDiem trung binh: " << sv.diem_trung_binh;
}

// ! Ham nhap danh sach sinh vien
void nhap_danh_sach_sinh_vien(sinh_vien arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        std::cout << "\n\n\t\tNHAP THONG TIN SINH VIEN " << i + 1 << std::endl;
        nhap_thong_tin_1_sinh_vien(arr[i]);
    }
}

// ! Ham xuat danh sach sinh vien
void xuat_danh_sach_sinh_vien(sinh_vien arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        std::cout << "\n\n\t\tTHONG TIN SINH VIEN THU " << i + 1 << std::endl;
        xuat_thong_tin_1_sinh_vien(arr[i]);
    }
    system("pause");
}

// ! Tim kiem thong tin sinh vien dua vao diem trung binh
void tim_kiem_thong_tin_sinh_vien_theo_diem_tb(sinh_vien arr[], int n, float diem_tb)
{
    short dem = 0;
    for (int i = 0; i < n; i++)
    {
        if (arr[i].diem_trung_binh == diem_tb)
        {
            dem++;
            std::cout << "\n\n\t\tTHONG TIN SINH VIEN THU " << dem << std::endl;
            xuat_thong_tin_1_sinh_vien(arr[i]);
        }
        std::cout << std::endl;
    }
}

// ! Them 1 sinh vien vao vi tri bat ki
void them_1_sinh_vien_vao_vi_tri_bat_ki(sinh_vien arr[], int &n, int vitrithem, sinh_vien x)
{
    for (int i = n - 1; i >= vitrithem; i--)
    {
        arr[i + 1] = arr[i];
    }
    arr[vitrithem] = x;
    n++;
}

// ! Xoa sinh vien co diem tb duoi 5
void xoa_sinh_vien_1_vi_tri_bat_ki(sinh_vien arr[], int &n, int vitri)
{
    for (int i = vitri + 1; i < n; i++)
    {
        arr[i - 1] = arr[i];
    }
    n--;
}

void xoa_cac_sinh_vien_co_diem_tb_duoi_5(sinh_vien arr[], int &n)
{
    for (int i = 0; i < n; i++)
    {
        if (arr[i].diem_trung_binh < 5)
        {
            xoa_sinh_vien_1_vi_tri_bat_ki(arr, n, i);
            i--;
        }
    }
}

// * Ham hoan vi
void hoan_vi(sinh_vien &x, sinh_vien &y)
{
    sinh_vien temp;
    temp = x;
    x = y;
    y = temp;
}

// !  Sap xep sinh vien tang dan theo diem trung binh
void sap_xep_tang_dan_diem_tb(sinh_vien arr[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (arr[i].diem_trung_binh > arr[j].diem_trung_binh)
            {
                hoan_vi(arr[i], arr[j]);
            }
        }
    }
}
int main()
{
    sinh_vien ds_sinh_vien[100];
    int n;
    std::cout << "\nNhap so luong sinh vien can nhap: ";
    std::cin >> n;
    std::cout << "\n\n\t\t\tNHAP DANH SACH SINH VIEN\n";
    nhap_danh_sach_sinh_vien(ds_sinh_vien, n);
    std::cout << "\n\n\t\t\tXUAT DANH SACH SINH VIEN\n";
    xuat_danh_sach_sinh_vien(ds_sinh_vien, n);

    /* float diem_tim_kiem;
    std::cout << "\nNhap diem can tim kiem: ";
    std::cin >> diem_tim_kiem;
    std::cout << "\n\n\t\t\tSINH VIEN TRUNG KHOP VOI DIEM\n";
    tim_kiem_thong_tin_sinh_vien_theo_diem_tb(ds_sinh_vien, n, diem_tim_kiem);

    int vi_tri_can_them;
    sinh_vien sv_can_them;
    std::cout << "\nNhap vi tri can them: ";
    std::cin >> vi_tri_can_them;
    std::cout << "\n\n\t\t\tNHAP THONG TIN SINH VIEN CAN THEM\n";
    nhap_thong_tin_1_sinh_vien(sv_can_them);
    them_1_sinh_vien_vao_vi_tri_bat_ki(ds_sinh_vien, n, vi_tri_can_them, sv_can_them);
    std::cout << "\n\n\t\t\tXUAT DANH SACH SINH VIEN\n";
    xuat_danh_sach_sinh_vien(ds_sinh_vien, n); */

    std::cout << "\n\n\t\t\tDANH SACH SINH VIEN SAU KHI SAP XEP\n";
    sap_xep_tang_dan_diem_tb(ds_sinh_vien, n);
    xuat_danh_sach_sinh_vien(ds_sinh_vien, n);

    xoa_cac_sinh_vien_co_diem_tb_duoi_5(ds_sinh_vien, n);
    std::cout << "\n\n\t\t\tDANH SACH SAU KHI XOA CAC SINH VIEN CO DIEM TRUNG BINH DUOI 5\n";
    xuat_danh_sach_sinh_vien(ds_sinh_vien, n);

    system("pause");
    return 0;
}