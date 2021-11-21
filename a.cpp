#include <iostream>
using namespace std;

int main()
{
    int a, b, c, d;
    cout << "\nNhap a - b - c - d: ";
    cin >> a >> b >> c >> d;
    int max1 = a;
    if (max1 < b && b > c && c > d)
        max1 = b;
    else if (max1 < c && c > d && c > b)
        max1 = c;
    else if (max1 < d && d > b && d > c)
        max1 = d;

    int max2 = max1;
    if (max2 < a && a < max1)

        cout << max1;
    return 0;
}