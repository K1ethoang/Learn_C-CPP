#include <iostream>
#include <fstream>
using namespace std;

int main()
{
    // * =================== ĐỌC FILE ===================
    //! CÚ PHÁP: ifstream <Tên biến file>;
    // * B1: KHAI BÁO RA BIẾN ĐỂ ĐỌC FILE
    ifstream FileIn; // Khai báo ra 1 biến FileIn đẻ đọc dữ liệu từ file

    // * B2: MỞ FILE CẦN ĐỌC DỮ LIỆU
    // * open(<tên đường dẫn đến file cần mở - để đọc - đây là 1 cái chuỗi>, chế độ làm việc với file);
    FileIn.open("input.txt", ios_base::in);

    if (FileIn.fail() == true)
    {
        cout << "\nFile cua ban khong ton tai";
        return 0;
    }

    // * B3: XỬ LÍ FILE - ĐỌC DỮ LIẸU TỪ FILE RA CHƯƠNG TRÌNH
    int x;
    int y;
    // cin >> x >> y;
    FileIn >> x >> y; // Đọc dữ liệu từ file
    cout << x << " + " << y << " = " << x + y;

    // * B4: ĐÓNG FILE LẠI SAU KHI XỬ LÍ
    FileIn.close(); // Đóng file lại sau khi xử lí

    // * =================== GHI FILE ===================

    ofstream FileOut;
    FileOut.open("output.txt", ios_base::out);
    FileOut << "\nTong 2 so nguyen " << x << " + " << y << " = " << x + y;
    // Lấy x + y rồi ghi vào file output.txt
    FileOut.close();

    return 0;
}