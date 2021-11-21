// ! BÀI 13: tìm SỐ HOÀN THIỆN nhỏ nhất trong mảng 1 chiều số nguyên
#include <iostream>
#include <algorithm>
using namespace std;

void input_array(int *a, int n);
void output_array(int *a, int n);
bool check_perfect_number(int n);
void handle(int *a, int n);

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

    handle(a, n);

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

bool check_perfect_number(int n)
{
    int sum = 0;
    for (int i = 1; i <= (n / 2); i++)
    {
        if (n % i == 0)
            sum += i;
    }
    if (sum == n) // tạm thời code vậy -> khá là chậm
        return true;
    else
        return false;
}

void handle(int *a, int n)
{
    int min = 0; // nếu biến min thay đổi thì trong mảng có phần tử là số hoàn thiện mà bé nhất
    for (int i = 0; i < n; i++)
    {
        if (check_perfect_number(*(a + i)) == true)
        {
            min = *(a + i);
            for (int j = i + 1; j < n; j++)
            {
                if ((check_perfect_number(*(a + j)) == true))
                {
                    if (min > *(a + j))
                        min = *(a + j);
                }
            }
            break;
        }
    }
    if (min != 0)
        cout << "\n\nThe smallest perfect number is: " << min;
    else
        cout << "\n\nThere is no perfect number in array";
}