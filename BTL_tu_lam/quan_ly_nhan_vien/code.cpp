// ###############################################################
// ###               Ban quyen thuoc ve K1ethoang               ###
// ###############################################################
// ###      Ho Ten: Hoang Gia Kiet                              ###
// ###      MSSV: 6251071049                                    ###
// ###      Lop: CNTT K62                                       ###
// ###      Moi truong thuc hien: VSCode                        ###
// ###      BM CNTT - DH GIAO THONG VAN TAI TP.HCM              ###
// ###############################################################

#include <iostream>
#include <string.h>
#include <windows.h>
using namespace std;

struct ngayThang
{
	short ngay, thang, nam;
};

struct nhanVien
{
	string maSo, ho, ten, noiSinh, diaChi;
	ngayThang ngaySinh, ngayCongTac;
	double luong;
};

void nhap1NhanVien(nhanVien *input);
void xuat1NhanVienTheoHangDoc(nhanVien *output);
void nhapDanhSach(nhanVien *&input, int &n);
void xuatDanhSach(nhanVien *output, int n);
void resizeDanhSach(nhanVien *&nv, int before, int after);
void them1NhanVien(nhanVien *&add, int &n);
void xoa1NhanVien(nhanVien *&del, int &n);
void timNhanVienTheoMaSo(nhanVien *nv, int n);
void timNhanVienTheoTen(nhanVien *nv, int n);
void hoanVi(nhanVien *a, nhanVien *b);
void sapXepGiamDanTheoLuong(nhanVien *nv, int n);

void line(int n);
void pressAnyKey();
void menu();

int main()
{
	system("color 72");
	int pass = 2309;
	do
	{
		cout << "\nNhap mat khau de chay chuong trinh: ";
		cin >> pass;
		if (pass != 2309)
		{
			cout << "\nSai mat khau :v";
			pressAnyKey();
			system("cls");
		}
		else
		{
			cout << "\nTruy cap thanh cong :>";
			pressAnyKey();
			system("cls");
			for (int i = 10; i < 100; i += 20)
			{
				cout << "\nLoading " << i << "...";
				Sleep(300);
				system("cls");
			}
		}

	} while (pass != 2309);

	menu();
	return 0;
}

