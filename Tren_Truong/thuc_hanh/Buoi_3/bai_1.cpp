// Ho Ten: Hoang Gia Kiet
// MSSV: 6251071049
// Lop: IT-62

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// y1
// nhập mảng
void inputArray(int a[], int n);
// y2
// xuất mảng
void outputArray(int a[], int n);
// y3
// tìm phần tử lớn nhất và nhỏ nhất
void findMaxAndMinElements(int a[], int n);
// y4
// tìm và in ra vị trí phần tử dương nhỏ nhất
void findPostionOfMinPositiveElement(int a[], int n);
// y5
// tổng của mảng
int sumOfArray(int a[], int n);
// y6
// trung bình cộng và trung bình nhân
void averageAndMultiplyAverage(int a[], int n);
// y7
// tìm 1 phần tử (x nhập từ bàn phím)
void findXElement(int a[], int n);
// y8
// hoán vị
void swap(int &a, int &b);
// sắp xếp tăng dần và giảm dần
void sortAscendingAndDescending(int a[], int n);
// y9
// xuất dãy đảo ngược của dãy ban đầu
void outputReverseArray(int a[], int n);
// y10
// thêm 1 phần tử x vào vị trí k (x,k nhập từ bàn phím)
void addOneElement(int a[], int &n, int x, int k);
// y11
// xoá 1 phần tử ở vị trí k (k nhập từ bàn phím)
void deleteOneElement(int a[], int &n, int k);
// y12
// đếm số phần tử dương và in ra tổng các phần tử dương
void countPositiveElementsAndOuputSum(int a[], int n);
// y13
// kiểm tra mảng có đối xứng hay không
bool checkPalindromicArray(int a[], int n);
// y14
// kiểm tra mảng có sắp thứ tự tăng hay không
bool checkAscendingArray(int a[], int n);
// y15
// kiểm tra 1 số nguyên tố
bool checkPrimeNumber(int n);
// đếm số nguyên tố trong mảng
int countPrimeNumberInArray(int a[], int n);
// y16
// đếm số cặp có số sau = tổng 2 số trước
int countNextNumberEqualSumOfTwoPreviousNumber(int a[], int n);
// y17
// đếm có bao nhiêu cặp ai + aj (i!=j) là số nguyên tố
int countElementIAddElementJIsPrimeNumber(int a[], int n);

void menu();
void pressAnyKey();

int main()
{
    menu();
    return 0;
}

void menu()
{
    short choose;
    int n, a[100];
    bool exit = false, isInputArray = true;
    do
    {
        printf("----------------------------- MENU -----------------------------");
        printf("\n  1. Nhap mang");
        printf("\n  2. Xuat mang");
        printf("\n  0. Thoat chuong trinh");
        printf("\n---------------------------- <3<3<3 ----------------------------");

        printf("\n  Nhap lua chon: ");
        scanf("%d", &choose);

        switch (choose)
        {
        case 0:
            exit = true;
            printf("\n\tBan da chon thoat chuong trinh");
            pressAnyKey();
            break;
        case 1:

            isInputArray = true;
            do
            {
                printf("\nNhap n (0 < n <= 100): ");
                scanf("%d", &n);
                if (n < 1 || n > 100)
                {
                    printf("\n\t\t(!) NHAP LAI (!)");
                    pressAnyKey();
                }
            } while (n < 1 || n > 100);
            inputArray(a, n);
            break;
        case 2:
            outputArray(a, n);
            pressAnyKey();
            break;
        default:
            break;
        }
    } while (!exit);
}

void pressAnyKey()
{
    printf("\n\n");
    system("pause");
    printf("\n");
}

// y1
void inputArray(int a[], int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("\nNhap a[%d]: ", i + 1);
        scanf("%d", &a[i]);
    }
}

// y2
void outputArray(int a[], int n)
{
    int count = 0;
    for (int i = 0; i < n; i++)
    {
        count++;
        printf("%d ", a[i]);
        if (count == 10)
        {
            printf("\n");
            count = 0;
        }
    }
}

// y3
void findMaxAndMinElements(int a[], int n)
{
    int maxElement = a[0], minElement = a[0];
    for (int i = 0; i < n; i++)
    {
        if (maxElement < a[i])
            maxElement = a[i];
        if (minElement > a[i])
            minElement = a[i];
    }

    printf("\nPhan tu lon nhat: %d", maxElement);
    printf("\nPhan tu nho nhat: %d", minElement);
}

// y4
void findPostionOfMinPositiveElement(int a[], int n)
{
    int minElement = a[0], minIndex = 0;
    bool hasMinElement = false;
    for (int i = 0; i < n; i++)
    {
        if (a[i] > 0)
        {
            hasMinElement = true; // có phần tử dương
            minIndex = i;
            minElement = a[minElement];
            for (int j = minIndex; j < n; j++)
            {
                if (minElement > a[j])
                {
                    minElement = a[j];
                    minIndex = j;
                }
            }
            break;
        }
    }

    if (hasMinElement)
        printf("\nVi tri phan tu duong nho nhat: %d", minIndex);
    else
        printf("\nKhong co phan tu duong nho nhat");
}

