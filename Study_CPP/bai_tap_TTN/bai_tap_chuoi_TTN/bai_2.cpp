#include <stdio.h>

int do_dai_chuoi(char s[])
{
    int i = 0;
    while (true)
    {
        if (s[i] == '\0')
        {
            return i;
        }
        i++;
    }
}

void xoa_1_ki_tu_bat_ki(char s[], int vi_tri_xoa)
{
    int n = do_dai_chuoi(s);
    for (int i = vi_tri_xoa + 1; i < n; i++)
    {
        s[i - 1] = s[i];
    }
    s[n - 1] = '\0';
}

void xoa_ki_tu_khoang_trang_dau_chuoi(char s[])
{
    while (true)
    {
        if (s[0] == ' ')
        {
            xoa_1_ki_tu_bat_ki(s, 0); // Xoa ki tu khoang trang tai vi tri i
        }
        else // <=> if(s[i] != ' ')
        {
            break;
        }
    }
}

void xoa_ki_tu_khoang_trang_cuoi_chuoi(char s[])
{
    while (true)
    {
        if (s[do_dai_chuoi(s) - 1] == ' ')
        {
            xoa_1_ki_tu_bat_ki(s, do_dai_chuoi(s) - 1);
        }
        else
        {
            break;
        }
    }
}

int main()
{
    char str[100];
    printf("Nhap chuoi:");
    fflush(stdin);
    gets(str);
    printf("Chuoi da nhap:%s.", str);
    printf("\nDo dai truoc khi xoa: %d", do_dai_chuoi(str));

    xoa_ki_tu_khoang_trang_dau_chuoi(str);
    printf("\n\nSau khi xoa khoang trang dau chuoi:\n%s.", str);
    printf("\nDo dai sau khi xoa dau chuoi: %d", do_dai_chuoi(str));
    xoa_ki_tu_khoang_trang_cuoi_chuoi(str);
    printf("\n\nSau khi xoa khoang trang cuoi chuoi:\n%s.", str);
    printf("\nDo dai sau khi xoa them cuoi chuoi: %d", do_dai_chuoi(str));

    return 0;
}