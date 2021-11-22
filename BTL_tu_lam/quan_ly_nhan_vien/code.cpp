// ################################################################
// ###               Ban quyen thuoc ve K1ethoang                ###
// ################################################################
// ###      Ho Ten: Hoang Gia Kiet                               ###
// ###      MSSV: 6251071049                                     ###
// ###      Lop: CNTT K62                                        ###
// ###      Tool: VSCode              				             ###
// ###      BM CNTT - DH GIAO THONG VAN TAI TP.HCM              ###
// ###############################################################

#include <iostream>
#include <string.h>
#include <windows.h>
#include <fstream>
#include <iomanip>
using namespace std;

struct ngayThang
{
	short ngay, thang, nam;
};

struct NhanVien
{
	NhanVien() // hàm khởi tạo (Constructor)
	{
		this->maSo = -1;
		this->ho = "";
		this->ten = "";
		this->noiSinh = "";
		this->ngaySinh.ngay = 0;
		this->ngaySinh.thang = 0;
		this->ngaySinh.nam = 0;
		this->luong = 0;
	}
	string ho, ten, noiSinh;
	int maSo;
	ngayThang ngaySinh;
	double luong;
};

void nhap1NhanVien(NhanVien *input);
void xuat1NhanVienTheoHangDoc(NhanVien *output);
int kiemTraMaSo(NhanVien *nv, int n);
void nhapDanhSach(NhanVien *&input, int &n);
void xuatDanhSach(NhanVien *output, int n);
void resizeDanhSach(NhanVien *&nv, int before, int after);
void them1NhanVien(NhanVien *&add, int &n);
void xoa1NhanvienBatKi(NhanVien *&nv, int &n, int del_pos);
void xoa1NhanVienTheoMaSo(NhanVien *&del, int &n);
void timNhanVienTheoMaSo(NhanVien *nv, int n);
void timNhanVienTheoTen(NhanVien *nv, int n);
void hoanVi(NhanVien *a, NhanVien *b);
void sapXepGiamDanTheoLuong(NhanVien *nv, int n);
void luuDanhSach(NhanVien *ds, int n);
void pressAnyKey();
void menu();

int main()
{
	// system("color 72");
	// int pass = 2309;
	// do
	// {
	// 	cout << "\nNhap mat khau de chay chuong trinh: ";
	// 	cin >> pass;
	// 	if (pass != 2309)
	// 	{
	// 		cout << "\nSai mat khau :v";
	// 		pressAnyKey();
	// 		system("cls");
	// 	}
	// 	else
	// 	{
	// 		cout << "\nTruy cap thanh cong :>";
	// 		pressAnyKey();
	// 		system("cls");
	// 		for (int i = 10; i < 100; i += 20)
	// 		{
	// 			cout << "\nLoading " << i << "%"
	// 				 << "...";
	// 			Sleep(300);
	// 		}
	// 	}

	// } while (pass != 2309);

	menu();
	return 0;
}

void menu()
{
	NhanVien *nv = new NhanVien;
	int soLuong;

	bool exit = false, check = false; // check: kiểm tra xem đã nhập danh sách chưa
	short key;
	do
	{
		system("cls");
		cout << "\t+ ---------------- Chuong trinh quan ly nhan vien ---------------- +";
		cout << "\n\t|   1. Them danh sach nhan vien                                    |";
		cout << "\n\t|   2. Xem danh sach nhan vien                                     |";
		cout << "\n\t|   3. Them 1 nhan vien vao danh sach                              |";
		cout << "\n\t|   4. xoa 1 nhan vien theo ma so                                  |";
		cout << "\n\t|   5. Tim nhan vien theo ma so                                    |";
		cout << "\n\t|   6. Tim nhan vien theo ten                                      |";
		cout << "\n\t|   7. Bang luong cua nhan vien trong cong ty (giam dan)           |";
		cout << "\n\t|   8. Luu danh sach vao file \"danh_sach_sinh_vien.txt\"            |";
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

				cout << "\n\t\tBan da chon Xoa 1 nhan vien theo ma so\n";
				xoa1NhanVienTheoMaSo(nv, soLuong);
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
		case 8:
			if (check)
			{

				cout << "\n\t\tBan da chon Luu danh sach vao file\n";
				luuDanhSach(nv, soLuong);
				pressAnyKey();
			}
			else
			{
				cout << "\n\t\tNhap danh sach nhan vien di ban oi -.-";
				pressAnyKey();
			}
			break;
		default:
			cout << "\n\t\tTui khong biet ban dang chon lenh gi luon - Nhap lai deii :v";
			pressAnyKey();
			break;
		}

	} while (!exit);
}

