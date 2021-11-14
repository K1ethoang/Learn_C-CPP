#include <bits/stdc++.h>
using namespace std;

int main()
{
    int M, N, k;
    cin >> M >> N >> k;
    if (M && N >= 0 && M && N <= 100 && (k >= 0 && k <= M + N))
    {
        int result = 0, temp;
        for (int i = 0; i <= k; i++)
        {
            // tìm số cách có thể chia k người
            int nu = M, nam = N;
            int count = 0;
            for (int j = 0; j <= k; j++)
            {
                if (i + j == k)
                {
                    nu -= i;
                    nam -= j;
                    // Chia đội
                    while (nu >= 2 && nam >= 1)
                    {
                        nu -= 2;
                        nam -= 1;
                        count++;
                    }
                    temp = count;
                    break;
                }
            }
            if (temp >= result)
            {
                result = temp;
            }
        }
        cout << result;
    }
    return 0;
}