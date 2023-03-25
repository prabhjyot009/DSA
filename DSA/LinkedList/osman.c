#include<stdio.h>
#include<stdlib.h>

typedef struct list
{
int info;
struct list*prev;
struct list*next;
}nodetype;

nodetype* insert(nodetype*);
void count(nodetype*);
void display(nodetype*);
int main()
{
int ch;
 nodetype *R=NULL,*L=NULL;
    do
    {
        printf("1 for insert,2 for count,3 for display,4for exit");
        scanf("%d",&ch);
            switch(ch)
            {
            case 1:
                 R=insert(R);
                   if(L==NULL)
                      L=R;
            break;
            case 2:
            if (L==NULL)
               printf("linklist is empty");
            else
               count(L);
            break;
            //case 3:
              // display(L);
        }
    }while(ch<3);
}
nodetype* insert(nodetype*R)
{
        nodetype*p;
      int x;
    p=(nodetype*)malloc(sizeof(nodetype)) ;

    if(p!=NULL)
    {
        printf("enter the value of x");
    scanf("%d",&x);

                p->info=x;

                if(R==NULL)
                   R=p;
                else
                {
                p->prev=R;
                R->next=p;
                R=p;
                }
    }
        return(R);
}

void count(nodetype *L)
{
   int  c=0;

while(L!=NULL)
{
  c++;
  L=L->next;
}
  printf("\n nodes are %d",c);
}




