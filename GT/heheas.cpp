#include <iostream>
#include <cmath>

int convert_to_binary(char c)
{
    int exp = 0;
    int sum = 0;
    while (c != 0)
    {
        sum += ((int)(c) % 2) * pow(10, exp);
        c /= 2;
        ++exp;
    }
    return sum;
}

// void xuat_nhi_phan(int n)
// {
//     int arr[8];
//     for (int i = 7; i >= 0; i--)
//     {
//         arr[i] = n % 10;
//         n /= 10;
//     }
//     for (int i = 0; i < 8; i++)
//     {

//         std::cout << arr[i];
//     }
//     std::cout << " ";
// }

int main()
{

    short n;
    std::cin >> n;

    short j = 0;
    if (n < 20)
    {
        while (j < n)
        {
            std::string s;
            fflush(stdin);
            std::getline(std::cin, s);
            for (int i = 0; i < s.length(); i++)
            {
                xuat_nhi_phan(convert_to_binary(s[i]));
            }
            std::cout << std::endl;
            j++;
        }
    }

    return 0;
}