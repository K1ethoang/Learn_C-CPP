// ! BÀI 11 : Trộn 2 mảng A, B vào mảng C - đảm bảo tính tăng dần.KHÔNG DÙNG THUẬT TOÁN SẮP XẾP
// * Mảng a và b khi nhập vào là các phần tử đã tăng dần


#include <iostream>
#include <windows.h>
using namespace std;

void input_array(int *a, int n);
void output_array(int *a, int n);
void handle(int *a, int *b, int *c, int n, int m, int &k);
void loading();

int main()
{
    int n, m;
    cout << "\nEnter required element of array A: ";
    cin >> n;
    int *a = new int[n];

    cout << "\n\tEnter elements\n";
    input_array(a, n);
    cout << "\n\tImported elements of array A\n";
    output_array(a, n);

    cout << "\n\nEnter required element of array B: ";
    cin >> m;
    int *b = new int[m];

    cout << "\n\tEnter elements\n";
    input_array(b, m);
    cout << "\n\tImported elements of array B\n";
    output_array(b, m);

    int *c = new int[n + m];
    int k; // số lượng phần tử của mảng C

    loading();
    cout << "\n\tResult\n";
    handle(a, b, c, n, m, k);
    output_array(c, k);

    delete[] a;
    delete[] b;
    delete[] c;
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

void handle(int *a, int *b, int *c, int n, int m, int &k)
{
    int i = 0; // chỉ số của mảng a
    int j = 0; // chỉ số của mảng b
    k = 0;     // chỉ số của mảng c
    while ((i < n) && (j < m))
    {
        if (*(a + i) < *(b + j))
        {
            *(c + k) = *(a + i);
            k++;
            i++; // Chỉ số a tăng lên để tiếp tục so sánh với *(b+j)
        }
        else // *(a + i) >= *(b + j)
        {
            *(c + k) = *(b + j);
            k++;
            j++;
        }
    }
    // Duyệt vòng lặp mảng a để bỏ hết các phần tử còn lại
    for (; i < n; i++)
    {
        *(c + k) = *(a + i);
        k++;
    }

    // Duyệt vòng lặp mảng b để bỏ hết các phần tử còn lại
    for (; j < m; j++)
    {
        *(c + k) = *(b + j);
        k++;
    }
}

void loading()
{
    system("cls");
    for (int i = 10; i < 100; i += 20)
    {
        cout << "\nLoading " << i << "%";
        for (int j = 0; j < 5; j++)
        {
            cout << ".";
            Sleep(100);
        }
        Sleep(500);
        system("cls");
    }
    system("cls");
}