#include <stdio.h>

double exponential(int x, int n)
{
    static double p = 1, f = 1;
    double r;

    if (n == 0)
        return 1;
    r = exponential(x, n - 1);
    p = p * x;
    f = f * n;
    return r + p / f;
}

int main()
{
    printf("%lf ", exponential(4, 15));
    return 0;
}
