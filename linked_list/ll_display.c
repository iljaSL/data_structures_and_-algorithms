/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ll_display.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ismelich <ismelich@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/10 09:48:41 by ismelich          #+#    #+#             */
/*   Updated: 2020/06/10 09:51:16 by ismelich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

// The struct of the linked list

struct          Node 
{
    int data;
    struct Node *next;
}               *first = NULL;

// Creating the linked list

void            create(int A[], int n)
{
    int i;
    struct Node *tmp, *last;

    first = (struct Node *)malloc(sizeof(struct Node));
    first->data = A[0];
    first->next = NULL;
    last = first;

    for (i = 1; i < n; i++)
    {
        tmp = (struct Node *)malloc(sizeof(struct Node));
        tmp->data = A[i];
        tmp->next = NULL;
        last->next = tmp;
        last = tmp;
    }
}

// Display the linked list

void            display(struct Node *p)
{
    while (p != NULL)
    {
        printf("%d ", p->data);
        p = p->next;
    }
}

// Return the number of nodes in a linked list

int             count(struct Node *p)
{
    int cnt = 0;

    while (p)
    {
        cnt++;
        p = p->next;
    }
    return (cnt);
}

// Return recursively the number of nodes in a linked list

int             recursive_count(struct Node *p)
{
    if (p != NULL)
        return recursive_count(p->next) + 1;
    else
        return (0);
}

// Return the sum of a linked list.

int             sum(struct Node *p)
{
    int s = 0;

    while (p != NULL)
    {
        s += p->data;
        p = p->next;
    }
    return s;
}

// Return recursively the sum of a linked list.

int             recurisive_sum(struct Node *p)
{
    int s = 0;

    if (p != NULL)
        return recurisive_sum(p->next) + p->data;
    else
        return 0;
}

// Return the biggest number of a linked list

int             max(struct Node *p)
{
    int max = INT32_MIN;

    while (p)
    {
        if (p->data > max)
            max = p->data;
        p = p->next;
    }
    return max;
}

// Return recursively the biggest number in a linked list

int             rec_max(struct Node *p)
{
    int x = 0;

    if (p == NULL)
        return INT32_MIN;
    x = rec_max(p->next);
    if (x > p->data)
        return x;
    else 
        return p->data;
}

// Search a node in a linked list

struct Node*    search_node(struct Node *p, int key)
{
    struct Node *tail;

    while (p)
    {
        if (p->data == key)
        {
            tail->next = p->next;
            p->next = first;
            first = p;
            return p;
        }
        tail = p;
        p = p->next;
    }
    return NULL;
}

// Insert new Node in Linked List

void            insert(struct Node *p, int i, int value)
{
    struct Node *t;
    int         cnt;

    if (i < 0 || i > count(p))
        return;
    t = (struct Node *)malloc(sizeof(struct Node));
    t->data = value;

    if (i == 0)
    {
        t->next = first;
        first = t;
    }
    else
    {
        for (cnt = 0; cnt < i-1; cnt++)
            p = p->next;
        t->next = p->next;
        p->next = t;
    }
}

// Insert a new node in a sorted linked list

void            sorted_insert(struct Node *p, int value)
{
    struct Node *t;
    struct Node *tail = NULL;

    t = (struct Node *)malloc(sizeof(struct Node));
    t->data = value;
    t->next = NULL;

    if (first == NULL)
        first = t;
    else
    {
        while (p && p->data < value)
        {
            tail = p;
            p = p->next;
        }
        if (p == first)
        {
            t->next = first;
            first = t;
        }
        else
        {
            t->next = tail->next;
            tail->next = t;
        }
    }
}

// Deleting a node in a linked list

int             delete_node(struct Node *p, int index)
{
    struct Node *tail = NULL;
    int         x = -1;
    int         i;

    if (index < 1 || index > count(p))
        return -1;
    if (index == 1)
    {
        tail = first;
        x = first->data;
        free (tail);
        return x;
    }
    else
    {
        for (i = 0; i < index - 1; i++)
        {
            tail = p;
            p = p->next;
        }
    }
    tail->next = p->next;
    x = p->data;
    free (p);
    return x;
}

int              main()
{
    int A[] = {3, 5, 6, 7, 10, 15};
    struct Node *tmp;

    create(A, 6);
    // tmp = search_node(first, 15);
    // display(first);
    // printf("Length is: %d\n", count(first));
    // printf("Length is: %d\n", recursive_count(first));
    // printf("Sum is: %d\n", sum(first));
    // printf("Sum is: %d\n", recurisive_sum(first));
    // printf("Max is: %d\n", max(first));
    // printf("Max is: %d\n", rec_max(first));
    // if (tmp)
    //     printf("Key found: %d\n", tmp->data);
    // else
    //     printf("Key Not found\n");
    // insert(first, 1, 55);
    // sorted_insert(first, 4);
    delete_node(first, 2);
    display(first);


    return 0;
}