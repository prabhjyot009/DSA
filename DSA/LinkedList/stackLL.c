#include<stdio.h>
#include<stdlib.h>

typedef struct stack
{
    int info;
    struct stack *next;
}stack;
stack *push(stack *);
stack *pop(stack *);
void display(stack *);

void main()
{
    stack *push(stack *top)
    {
        stack *p=NULL:
        int x;
        p=(stack*)malloc(sizeof(stack));
        if(p==NULL)
        printf("\nnot enough memory!!");
        scanf("%d",&x);
        p->info=x;
        p->next=top;
        top=p;
    }
    return(top);

    stack *pop(stack *top)
    {
        stack *p=NULL;
        p=top;
        printf("\nPoped node are: ");
        top=top->next;
        free(p);
        return(top);
    }

    void display(stack *top)
    {
        stack *p=NULL:
        p=top;
        while(p!=NULL
        {
            printf("%d",p->info)
        }
    }
}