//Program to insert a node in a circular doubly link list, from left to right so that nodes of that circular doubly link list will be in ascending order.  
#include <stdio.h>
#include <stdlib.h>

typedef struct list
{
    struct list *prev;
    int info;
    struct list *next;
} nodetype;

void insert(nodetype **L, nodetype **R)
{
    int X;
    nodetype *p = NULL, *t = NULL;
    p = (nodetype *)malloc(sizeof(nodetype));
    if (p != NULL)
    {
        printf("Enter number:");
        scanf("%d", &X);
        p->info = X;
        if ((*L) == NULL && (*R) == NULL)
            (*L) = (*R) = p;
        else if (X < (*L)->info)
        {
            p->next = (*L);
            (*L)->prev = p;
            (*L) = p;
        }
        else if (X > (*R)->info)
        {
            p->prev = (*R);
            (*R)->next = p;
            (*R) = p;
        }
        else
        {
            t = (*L);
            while (X > t->next->info)
                t = t->next;
            p->next = t->next;
            p->prev = t;
            t->next->prev = p;
            t->next = p;
        }
        (*L)->prev = (*R);
        (*R)->next = (*L);
    }
}

void display(nodetype *L)
{
    nodetype *t = L;
    do
    {
        printf("%d\t", t->info);
        t = t->next;
    } while (t != L);
}

void main()
{
    int ch;
    nodetype *L = NULL, *R = NULL;
    do
    {
        printf("\nEnter 1 to insert\nEnter 2 to display\nEnter 3 for exit\n");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            insert(&L, &R);
            break;

        case 2:
            if (L == NULL)
                printf("Empty");
            else
                display(L);
            break;
        }
    } while (ch <= 2);
}
