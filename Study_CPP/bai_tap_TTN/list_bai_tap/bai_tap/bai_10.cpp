// ! BÀI 10: thêm giá trị x vào sau phần tử là SỐ NGUYÊN TỐ trong mảng 1 chiều động ;>
#include <iostream>
#include <windows.h>
using namespace std;

void input_array(int *a, int n);
void output_array(int *a, int n);
void add_one_element(int *&a, int &n, int add_pos, int x);
bool check_prime_number(int n);
void handle(int *&a, int &n, int x);
void loading();

int main()
{
    int n, x;
    cout << "\nEnter required element of array: ";
    cin >> n;
    int *a = new int[n];

    cout << "\n\tEnter elements\n";
    input_array(a, n);
    cout << "\n\tImported elements\n";
    output_array(a, n);
    cout << "\nEnter number need to add after prime number: ";
    cin >> x;

    loading();
    cout << "\n\tResult\n";
    handle(a, n, x);
    output_array(a, n);

    delete[] a;
    system("pause");
    return 0;
}

void input_array(int *a, int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << "\nEnter a[" << i << "]: ";
        cin >> *(a + i);
    }
}

void output_array(int *a, int n)
{
    int count = 0;
    for (int i = 0; i < n; i++)
    {
        count++;
        cout << *(a + i) << ' ';
        if (count == 0)
        {
            cout << endl;
            count = 0;
        }
    }
}

void add_one_element(int *&a, int &n, int add_pos, int x)
{
    // tăng mảng trước rồi mới thêm
    int *temp = new int[n];
    for (int i = 0; i < n; i++)
    {
        *(temp + i) = *(a + i); // đổ các phần tử mảng a qua cho mảng temp
    }

    delete[] a;
    a = new int[n + 1];
    for (int i = 0; i < n; i++)
    {
        *(a + i) = *(temp + i);
    }

    // Thêm 1 phần tử vào mang a
    for (int i = n - 1; i >= add_pos; i--)
    {
        *(a + i + 1) = *(a + i);
    }
    *(a + add_pos) = x;
    n++;

    delete[] temp;
}

bool check_prime_number(int n)
{
    if (n < 2)
        return false;
    else
    {
        if (n == 2)
            return true;
        else if (n % 2 == 0)
            return false;
        for (int i = 2; i < n - 1; i++)
        {
            if (n % i == 0)
                return false;
        }
    }
    return true;
}

void handle(int *&a, int &n, int x)
{
    for (int i = 0; i < n; i++)
    {
        if (check_prime_number(*(a + i)) == true)
        {
            add_one_element(a, n, i + 1, x);
            i++; // tăng giá trị i lên 1 đơn vị để bỏ qua vị trí x (nhập từ bàn phím) mà kiểm tra SNT
        }
    }
}

void loading()
{
    system("cls");
    for (int i = 10; i <= 100; i += 10)
    {
        cout << "\nLoading " << i << "%"
             << "....";
        Sleep(500);
    }
    system("cls");
}