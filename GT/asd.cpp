#include <iostream>
#include <string>

// void chuyen_ve_dang_chuan(std::string &s)
// {
//     for (int i = 0; i < s.length(); i++)
//     {
//         if (s[i] == ' ' && s[i + 1] == ' ')
//         {
//             s.erase(s.begin() + (i + 1));
//             i--;
//         }
//     }
// }

void xu_ly(std::string s)
{
    int dem = 0;
    for (int i = 0; i < s.length(); i++)
    {
        if (s[i] == ' ' && s[i + 1] != ' ')
        {
            dem++;
        }
    }
    std::cout << dem << std::endl;
}

int main()
{
    int n = 0;
    std::cin >> n;
    while (n--)
    {
        std::string s;
        std::getline(std::cin, s);
        std::cin.ignore();

        xu_ly(s);
    }

    return 0;
}