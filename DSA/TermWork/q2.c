//Program to Insert and Delete elements form a Queue using link list
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Que
{
    char Product_id;
    char Product_Name[30];
    int Total_Sale;
    char Product_Grade;
    struct Que *next;
} Que;

Que *Enq(Que *R)
{
    Que *p = NULL;
    int W;
    char X, Y;
    char Z[30];
    p = (Que *)malloc(sizeof(Que));
    if (p == NULL)
        printf("Not enough memory");
    else
    {
        printf("Enter Product Id:");
        scanf(" %c", &X);
        printf("Enter Product Name: ");
        scanf("%s", &Z);
        printf("Enter Total Sale: ");
        scanf("%d", &W);
        printf("Enter Product Grade: ");
        scanf(" %c", &Y);
        p->Product_id = X;
        strcpy(p->Product_Name, Z);
        p->Total_Sale = W;
        p->Product_Grade = Y;
        if (R == NULL)
            R = p;
        else
        {
            R->next = p;
            R = p;
        }
        R->next = NULL;
    }
    return R;
}

Que *Deq(Que *F)
{
    Que *p = NULL;
    p = F;
    printf("\nProduct Id: %c\n", F->Product_id);
    printf("Product Name: %s\n", F->Product_Name);
    printf("Total Sale: %d\n", F->Total_Sale);
    printf("Product Grade: %c\n", F->Product_Grade);
    F = F->next;
    free(p);
    return F;
}

void display(Que *F)
{
    while (F != NULL)
    {
        printf("\nProduct Id: %c\n", F->Product_id);
        printf("Product Name: %s\n", F->Product_Name);
        printf("Total Sale: %d\n", F->Total_Sale);
        printf("Product Grade: %c\n", F->Product_Grade);
        F = F->next;
    }
}

void main()
{
    Que *F = NULL, *R = NULL;
    int ch;
    do
    {
        printf("\nEnter 1 to insert\nEnter 2 to delete\nEnter 3 for display\nEnter 4 for exit\n");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            R = Enq(R);
            if (F == NULL)
                F = R;
            break;

        case 2:
            if (F == NULL)
                printf("Empty Que");
            else
            {
                F = Deq(F);
                if (F == NULL)
                    R = NULL;
            }
            break;

        case 3:
            if (F == NULL)
                printf("Empty Que");
            else
                display(F);
            break;
        }

    } while (ch <= 3);
}
