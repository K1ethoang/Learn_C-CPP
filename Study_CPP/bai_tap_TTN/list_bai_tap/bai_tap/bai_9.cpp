//  ! BÀI 9: Giải bài tập mảng động - Xóa các SỐ NGUYÊN TỐ trong mảng 1 chiều

#include <iostream>
using namespace std;

void input_array(int *a, int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << "Enter A[" << i << "]: ";
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
        if (count == 10)
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
    // b1: bỏ tât cả phần tử mảng a qua mảng temp
    int *temp = new int[n];

    for (int i = 0; i < n; i++)
    {
        *(temp + i) = *(a + i);
    }

    // b2: khởi tạo lại 1 mảng mới với số lượng phần tử giảm đi 1
    //  giai phong di vung nho cu
    delete[] a;
    a = new int[n];
    // b3: Đổ các phần tử mảng temp vè cho mảng a
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
        if (check_prime_number(*(a + i)) == true)
        {
            del_one_element(a, n, i);
            i--; // giảm i 1 đơn vị - để tránh TH các số nguyên tố nằm gần nhau
        }
    }
}

int main()
{
    int n;
    cout << "\nEnter the required element of array: ";
    cin >> n;
    int *a = new int[n];

    input_array(a, n);
    cout << "\n\tImported elements\n\n";
    output_array(a, n);
    cout << "\n\tAfter delete elements are prime number\n";
    handle(a, n);
    output_array(a, n);
    delete[] a;
    system("pause");
    return 0;
}