//Program to add of two polynomials of degree n, using linked list
#include <stdio.h>
#include <math.h>
#include <stdlib.h>

typedef struct list
{
    int degree;
    int exp1;
    int exp2;
    struct list *next;
} nodetype;

nodetype *insert(nodetype *L, int N, int e1, int e2)
{
    nodetype *p = NULL;
    while (N >= 0)
    {
        p = (nodetype *)malloc(sizeof(nodetype));
        p->degree = N;
        p->exp1 = e1;
        p->exp2 = e2;
        p->next = L;
        L = p;
        N--;
    }
    return L;
}

void add(nodetype *P1, nodetype *P2)
{
    int total = 0;
    while (P1 != NULL)
    {
        total += pow(P1->exp1, P1->degree) * pow(P1->exp2, P1->degree);
        P1 = P1->next;
    }
    while (P2 != NULL)
    {
        total += pow(P2->exp1, P2->degree) * pow(P2->exp2, P2->degree);
        P2 = P2->next;
    }
    printf("P3 = %d", total);
}

void main()
{
    nodetype *P1 = NULL, *P2 = NULL;
    int ch, N, e1, e2;
    do
    {
        printf("\nEnter 1 to insert in first polynomial\nEnter 2 to insert in second polynomial\nEnter 3 to add both polynomial\nEnter 4 for exit\n");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            printf("Enter degree: ");
            scanf("%d", &N);
            printf("Enter first exponent: ");
            scanf("%d", &e1);
            printf("Enter second exponent: ");
            scanf("%d", &e2);
            P1 = insert(P1, N, e1, e2);
            break;

        case 2:
            printf("Enter degree: ");
            scanf("%d", &N);
            printf("Enter first exponent: ");
            scanf("%d", &e1);
            printf("Enter second exponent: ");
            scanf("%d", &e2);
            P2 = insert(P2, N, e1, e2);
            break;

        case 3:
            add(P1, P2);
            break;
        }
    } while (ch <= 3);
}
