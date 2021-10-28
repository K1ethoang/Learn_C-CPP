#include <bits/stdc++.h>
using namespace std;

struct sinh_vien
{
    string ma_sinh_vien;
    float diem;
};

void xu_ly(sinh_vien sv[], int n, int m)
{
    for (int i = 0; i < n; i++)
    {
        if (m == 0)
        {
            return;
        }
        else if (sv[i].diem > sv[i + 1].diem)
        {
            cout << sv[i].ma_sinh_vien << " ";
            m--;
        }
    }
}

int main()
{
    sinh_vien sv[1000];
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        fflush(stdin);
        getline(cin, sv[i].ma_sinh_vien);
        cin >> sv[i].diem;
    }
    int m;
    cin >> m;

    // sap xep
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = i; j < n; j++)
        {
            if (sv[i].diem <= sv[j].diem)
            {
                swap(sv[i], sv[j]);
            }
        }
    }

    for (int i = 0; i < n; i++)
    {
        cout << sv[i].diem << " ";
    }

    return 0;
}