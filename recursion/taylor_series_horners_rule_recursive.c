#include <stdio.h>

double exponential(int x, int n)
{
    static double s;

    if (n == 0)
        return s;
    s = 1 + x * s / n;
    return exponential(x, n - 1);
}

int main()
{
    printf("%lf ", exponential(2, 10));
    return 0;
}