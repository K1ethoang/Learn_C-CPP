#include <iostream>
using namespace std;

void input_array(int n, int *a)
{
    for (int i = 0; i < n; i++)
    {
        cout << "\nNhap a[" << i << "]: ";
        cin >> *(a + i);
    }
}

void output_array(int n, int *a)
{
    for (int i = 0; i < n; i++)
    {
        cout << *(a + i) << " ";
    }
}

void add_one_element(int &n, int *a, int pos, int x)
{
    for (int i = n - 1; i >= pos; i--)
    {
        *(a + 1) = *a;
    }
    a[pos] = x;
    n++;
}

void delete_one_element(int &n, int *a, int pos)
{
    for (int i = pos + 1; i < n; i++)
    {
        *(a - 1) = *a;
    }
    n--;
}

void resize_array(int n, int *a, int x)
{
    int b[n];
    // * Chuyển các ptu cua mảng a qua mảng b
    for (int i = 0; i < n; i++)
    {
        b[i] = a[i];
    }

    // * Thay đổi kích thước mảng a
    a = new int[n + x];
    // * Chuyển các ptu của mảng b lại cho a
    for (int i = 0; i < n; i++)
    {
        a[i] = b[i];
    }
}

int main()
{

    int n;
    cout << "Nhap n phan tu: ";
    cin >> n;
    // * Cấp phát vùng nhớ cho con trỏ a <=> tạo mảng động
    int *a = new int[n];

    cout << "\n\n\tNHAP MANG\n";
    input_array(n, a);
    cout << "\n\n\tXUAT MANG\n";
    output_array(n, a);

    int pos, x;
    cout << "\nNhap vi tri can them: ";
    cin >> pos;
    cout << "\nNhap gia tri cna them: ";
    cin >> x;

    cout << "\n\n\tSAU KHI DUOC THEM\n";
    // resize_array(n, a, 1);
    add_one_element(n, a, pos, x);
    output_array(n, a);

    delete[] a;
    system("pause");
    return 0;
}