void nhap1NhanVien(NhanVien *input)
{
	cout << "\n(?) Nhap ma so: ";
	cin >> input->maSo;
	fflush(stdin);
	cout << "\n(?) Nhap ho: ";
	getline(cin, input->ho);
	cout << "\n(?) Nhap ten: ";
	getline(cin, input->ten);
	cout << "\n(?) Nhap ngay sinh (dd/mm/yyyy - ngan cach bang khoang cach): ";
	cin >> input->ngaySinh.ngay >> input->ngaySinh.thang >> input->ngaySinh.nam;
	cout << "\n(?) Nhap noi sinh: ";
	fflush(stdin);
	getline(cin, input->noiSinh);
	cout << "\n(?) Luong (Tinh theo $): ";
	cin >> input->luong;
}

void xuat1NhanVienTheoHangDoc(NhanVien *output)
{
	cout << "\n++++++++++++++++++++++++++++++++++++++++++++++";
	cout << "\n+\tMa so: " << output->maSo;
	cout << "\n+\tHo: " << output->ho;
	cout << "\n+\tTen: " << output->ten;
	cout << "\n+\tNgay sinh: " << output->ngaySinh.ngay << '/' << output->ngaySinh.thang << '/' << output->ngaySinh.nam;
	cout << "\n+\tNoi sinh: " << output->noiSinh;
	cout << "\n+\tLuong: " << output->luong;
	cout << "\n++++++++++++++++++++++++++++++++++++++++++++++";
}

int kiemTraMaSo(NhanVien *nv, int n, int maSo)
{
	for (int i = 0; i < n; i++)
	{
		if (maSo == (nv + i)->maSo)
		{
			return i;
		}
	}
	return -1; // không có mã số trùng khớp
}

void nhapDanhSach(NhanVien *&input, int &n)
{
	do
	{
		cout << "\n-> Nhap so nhan vien: ";
		cin >> n;
		if (n <= 0)
		{
			cout << "\nSo luong khong hop le :v";
			pressAnyKey();
		}
	} while (n <= 0);

	input = new NhanVien[n];
	for (int i = 0; i < n; i++)
	{
		cout << "\n\tNhap nhan vien thu [" << i + 1 << "]\n";
		nhap1NhanVien(input + i);
		for (int j = i - 1; j >= 0; j--)
		{
			do
			{
				if ((input + j)->maSo == (input + i)->maSo)
				{
					cout << "\n\tMa so cua nhan vien ban vua nhap trung voi ma so nhan vien thu [" << j + 1 << "]\n";
					cout << "\n-> Moi ban nhap lai ma so khac: ";
					cin >> (input + i)->maSo;
					pressAnyKey();
				}
			} while ((input + j)->maSo == (input + i)->maSo);
		}
	}
}

void xuatDanhSach(NhanVien *output, int n)
{
	for (int i = 0; i < n; i++)
	{
		cout << "\n\n\t\t-> Nhan vien thu [" << i + 1 << "]\n";
		xuat1NhanVienTheoHangDoc(output + i);
	}
}

// cấp phát lại vùng nhớ cho mảng động
void resizeDanhSach(NhanVien *&nv, int before, int after)
{
	NhanVien *temp = new NhanVien[before]; // kích thước bằng với mảng ban đầu
	for (int i = 0; i < before; i++)
	{
		*(temp + i) = *(nv + i); // chuyển các dữ liệu qua mảng temp
	}
	delete[] nv;			  // xoá đi vùng nhớ cũ
	nv = new NhanVien[after]; // cấp phát vùng nhớ mới
	for (int i = 0; i < before; i++)
	{
		*(nv + i) = *(temp + i); // trả dữ liệu lại mảng ban đầu
	}
	delete[] temp; // xoá vùng nhớ của con trỏ temp;
}

