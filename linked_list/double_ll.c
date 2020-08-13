#include <stdio.h>
#include <stdlib.h>

struct  Node
{
    struct Node *prev;
    struct Node *next;
    int         data;
}       *first = NULL;

void    create(int A[], int n)
{
    struct Node *t, *last;
    int         i;

    first = (struct Node *)malloc(sizeof(struct Node));
    first->data = A[0];
    first->prev = first->next = NULL;
    last = first;

    for (i = 1; i < n; i++)
    {
        t = (struct Node *)malloc(sizeof(struct Node));
        t->data = A[i];
        t->next = last->next;
        t->prev = last;
        last->next = t;
        last = t;
    }
}

void    display(struct Node *p)
{
    while (p)
    {
        printf("%d ", p->data);
        p = p->next;
    }
    printf("\n");
}

int     length(struct Node *p)
{
    int len = 0;

    while (p)
    {
        len++;
        p = p->next;
    }
    return len;
}

void    insert(struct Node *p, int index, int x)
{
    struct Node *t;
    int         i;

    if (index < 0 || index > length(p))
        return;
    if (index == 0)
    {
        t = (struct Node *)malloc(sizeof(struct Node));
        t->data = x;
        t->prev = NULL;
        t->next = first;
        first->prev = t;
        first = t;
    }
    else
    {
        for (i = 0; i < index - 1; i++)
            p = p->next;
        t = (struct Node *)malloc(sizeof(struct Node));
        t->data = x;
        t->prev = p;
        t->next = p->next;
        if (p->next)
            p->next->prev = t;
        p->next = t;
    }
}

int    delete(struct Node *p, int index)
{
    struct Node *q;
    int         x = -1, i;

    if (index < 1 || index > length(p))
        return -1;
    if (index == 1)
    {
        first = first->next;
        if (first)
            first->prev = NULL;
        x = p->data;
        free(p);
    }
    else
    {
        for (i = 0; i < index - 1; i++)
            p = p->next;
        p->prev->next = p->next;
        if (p->next)
            p->next->prev = p->prev;
        x = p->data;
        free(p);
    }
    return x;
}

void    reverse(struct Node *p)
{
    struct Node *tmp;

    while (p != NULL)
    {
        tmp = p->next;
        p->next = p->prev;
        p->prev = tmp;
        p = p->prev;
        if (p != NULL && p->next == NULL)
            first = p;
    }
}

int     main()
{
    int A[] = {10, 20, 30, 40, 50};

    create(A, 5);
    // printf("The length is: %d\n", length(first));
    // insert(first, 2, 90);
    // delete(first, 3);
    reverse(first);
    display(first);
    return (0);
}