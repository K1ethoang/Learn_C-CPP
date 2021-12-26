#include <iostream>

int main(int argc, char *argv[])
{
    int sum = 0;
    for (int i = 1; i < argc; i++)
    {
        sum += atoi(argv[i]);
    }
    std::cout << sum;
    system("pause");
    return 0;
}
