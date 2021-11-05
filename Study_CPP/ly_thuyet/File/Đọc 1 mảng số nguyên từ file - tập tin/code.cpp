// ! Đọc 1 mảng số nguyên từ file - tập tin
#include <iostream>
#include <fstream>
using namespace std;

// ! bai 1
/* Đọc 1 dãy số nguyên từ file INPUT.TXT
+ dòng đầu tiên là số lượng các số nguyên hiện có trong file
+ dòng tiếp theo là 1 dãy các số nguyên
INPUT.TXT
5
1 2 3 4 5
Ghi vào file KETQUA.TXT */
// ! bai 2
/* Đọc 1 dãy số nguyên từ file INPUT.TXT
+ dòng tiếp theo là 1 dãy các số nguyên
INPUT.TXT
1 2 3 4 5
Ghi vào file KETQUA.TXT */
int main()
{
    ifstream filein;
    filein.open("INPUT.txt", ios_base::in);

    if (filein.fail())
    {
        cout << "Mo file that bai";
        system("pause");
        return 0;
    }

    int a[100];
    int i = 0;
    int count = 0;
    // * Đọc mảng số nguyên từ file bằng cách kiểm tra nếu con trỏ chỉ vị chưa đến cuối file thì tiếp tục đọc
    while (!filein.eof()) // <=> !filein.eof() // * con trỏ chỉ vị chưa nằm cuối file
    {
        filein >> a[i];
        i++;
        count++;
    }
    filein.close();

    ofstream fileout;
    fileout.open("KETQUA.txt", ios_base::out);
    for (int i = 0; i < count; i++)
    {
        fileout << a[i] << " ";
    }
    fileout.close();
    return 0;
}