// 5
int sumOfArray(int a[], int n)
{
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        sum += a[i];
    }
    return sum;
}

// y6
void averageAndMultiplyAverage(int a[], int n)
{
    int sumAverage = 0, sumMultiplyAverage = 1;
    for (int i = 0; i < n; i++)
    {
        sumAverage += a[i];
        sumMultiplyAverage *= a[i];
    }

    printf("\nTrung binh cong: %.2f", sumAverage * 1.0 / n);
    printf("\nTrung binh nhan: %.2f", pow(sumMultiplyAverage, (1.0 / n)));
}

// y7
void findXElement(int a[], int n)
{
    bool hasXElement = false;
    int x;
    printf("\nNhap phan tu x can tim kiem: ");
    scanf("%d", &x);
    for (int i = 0; i < n; i++)
    {
        if (a[i] == x)
        {
            hasXElement = true;
            break;
        }
    }

    if (hasXElement)
        printf("\nCo phan tu x trong mang");
    else
        printf("\nKhong co phan tu x trong mang");
}

// y8
void swap(int &a, int &b)
{
    int temp = a;
    a = b;
    b = temp;
}

void sortAscendingAndDescending(int a[], int n)
{
    // tang dan -> selection sort
    for (int i = 0; i < n - 1; i++)
    {
        int minIndex = i;
        for (int j = i; j < n; j++)
        {
            if (a[j] < a[minIndex])
                minIndex = j;
        }
        if (minIndex != i)
            swap(a[i], a[minIndex]);
    }

    // giam dan -> bubble sort
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (a[j] < a[j + 1])
                swap(a[j], a[j + 1]);
        }
    }
}

// y9
void outputReverseArray(int a[], int n)
{
    int count = 0;
    for (int i = n - 1; i >= 0; i--)
    {
        count++;
        printf("%d ", a[i]);
        if (count == 10)
        {
            printf("\n");
            count = 0;
        }
    }
}

// y10
void addOneElement(int a[], int &n, int x, int k)
{
    for (int i = n; i >= k - 1; i--)
    {
        a[i] = a[i - 1]; // giá trị sau = giá trị trước
    }
    a[k - 1] = x;
    n++;
}

// y11
void deleteOneElement(int a[], int &n, int k)
{
    for (int i = k - 1; i < n - 1; i++)
    {
        a[i] = a[i + 1];
    }
    n--;
}

// y12
void countPositiveElementsAndOuputSum(int a[], int n)
{
    int count = 0, sum = 0;
    for (int i = 0; i < n; i++)
    {
        if (a[i] > 0)
        {
            count++;
            sum += a[i];
        }
    }

    if (count != 0)
    {
        printf("\nSo cac phan tu duong: %d", count);
        printf("\nTong cac phan tu duong: %d", sum);
    }
    else
        printf("\nKhong co phan tu nao duong");
}

// y13
bool checkPalindromicArray(int a[], int n)
{
    // mảng đối xứng
    // n = 5 -> 12321 là đối xứng
    // n = 6 -> 123321 là đối xứng
    if (n % 2 != 0)
    {
        // duyệt [0, (n - 1) / 2)
        // vd: n = 5 -> [0, 1];
        for (int i = 0; i < (n - 1) / 2; i++)
        {
            if (a[i] != a[n - 1 - i])
                return false;
        }
    }
    else
    {
        // duyệt [0, n / 2)
        // vd: n = 6 -> [0, 2];
        for (int i = 0; i < n / 2; i++)
        {
            if (a[i] != a[n - 1 - i]) // so sánh phần tử đầu và cuối
                return false;
        }
    }
    return true;
}

bool checkAscendingArray(int a[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        if (a[i] > a[i + 1])
            return false;
    }
    return true;
}

// y15
bool checkPrimeNumber(int n)
{
    if (n < 2)
        return false;
    else
    {
        if (n == 2)
            return true;
        else
        {
            for (int i = 2; i <= sqrt(n); i++)
            {
                if (n % i == 0)
                    return false;
            }
        }
    }
    return true;
}

int countPrimeNumberInArray(int a[], int n)
{
    int count = 0;
    for (int i = 0; i < n; i++)
    {
        if (checkPrimeNumber(a[i]) == true)
            count++;
    }
    return count;
}

// y16
int countNextNumberEqualSumOfTwoPreviousNumber(int a[], int n)
{
    int count = 0;
    // bắt đầu duyệt từ phần tử thứ 3
    for (int i = 2; i < n; i++)
    {
        if (a[i] == (a[i - 1] + a[i - 2]))
            count++;
    }
    return count;
}

// y17
int countElementIAddElementJIsPrimeNumber(int a[], int n)
{
    int count = 0;
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (checkPrimeNumber(a[i] + a[j]) == true)
                count++;
        }
    }
    return count;
}
