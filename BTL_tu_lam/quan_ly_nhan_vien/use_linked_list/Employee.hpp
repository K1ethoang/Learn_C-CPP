#pragma once
#include <iostream>
#include <string>
#include <fstream>
using namespace std;

class Employee
{
private:
    int code;
    string fullName;
    string homeTown;
    int day, month, year;
    float salaryAmountInDollar;

public:
    Employee();
    friend istream &operator>>(istream &is, Employee &e);
    friend ostream &operator<<(ostream &os, Employee e);
    int getCode();
    // string getFullName();
    // string getHomeTown();
    // int getDay();
    // int getMonth();
    // int getYear();
    // float getSalary();
    void read(ifstream &ifs);
    void write(ofstream &ofs);
};

Employee::Employee()
{
    this->fullName = "";
    this->code = 0;
    this->homeTown = "";
    this->day = 0;
    this->month = 0;
    this->year = 0;
    this->salaryAmountInDollar = 0.0;
}

istream &operator>>(istream &is, Employee &e)
{
    cout << "\nNhap ma so nhan vien: ";
    is >> e.code;
    fflush(stdin);
    cout << "\nNhap ho va ten: ";
    getline(is, e.fullName);
    cout << "\nNhap que quan: ";
    getline(is, e.homeTown);
    cout << "\nNgay sinh (dd/mm/yyyy - cach nhau boi khoang trang): ";
    is >> e.day >> e.month >> e.year;
    cout << "\nNhap luong (don vi nghin $): ";
    is >> e.salaryAmountInDollar;
    return is;
}

ostream &operator<<(ostream &os, Employee e)
{
    os << "\nMa so nhan vien: " << e.code;
    os << "\nHo va ten: " << e.fullName;
    os << "\nQue quan: " << e.homeTown;
    os << "\nNgay sinh: " << e.day << "/" << e.month << "/" << e.year;
    os << "\nLuong: " << e.salaryAmountInDollar << "k (dollar)";
    return os;
}

int Employee::getCode()
{
    return this->code;
}

// string Employee::getFullName()
// {
//     return this->fullName;
// }

// string Employee::getHomeTown()
// {
//     return this->homeTown;
// }

// int Employee::getDay()
// {
//     return this->day;
// }

// int Employee::getMonth()
// {
//     return this->month;
// }

// int Employee::getYear()
// {
//     return this->year;
// }

// float Employee::getSalary()
// {
//     return this->salaryAmountInDollar;
// }

void Employee::read(ifstream &ifs)
{
}

void Employee::write(ofstream &ofs)
{

    ofs << this->code << endl;
    ofs << this->fullName << endl;
    ofs << this->homeTown << endl;
    ofs << this->day << endl;
    ofs << this->month << endl;
    ofs << this->year << endl;
    ofs << this->salaryAmountInDollar << endl;
}
