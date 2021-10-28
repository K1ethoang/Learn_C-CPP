#include <bits/stdc++.h>
using namespace std;

void output(int ngay, int thang, int nam)
{
    // kiem tra de in so ngay

    if (ngay / 10 != 0 && thang / 10 != 0)
    {
        cout << ngay << "/" << thang << "/" << nam;
    }
    else
    {
        if (ngay / 10 == 0 && thang / 10 == 0)
        {
            cout << "0" << ngay << "/0" << thang << "/" << nam;
        }
        else if (thang / 10 == 0)
        {
            cout << ngay << "/0" << thang << "/" << nam;
        }
        else
        {
            cout << "0" << ngay << "/" << thang << "/" << nam;
        }
    }
}

void xu_ly(int &ngay, int &thang, int &nam)
{
kiem_tra:
    switch (thang)
    {
    case 1:
    case 3:
    case 5:
    case 7:
    case 8:
    case 10:
    case 12:
        while (ngay > 31)
        {
            ngay -= 31;
            thang++;

            while (thang > 12)
            {
                thang -= 12;
                nam++;
            }
            goto kiem_tra;
        }

        // IN NGAY
        output(ngay, thang, nam);
        break;
    case 4:
    case 6:
    case 9:
    case 11:
        while (ngay > 30)
        {
            ngay -= 30;
            thang++;
            goto kiem_tra;
        }
        // IN NGAY
        output(ngay, thang, nam);

        break;
    case 2:
        if (nam % 400 == 0 || (nam % 4 == 0 && nam % 100 != 0))
        {
            while (ngay > 29)
            {
                ngay -= 29;
                thang++;
                goto kiem_tra;
            }
            // IN NGAY
            output(ngay, thang, nam);
        }

        else
        {
            while (ngay > 28)
            {
                ngay -= 28;
                thang++;

                goto kiem_tra;
            }
            // IN NGAY
            output(ngay, thang, nam);
        }
        break;
    }
}
int main()
{
    int ngay, thang, nam;
    cin >> ngay >> thang >> nam;
    int m;
    cin >> m;

    // Kiem tra dau vao
    if ((ngay < 1 || ngay > 31) || (thang < 1 || thang > 12) || (nam < 1995 || nam > 2012))
    {
        cout << "0";
    }
    else if (thang == 2 && ngay > 28)
    {
        if (nam % 400 == 0 || (nam % 4 == 0 && nam % 100 != 0))
        {
            if (ngay > 29)
            {
                cout << "0";
            }
            else
            {
                ngay += m;
                xu_ly(ngay, thang, nam);
            }
        }
        else
        {
            cout << "0";
        }
    }
    else
    {
        ngay += m;
        xu_ly(ngay, thang, nam);
    }

    return 0;
}
