#include <iostream>

void nhap(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        std::cin >> arr[i];
    }
}

void xuat(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        std::cout << arr[i] << " ";
    }
}

void sap_xep(int arr[], int n)
{
    int temp;
    int step = 1;
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (arr[i] > arr[j])
            {
                temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
        std::cout << "Step " << step << ": ";
        xuat(arr, n);
        std::cout << std::endl;
        step++;
    }
}

int main()
{
    int n;
    std::cin >> n;
    int arr[n];
    if (n <= 200)
    {
        nhap(arr, n);
        sap_xep(arr, n);
    }

    return 0;
}