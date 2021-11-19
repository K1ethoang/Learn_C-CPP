
// ⢀⣤⣀⣀⣀⠀⠈⠻⣷⣄
// ⠀⠀⠀⠀⢀⣴⣿⣿⣿⡿⠋⠀⠀⠀⠹⣿⣦⡀
// ⠀⠀⢀⣴⣿⣿⣿⣿⣏⠀⠀⠀⠀⠀⠀⢹⣿⣧
// ⠀⠀⠙⢿⣿⡿⠋⠻⣿⣿⣦⡀⠀⠀⠀⢸⣿⣿⡆
// ⠀⠀⠀⠀⠉⠀⠀⠀⠈⠻⣿⣿⣦⡀⠀⢸⣿⣿⡇
// ⠀⠀⠀⠀⢀⣀⣄⡀⠀⠀⠈⠻⣿⣿⣶⣿⣿⣿⠁
// ⠀⠀⠀⣠⣿⣿⢿⣿⣶⣶⣶⣶⣾⣿⣿⣿⣿⡁
// ⢠⣶⣿⣿⠋⠀⠉⠛⠿⠿⠿⠿⠿⠛⠻⣿⣿⣦⡀
// ⣿⣿⠟⠁⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠈⠻⣿⡿

// ! Nhập vào tháng và năm. Xuất ra SỐ NGÀY của tháng đó
#include <iostream>
using namespace std;

bool check_year(int *year)
{
    if ((*year % 4 == 0 && *year % 100 != 0) || *year % 400 == 0) // Nam nhuan
        return true;
    else
        return false;
}

int main()
{

    int *month = new int, *year = new int, *day = new int;

    do
    {
        system("cls");
        cout << "(?) Enter month and year: ";
        cin >> *month >> *year;
    } while (*month <= 0 || *month > 12 || *year <= 0);
    switch (*month)
    {
    case 1:
    case 3:
    case 5:
    case 7:
    case 8:
    case 10:
    case 12:
        *day = 31;
        break;
    case 4:
    case 6:
    case 9:
    case 11:
        *day = 30;
        break;
    case 2:
        if (check_year(year) == true)
            *day = 29;
        else
            *day = 28;
        break;
    }
    cout << "\nMonth: " << *month << " and year: " << *year << " -> " << *day;

    delete month;
    delete year;
    delete day;
    return 0;
}
