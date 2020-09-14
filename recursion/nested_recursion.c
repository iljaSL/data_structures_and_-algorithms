#include <stdio.h>

int nested_recursion(int n)
{
    if (n > 100)
        return n - 10;
    return nested_recursion(nested_recursion(n + 11));
}

int main()
{
    int number;

    number = nested_recursion(200);
    printf("%d ", number);
    return 0;
}