void them1NhanVien(NhanVien *&add, int &n)
{
	resizeDanhSach(add, n, n + 1);
	nhap1NhanVien(add + n);
	do
	{ // kiểm tra xem mã số nv vừa thêm đã tồn tại chưa
		if (kiemTraMaSo(add, n, (add + n)->maSo) != -1)
		{
			cout << "\nDa ton tai nhan vien co ma so nay :))";
			cout << "\nNhap lai ma so khac: ";
			cin >> (add + n)->maSo;
			pressAnyKey();
		}

	} while (kiemTraMaSo(add, n, (add + n)->maSo) != -1);
	cout << "\n\tThem nhan vien thanh cong :>";
	xuat1NhanVienTheoHangDoc(add + n);
	n++;
}

void xoa1NhanvienBatKi(NhanVien *&nv, int &n, int del_pos)
{
	for (int i = del_pos + 1; i < n; i++)
	{
		*(nv + i - 1) = *(nv + i);
	}
	cout << "\n\n\tXoa thanh cong :>";
	resizeDanhSach(nv, n, n - 1);
	n--;
}

void xoa1NhanVienTheoMaSo(NhanVien *&del, int &n)
{
	int maSo;
	cout << "\nNhap ma so cua nhan vien can xoa: ";
	cin >> maSo;

	bool check = false;				   // biên kiểm tra xem có nhân viên đó không
	int i = kiemTraMaSo(del, n, maSo); // vị trí của mã số kiểm tra
	if (i == -1)

		check = false;
	else
	{
		xoa1NhanvienBatKi(del, n, i);
		check = true;
	}

	if (check == false)
		cout << "\nkhong co nhan vien trung khop :v";
}

void timNhanVienTheoMaSo(NhanVien *nv, int n)
{
	bool check = false;
	int maSoCanTim;
	cout << "\nNhap ma so can tim: ";
	cin >> maSoCanTim;
	for (int i = 0; i < n; i++)
	{

		if ((nv + i)->maSo == maSoCanTim)
		{
			check = true;
			xuat1NhanVienTheoHangDoc(nv + i);
		}
	}

	if (check == false)
		cout << "\nKhong tim thay @@ - Chac chan rang ban ko ngao chu :))";
}

void timNhanVienTheoTen(NhanVien *nv, int n)
{
	bool check = false;
	string tenCanTim;
	cout << "\nNhap ten can tim: ";
	cin >> tenCanTim;

	for (int i = 0; i < n; i++)
	{

		if ((nv + i)->ten.find(tenCanTim) != string::npos)
		{
			check = true;
			xuat1NhanVienTheoHangDoc(nv + i);
		}
	}

	if (check == false)
		cout << "\nKhong tim thay @@ - Chac chan rang ban ko ngao chu :))";
}

void hoanVi(NhanVien *a, NhanVien *b)
{
	NhanVien *temp = new NhanVien;
	*temp = *a;
	*a = *b;
	*b = *temp;

	delete temp;
}

void sapXepGiamDanTheoLuong(NhanVien *nv, int n)
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

void luuDanhSach(NhanVien *ds, int n)
{
	ofstream file;
	file.open("danh_sach_sinh_vien.txt", ios_base::out);

	bool check = false;

	if (file.fail())
		cout << "\nLoi khi mo file";
	else
	{

		check = true;
		for (int i = 0; i < n; i++)
		{
			file << (ds + i)->maSo << ", ";
			file << (ds + i)->ho << ", ";
			file << (ds + i)->ten << ", ";
			file << (ds + i)->ngaySinh.ngay << " " << (ds + i)->ngaySinh.thang << " " << (ds + i)->ngaySinh.nam << ", ";
			file << (ds + i)->noiSinh << ", ";
			file << (ds + i)->luong << endl;
		}
	}

	if (check)
		cout << "\n\t\tLuu File thanh cong <3";

	file.close();
}

void pressAnyKey()
{
	cout << endl;
	system("pause");
	system("cls");
}
