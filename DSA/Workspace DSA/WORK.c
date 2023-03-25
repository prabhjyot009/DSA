#include<stdio.h>
#include<stdlib.h>

typedef struct list
{
    struct list *prev;
    int info;
    struct list *next;
}nodetype;


void insert(nodetype **L,nodetype**R)
{
    int x;
    nodetype *p=NULL,*t=NULL;
    nodetype *p=(nodetype*)malloc(sizeof(nodetype));
    if(p!=NULL)
    {
        printf("Enter the numebr: ");
        scaf("%d",&x);
        p->info=x;
        if((*L)==NULL&&(*R)=NULL)
        {
            (*L)=(*R)=p;
            elseif(x<(*L)->info)
            {
                p->next=(*L);
                (*L)->prev=p;
                (*L)=P;
            }
            elseif(x>(*R)->info)
            {
                p->prev=(*R);
                (*R)->next=p;
                (*R)=p;
            }
        }
    }
}