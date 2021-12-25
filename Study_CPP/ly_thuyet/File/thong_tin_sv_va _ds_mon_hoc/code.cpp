#include <iostream>
using namespace std;
#include <fstream>
#include <string>
#include <vector>
#include <cstring>

struct Subject
{
    string fullname;
    float mark;
};

struct Student
{
    string fullname;
    string code;
    // int date, month, year;
    string yearOfBirth;
    // mang cac mon hoc cua sinh vien
    vector<Subject> subjects;
};
void readStudent(ifstream &fileIn, Student &s);
void readSubject(ifstream &fileIn, Subject &s);
void importStudens(ifstream &fileIn, vector<Student> &s);
void outputOneStudent(Student s);
void outputStudents(vector<Student> s);

// câu 2: hàm xuất tất cả thồng tin của sinh viên có tên trùng
void findStudentByFullname(vector<Student> s, string fullname);

int main()
{
    vector<Student> students;
    ifstream fileIn;
    fileIn.open("sinhVien.txt", ios::in);

    importStudens(fileIn, students);
    outputStudents(students);

    string fullname;
    cout << "\nNhap ho ten sinh vien: ";
    getline(cin, fullname);
    findStudentByFullname(students, fullname);

    fileIn.close();
    return 0;
}

void readStudent(ifstream &fileIn, Student &s)
{
    getline(fileIn, s.fullname, ','); // đọc dữ liệu đến dấu phẩy thì dừng
    // fileIn.seekg(1, ios::cur);
    getline(fileIn, s.code, ',');
    // fileIn.seekg(1, ios::cur);
    getline(fileIn, s.yearOfBirth);
    // fileIn >> s.date;
    // fileIn.seekg(1, ios::cur);
    // fileIn >> s.month;
    // fileIn.seekg(1, ios::cur);
    // fileIn >> s.year;
}

void readSubject(ifstream &fileIn, Subject &s)
{
    getline(fileIn, s.fullname, '-'); // đọc dữ liệu đến dấu '-'
    fileIn >> s.mark;
}

void importStudens(ifstream &fileIn, vector<Student> &students)
{
    // vòng lặp lặp đén cuối file thì dừng
    while (!fileIn.eof())
    {
        // * bước 1: đọc thông tin của 1 thằng sinh viên
        Student student;
        readStudent(fileIn, student);
        // * bước 2: đọc số lượng môn học sv đã học
        int n = 0; // số lượng môn học
        fileIn >> n;

        // có cái này để đọc kí tự '\n' của cái dòng bên trên
        string temp;
        getline(fileIn, temp);

        // * bước 3: đọc danh sách môn học
        for (int i = 0; i < n; i++)
        {
            Subject subject;
            readSubject(fileIn, subject);
            getline(fileIn, temp);
            student.subjects.push_back(subject); // thêm 1 môn học
        }

        // * bước 4: thêm thông tin sinh viên vào vector sinh viên
        students.push_back(student); // thêm 1 sv vào vector
    }
}

void outputOneStudent(Student s)
{
    cout << "\nHo ten: " << s.fullname << endl;
    cout << "Ma SV: " << s.code << endl;
    cout << "Nam sinh: " << s.yearOfBirth << endl;
    // cout << "Ngay sinh: " << s.date << "/" << s.month << "/" << s.year;
    // xuất danh sách các môn học
    for (int i = 0; i < s.subjects.size(); i++)
    {
        cout << "Ten mon hoc: " << s.subjects[i].fullname << endl;
        cout << "Diem: " << s.subjects[i].mark << endl;
    }
}

void outputStudents(vector<Student> s)
{
    for (int i = 0; i < s.size(); i++)
    {
        cout << "\n\n\t\tSINH VIEN THU " << i + 1 << endl;
        outputOneStudent(s[i]);
    }
}

void findStudentByFullname(vector<Student> s, string fullname)
{
    for (int i = 0; i < s.size(); i++)
    {
        if (stricmp(s[i].fullname.c_str(), fullname.c_str()) == 0) // hàm ko phân biệt kí tự hoa hay thường
        {
            cout << "\n\n\t\tSINH VIEN THU " << i + 1 << endl;
            outputOneStudent(s[i]);
        }
    }
}