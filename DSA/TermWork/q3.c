//Program to find union (of two linked lists) based on their information field that implements singly linked list.
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct list
{
    char Emp_Id;
    char Emp_Name[20];
    struct list *next;
} nodetype;

nodetype *insert(nodetype *L)
{
    nodetype *p = NULL;
    char X, Y[30];
    p = (nodetype *)malloc(sizeof(nodetype));
    if (p != NULL)
    {
        printf("Enter employee Id: ");
        scanf(" %c", &X);
        printf("Enter emplyee name: ");
        scanf("%s", &Y);
        p->Emp_Id = X;
        strcpy(p->Emp_Name, Y);
        p->next = L;
        L = p;
    }
    return L;
}

int isPresent(nodetype *L1, nodetype *L2)
{
    while (L1 != NULL)
    {
        if (L1->Emp_Id == L2->Emp_Id)
            return 0;
        L1 = L1->next;
    }
    return 1;
}

void unionNodes(nodetype *L1, nodetype *L2)
{
    nodetype *t = L1;
    while (t != NULL)
    {
        printf("Employee Id: %c\n", t->Emp_Id);
        printf("Employee Name: %s\n\n", t->Emp_Name);
        t = t->next;
    }
    while (L2 != NULL)
    {
        if (isPresent(L1, L2))
        {
            printf("Employee Id: %c\n", L2->Emp_Id);
            printf("Employee Name: %s\n\n", L2->Emp_Name);
        }
        L2 = L2->next;
    }
}

void main()
{
    nodetype *L1 = NULL, *L2 = NULL;
    int ch;
    do
    {
        printf("\nEnter 1 to insert in first list\nEnter 2 to insert in second list\nEnter 3 to display union\nEnter 4 for exit\n");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            L1 = insert(L1);
            break;

        case 2:
            L2 = insert(L2);
            break;

        case 3:
            if (L1 == NULL || L2 == NULL)
                printf("One list is empty!!");
            else
                unionNodes(L1, L2);
            break;
        }
    } while (ch <= 3);
}
