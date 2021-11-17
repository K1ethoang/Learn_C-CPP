#include <iostream>
using namespace std;

int main()
{

    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    int count = 0;
    cout << endl;
    for (int i = 0; i < n; i++)
    {
        count++;
        cout << a[i] << ' ';
        if (count == 10)
        {
            cout << endl;
            count = 0;
        }
    }
}