#include <stdio.h>

void fun_b(int n);

void fun_a(int n)
{
    if (n > 0)
    {
        printf("%d ", n);
        fun_b(n - 1);
    }
}

void fun_b(int n)
{
    if (n > 1)
    {
        printf("%d ", n);
        fun_a(n / 2);
    }
}

int main()
{
    fun_a(100);
    return 0;
}
