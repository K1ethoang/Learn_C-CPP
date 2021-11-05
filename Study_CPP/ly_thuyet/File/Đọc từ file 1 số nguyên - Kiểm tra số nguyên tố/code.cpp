// ! Đọc từ file 1 số nguyên - Kiểm tra số nguyên tố

#include <iostream>
#include <fstream>
#include <cmath>

using namespace std;

bool kiem_tra_so_nguyen_to(const int &n)
{
    if (n < 2)
        return 0;
    else
    {
        if (n == 2)
            return 1;
        else
        {
            for (int i = 2; i <= sqrt(n); i++)
            {
                if (n % i == 0)
                {
                    return 0;
                    break;
                }
            }
        }
    }
    return 1;
}

int main()
{
    ifstream filein; // khai báo ra lớp để đọc dữ liệu từ file
    filein.open("input.txt", ios_base::in);

    if (filein.fail() != true) // Kiem tra mo duoc file khong
    {
        cout << "Mo file thanh cong";
        system("pause");
    }

    int n;
    filein >> n;

    filein.close();

    ofstream fileout;
    fileout.open("output.txt", ios_base::out);
    if (kiem_tra_so_nguyen_to(n) == 1)

        fileout << "True"; // Ghi du lieu vao file

    else
        fileout << "False";

    fileout.close();

    return 0;
}