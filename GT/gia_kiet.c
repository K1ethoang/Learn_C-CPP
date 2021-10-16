#include <stdio.h>
#include <math.h>

int main()
{
    float a, b, c;
    float x1, x2;
    printf("Nhap a, b, c: ");
    scanf("%f%f%f", &a, &b, &c);
    int delta;
    delta = b * b - 4 * a * c;

    if (a == 0) //giai phuong trinh bac nhat bx + c = 0
    {
        if (b == 0)
        {
            if (c == 0)
            {
                printf("Vo so nghiem");
            }
            else
            {
                printf("Vo nghiem");
            }
        }
        else if (b > 0)
        {
            printf("%.2f", -c / b);
        }
        else if (b < 0)
        {
            if (c == 0)
            {
                b = abs(b);
                printf("%.2f", -c / b);
            }
            else if (c != 0)
            {
                printf("%.2f", -c / b);
            }
        }
    }
    else // a != 0 => Giai pt ax2 + bx + c = 0
    {
        if (delta > 0)
        {
            x1 = ((-b - sqrt(delta)) / (2 * a));
            x2 = ((-b + sqrt(delta)) / (2 * a));
            printf("%.2f\n%.2f", x1, x2);
        }
        else if (delta < 0)
        {
            printf("Vo nghiem");
        }
        else
        {
            printf("%.2f", -b / (2 * a));
        }
    }

    return 0;
}