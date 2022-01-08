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
    void setCode(int _code);
    string getFullName();
    float getSalary();
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
    cout << "\nNhap luong (dollar): ";
    is >> e.salaryAmountInDollar;
    return is;
}

ostream &operator<<(ostream &os, Employee e)
{
    os << "\nMa so nhan vien: " << e.code;
    os << "\nHo va ten: " << e.fullName;
    os << "\nQue quan: " << e.homeTown;
    os << "\nNgay sinh: " << e.day << "/" << e.month << "/" << e.year;
    os << "\nLuong: " << e.salaryAmountInDollar << " (dollar)";
    return os;
}

int Employee::getCode()
{
    return this->code;
}

void Employee::setCode(int _code)
{
    this->code = _code;
}

string Employee::getFullName()
{
    return this->fullName;
}

float Employee::getSalary()
{
    return this->salaryAmountInDollar;
}

void Employee::read(ifstream &ifs)
{
    string s;
    ifs >> this->code;
    getline(ifs, s);
    getline(ifs, this->fullName);
    getline(ifs, this->homeTown);
    ifs >> this->day >> this->month >> this->year;
    ifs >> this->salaryAmountInDollar;
}

void Employee::write(ofstream &ofs)
{
    ofs << this->code << ", ";
    ofs << this->fullName << ", ";
    ofs << this->homeTown << ", ";
    ofs << this->day << " " << this->month << " " << this->year << ", ";
    ofs << this->salaryAmountInDollar;
}
