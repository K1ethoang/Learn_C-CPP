// ! BÀI 12:  các phần tử là SỐ SIÊU NGUYÊN TỐ trong mảng 1 chiều số nguyên
#include <iostream>
using namespace std;

void input_array(int *a, int n);
void output_array(int *a, int n);
void del_one_element(int *&a, int &n, int del_pos);
bool check_prime_number(int n);
void handle(int *&a, int &n);

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
    cout << "\n\tAfter deleting super prime number in array\n";
    handle(a, n);
    output_array(a, n);

    delete[] a;
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

void del_one_element(int *&a, int &n, int del_pos)
{
    for (int i = del_pos + 1; i < n; i++)
    {
        *(a + i - 1) = *(a + i);
    }
    n--;
    // giảm kích thước mảng động
    int *temp = new int[n];
    for (int i = 0; i < n; i++)
    {
        *(temp + i) = *(a + i);
    }

    delete[] a;

    a = new int[n];
    for (int i = 0; i < n; i++)
    {
        *(a + i) = *(temp + i);
    }

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

void handle(int *&a, int &n)
{
    for (int i = 0; i < n; i++)
    {
        bool check = true;
        while (*(a + i) != 0) // check super prime number
        {
            if (check_prime_number(*(a + i)) == true)
                *(a + i) /= 10; // giảm đi 1 số phía bên phải
            else
            {
                check = false;
                break;
            }
        }
        if (check == true)
        {
            del_one_element(a, n, i);
            i--; // kiểm tra lại vị trí vừa xoá
        }
    }
}