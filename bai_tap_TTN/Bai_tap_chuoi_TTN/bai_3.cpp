#include <stdio.h>
#include <string.h>
#include <cmath>

//"123" = ('1' - 48) * 10^2 + ('2' - 48) * 10^1 + ('3' - 48) * 10^0
// <=> 1 * 10^2  + 2 * 10^1 + 3 * 10^0 = 123

// Ham chuyen chuoi so thanh so nguyen
int chuyen_doi(char s[])
{
    int sum = 0; // Chua ket qua cua so nguyen sau khi chuyen
    int mu = 0;  // Bien mu cua ct <=> 1 * 10^2  + 2 * 10^1 + 3 * 10^0 = 123
    // duyet tu cuoi chuoi ve dau chuoi
    for (int i = strlen(s) - 1; i >= 0; i--)
    {
        sum = sum + (s[i] - 48) * pow(10, mu);
        mu++; // Bien mua tang 1 don vi
    }
    return sum;
}

int main()
{
    char str[100];
    printf("Nhap chuoi so: ");
    fflush(stdin);
    gets(str);
    printf("\n\tChuoi so vua nhap:\n%s", str);

    printf("\n\tKet qua so nguyen sau khi chuyen doi:\n%d", chuyen_doi(str));

    return 0;
}