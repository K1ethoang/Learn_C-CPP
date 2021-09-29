// ! Nhập vào 1 chuỗi các kí tự in thường từ bàn phím. Bỏ hết tất cả các kí tự x
// ! (x là 1 kí tự in thường nhập từ bàn phím) dó vào chuỗi temp.
// ! Chú ý: không được dùng hàm có sẵn

#include <stdio.h>
#include <string.h>

void xu_ly(char s[], char temp[], char x)
{
    /*
    /// * Duyet tu dau chuoi den cuoi chuoi str - neu ki tu x ma trung voi ki tu nao cua chuoi str
    /// * thi bo ki tu cua chuoi str vao chuoi temp 
    */
    int count = 0;
    for (int i = 0; i < strlen(s); i++)
    {
        if (s[i] == x)
        {
            temp[count] = s[i];
            count++;
        }
    }
    temp[count] = '\0'; // Phai co ki tu ket thuc chuoi - Neu ko se bi loi
}

int main()
{
    char str[100];
    printf("\nNhap chuoi S: ");
    fflush(stdin);
    gets(str);
    printf("\nChuoi str nhan duoc la: %s", str);

    char x;
    printf("\nNhap ki tu x: ");
    scanf("%c", &x); // Nhap ki tu vao ban phim

    char temp[100];
    xu_ly(str, temp, x);
    printf("\n\nChuoi temp nhan duoc la: %s", temp);

    return 0;
}