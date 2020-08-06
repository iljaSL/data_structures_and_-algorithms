/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   circular_linked_list.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ismelich <ismelich@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/05 15:18:18 by ismelich          #+#    #+#             */
/*   Updated: 2020/08/06 12:14:03 by ismelich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

struct  Node
{
    int         data;
    struct Node *next;
}       *Head;

void    create(int A[], int n)
{
    int         i;
    struct Node *t, *last;

    Head = (struct Node*)malloc(sizeof(struct Node));
    Head->data = A[0];
    Head->next = Head;
    last = Head;

    for (i = 1; i < n; i++)
    {
        t = (struct Node*)malloc(sizeof(struct Node));
        t->data = A[i];
        t->next = last->next;
        last->next = t;
        last = t;
    }
}

void    display(struct Node *h)
{
    do
    {
        printf("%d ", h->data);
        h = h->next;
    } while(h != Head);
    printf("\n");
}

void    recursive_display(struct Node *h)
{
    static int  flag = 0;

    if (h != Head || flag == 0)
    {
        flag = 1;
        printf("%d ", h->data);
        recursive_display(h->next);
    }
    flag = 0;
}

// Check the length of the linke list

int     length(struct Node *p)
{
    int len = 0;

    do
    {
        len++;
        p =p->next;
    } while (p != Head);
    return len;
}

// Insert Node in a circular linked list

void    insert(struct Node *h, int index, int x)
{
    struct Node *t;
    int         i;

    if (index < 0 || index > length(h))
        return;
    if (index == 0)
    {
        t = (struct Node *)malloc(sizeof(struct Node));
        t->data = x;
        if (Head == NULL)
        {
            Head = t;
            Head->next = Head;
        }
        else
        {
            while (h->next != Head)
                h = h->next;
            h->next = t;
            t->next = Head;
            Head = t;
        }
    }
    else
    {
        for (i = 0; i < index - 1; i++)
            h = h->next;
        t = (struct Node *)malloc(sizeof(struct Node));
        t->data = x;
        t->next = h->next;
        h->next = t;
    }
}

int     main()
{
    int A[] = {2, 3, 4, 5, 6};
    create(A, 5);

    // display(Head);
    insert(Head, 2, 10);
    recursive_display(Head);
    return 0;
}