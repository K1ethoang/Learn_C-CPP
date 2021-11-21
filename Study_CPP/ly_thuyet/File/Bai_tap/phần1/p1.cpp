// Bài 2. Đọc các số nguyên từ file INPUT.TXT biết
// + Chỉ có 1 dòng duy nhất chứa các số nguyên
// VD: INPUT.TXT
// 12 345 135 7 12 1
// === Yêu cầu ===
// Tìm các phần tử là số Amstrong trong mảng số nguyên đó và ghi vào file AMSTRONG.TXT.

#include <stdio.h>

int main()
{
    FILE *filein;
    filein = fopen("input.txt", "r");
    if (filein == NULL)
        printf("\nMo file bi loi!");
    else
        printf("\nMo file thanh cong :>");

    fclose(filein);
    return 0;
}