void menu()
{
	nhanVien *nv = new nhanVien;
	int soLuong;

	bool exit = false, check = false; // check: kiểm tra xem đã nhập danh sách chưa
	short key;
	do
	{
		cout << "\t+ ---------------- Chuong trinh quan ly nhan vien ---------------- +";
		cout << "\n\t|   1. Them danh sach nhan vien                                    |";
		cout << "\n\t|   2. Xem danh sach nhan vien                                     |";
		cout << "\n\t|   3. Them 1 nhan vien vao danh sach                              |";
		cout << "\n\t|   4. xoa 1 nhan vien vao danh sach                               |";
		cout << "\n\t|   5. Tim nhan vien theo ma so                                    |";
		cout << "\n\t|   6. Tim nhan vien theo ten                                      |";
		cout << "\n\t|   7. Bang luong cua nhan vien trong cong ty (giam dan)           |";
		cout << "\n\t|   0. Thoat chuong trinh                                          |";
		cout << "\n\t+ -------------------------- Cam on <3 --------------------------- +";

		cout << "\n\t\t-> Nhap lenh: ";
		cin >> key;

		switch (key)
		{
		case 0:
			cout << "\nBye ban nha <3";
			exit = true;
			pressAnyKey();
			break;

		case 1:
			check = true;
			cout << "\n\t\tBan da chon Them danh sach nhan vien\n";
			nhapDanhSach(nv, soLuong);
			pressAnyKey();
			break;
		case 2:
			if (check)
			{

				cout << "\n\t\tBan da chon Xem danh sach nhan vien\n";
				xuatDanhSach(nv, soLuong);
				pressAnyKey();
			}
			else
			{
				cout << "\n\t\tNhap danh sach nhan vien di ban oi -.-";
				pressAnyKey();
			}
			break;

		case 3:
			if (check)
			{

				cout << "\n\t\tBan da chon Them 1 nhan vien\n";
				them1NhanVien(nv, soLuong);
				pressAnyKey();
			}
			else
			{
				cout << "\n\t\tNhap danh sach nhan vien di ban oi -.-";
				pressAnyKey();
			}
			break;
		case 4:
			if (check)
			{

				cout << "\n\t\tBan da chon Xoa 1 nhan vien\n";
				xoa1NhanVien(nv, soLuong);
				pressAnyKey();
			}
			else
			{
				cout << "\n\t\tNhap danh sach nhan vien di ban oi -.-";
				pressAnyKey();
			}
			break;
		case 5:
			if (check)
			{

				cout << "\n\t\tBan da chon Tim nhan vien theo ma so\n";
				timNhanVienTheoMaSo(nv, soLuong);
				pressAnyKey();
			}
			else
			{
				cout << "\n\t\tNhap danh sach nhan vien di ban oi -.-";
				pressAnyKey();
			}
			break;
		case 6:
			if (check)
			{

				cout << "\n\t\tBan da chon Tim nhan vien theo ten\n";
				timNhanVienTheoTen(nv, soLuong);
				pressAnyKey();
			}
			else
			{
				cout << "\n\t\tNhap danh sach nhan vien di ban oi -.-";
				pressAnyKey();
			}
			break;
		case 7:
			if (check)
			{

				cout << "\n\t\tBan da chon Bang luong cua nhan vien trong cong ty\n";
				sapXepGiamDanTheoLuong(nv, soLuong);
				xuatDanhSach(nv, soLuong);
				pressAnyKey();
			}
			else
			{
				cout << "\n\t\tNhap danh sach nhan vien di ban oi -.-";
				pressAnyKey();
			}
			break;
		default:
			cout << "\n\t\tTui ca chac la ban bi ngao - Nhap lai deii :v";
			pressAnyKey();
			break;
		}

	} while (!exit);
}
void nhap1NhanVien(nhanVien *input)
{
	fflush(stdin);
	cout << "\nNhap ma so: ";
	getline(cin, input->maSo);
	cout << "\nNhap ho: ";
	getline(cin, input->ho);
	cout << "\nNhap ten: ";
	getline(cin, input->ten);
	cout << "\nNhap ngay sinh (dd/mm/yyyy - ngan cach bang khoang cach): ";
	cin >> input->ngaySinh.ngay >> input->ngaySinh.thang >> input->ngaySinh.nam;
	cout << "\nNhap noi sinh: ";
	fflush(stdin);
	getline(cin, input->noiSinh);
	cout << "\nNhap dia chi: ";
	getline(cin, input->diaChi);
	cout << "\nNhap ngay cong tac (dd/mm/yyyy - ngan cach bang khoang cach): ";
	cin >> input->ngayCongTac.ngay >> input->ngayCongTac.thang >> input->ngayCongTac.nam;
	cout << "\nLuong: ";
	cin >> input->luong;
}

void xuat1NhanVienTheoHangDoc(nhanVien *output)
{
	cout << "\n++++++++++++++++++++++++++++++++++++++++++++++";
	cout << "\n+\tMa so: " << output->maSo;
	cout << "\n+\tHo: " << output->ho;
	cout << "\n+\tTen: " << output->ten;
	cout << "\n+\tNgay sinh: " << output->ngaySinh.ngay << '/' << output->ngaySinh.thang << '/' << output->ngaySinh.nam;
	cout << "\n+\tNoi sinh: " << output->noiSinh;
	cout << "\n+\tDia chi: " << output->diaChi;
	cout << "\n+\tNgay cong tac: " << output->ngayCongTac.ngay << '/' << output->ngayCongTac.thang << '/' << output->ngayCongTac.nam;
	cout << "\n+\tLuong: " << output->luong;
	cout << "\n++++++++++++++++++++++++++++++++++++++++++++++";
}

