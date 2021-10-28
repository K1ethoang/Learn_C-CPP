#include <bits/stdc++.h>
using namespace std;

int main()
{
    system("cls") int a, b, c;
    cin >> a >> b >> c;
    if (a > 31 || b > 12)
    {
        cout << "0";
    }
    else if (b == 2 && a > 28)
    {
        if (c % 400 == 0 || (c % 4 == 0 && c % 100 != 0))
        {
            cout << "0";
        }
        else
        {
            cout << "0";
        }
    }
    else if (c < 1995 || c > 2012)
    {
        cout << "0";
    }

    return 0;
}