#include <stdio.h>

int fact(int n)
{
    if (n < 0)
        return 0;
    if (n == 0)
        return 1;
    else
        return fact(n - 1) * n;
}

int main(int argc, char const *argv[])
{
    int number;
    number = fact(4);
    printf("%d ", number);
    return 0;
}