void nhapDanhSach(nhanVien *&input, int &n)
{
	cout << "\nNhap so nhan vien: ";
	cin >> n;
	input = new nhanVien[n];
	for (int i = 0; i < n; i++)
	{
		cout << "\n\tNhap nhan vien thu [" << i + 1 << "]\n";
		nhap1NhanVien(input + i);
	}
}

void xuatDanhSach(nhanVien *output, int n)
{
	for (int i = 0; i < n; i++)
	{
		cout << "\n\n\t\tNhan vien thu [" << i + 1 << "]\n";
		xuat1NhanVienTheoHangDoc(output + i);
	}
}

// cấp phát lại vùng nhớ cho mảng động
void resizeDanhSach(nhanVien *&nv, int before, int after)
{
	nhanVien *temp = new nhanVien[before];
	for (int i = 0; i < before; i++)
	{
		*(temp + i) = *(nv + i); // chuyển các dữ liệu qua mảng temp
	}
	delete[] nv;			  // xoá đi vùng nhớ cũ
	nv = new nhanVien[after]; // cấp phát vùng nhớ mới
	for (int i = 0; i < before; i++)
	{
		*(nv + i) = *(temp + i); // trả dữ liệu lại mảng ban đầu
	}
	delete[] temp; // xoá vùng nhớ của con trỏ temp;
}

void them1NhanVien(nhanVien *&add, int &n)
{
	resizeDanhSach(add, n, n + 1);
	nhap1NhanVien(add + n);
	n++;
}

void xoa1NhanVien(nhanVien *&del, int &n)
{
	int pos;
	cout << "\nVi tri can xoa: ";
	cin >> pos;

	if (pos <= 0 || pos > n)
		cout << "\nVi tri can xoa khong hop le! - Chac chan rang ban ko ngao chu :))";
	else
	{

		pos -= 1;
		for (int i = pos + 1; i < n; i++)
		{
			*(del + i - 1) = *(del + i);
		}
		n--;
		cout << "\n\n\tXoa thanh cong :>";
	}
}

void timNhanVienTheoMaSo(nhanVien *nv, int n)
{
	bool check = false;
	string codeToFind;
	fflush(stdin);
	cout << "\nNhap ma so can tim: ";
	getline(cin, codeToFind);
	for (int i = 0; i < n; i++)
	{

		if ((nv + i)->maSo.find(codeToFind) != string::npos)
		{
			check = true;
			xuat1NhanVienTheoHangDoc(nv + i);
		}
	}

	if (check == false)
		cout << "\nKhong tim thay @@ - Chac chan rang ban ko ngao chu :))";
}

void timNhanVienTheoTen(nhanVien *nv, int n)
{
	bool check = false;
	string nameToFind;
	fflush(stdin);
	cout << "\nNhap ten can tim: ";
	getline(cin, nameToFind);
	for (int i = 0; i < n; i++)
	{

		if ((nv + i)->ten.find(nameToFind) != string::npos)
		{
			check = true;
			xuat1NhanVienTheoHangDoc(nv + i);
		}
	}

	if (check == false)
		cout << "\nKhong tim thay @@ - Chac chan rang ban ko ngao chu :))";
}

void hoanVi(nhanVien *a, nhanVien *b)
{
	nhanVien *temp = new nhanVien;
	*temp = *a;
	*a = *b;
	*b = *temp;

	delete temp;
}

void sapXepGiamDanTheoLuong(nhanVien *nv, int n)
{
	for (int i = 0; i < n - 1; i++)
	{
		int maxPos = i;
		for (int j = i + 1; j < n; j++)
		{
			if ((nv + j)->luong > (nv + i)->luong)
				maxPos = j;
		}
		if (maxPos != i)
			hoanVi((nv + i), (nv + maxPos));
	}
}

void line(int n)
{
	cout << endl;
	for (int i = 0; i < n; i++)
	{
		cout << '-';
	}
	cout << endl;
}

void pressAnyKey()
{
	cout << endl;
	system("pause");
	system("cls");
}
