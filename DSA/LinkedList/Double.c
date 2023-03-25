#include <stdio.h>
#include <stdlib.h>

struct node
{
    struct node *prev;
    int data;
    struct node *next;
};

struct node *head;

void beg_insert()
{
    int item;
    struct node *newnode;
    newnode = malloc(sizeof(struct node*));

    printf("\nEnter the element which you want to insert at the beginning of the list: ");
    scanf("%d",&item);

    newnode->data=item;

    if(head==NULL)
    {
        head=newnode;
        newnode->next=NULL;
        newnode->prev=NULL;
    }
    else
    {
        newnode->prev=NULL;
        newnode->next=head;
        head->prev=newnode;
        head=newnode;
    }

    printf("%d has been inserted Successfully at the beginning of the list\n", item);

}

void last_insert()
{
    int item;
    struct node *newnode, *temp;
    temp=head;
    newnode=malloc(sizeof(struct node*));
    printf("\nEnter the element which you want to insert at last of the list: ");
    scanf("%d", &item);
    newnode->data=item;

    if(head==NULL)
    {
        newnode->next=NULL;
        newnode->prev=NULL;
        head=newnode;
    }
    else
    {
        while(temp->next!=NULL)
        {
            temp=temp->next;
        }

        temp->next=newnode;
        newnode->prev=temp;
        newnode->next=NULL;
    }
    printf("%d has been inserted successfully at the last of the linked list\n", item);
}

void random_insert()
{
   struct node *newnode,*temp;
   int item,loc,i, pos;
   newnode = (struct node *)malloc(sizeof(struct node));

    temp=head;
    printf("\nEnter the location after which you want to insert the new element: ");
    scanf("%d",&loc);
    pos=loc;
    loc--;
    for(i=0;i<loc;i++)
    {
        temp = temp->next;
        if(temp == NULL)
        {
            printf("\nCan't insert the element because there are less than %d elements", pos);
            return;
        }
    }
    printf("\nEnter the value which you want to insert after %d position: ", pos);
    scanf("%d",&item);
    newnode->data = item;
    newnode->next = temp->next;
    newnode -> prev = temp;
    temp->next = newnode;
    temp->next->prev=newnode;
    printf("\n%d has been inserted successfully after %d position.\n", item, pos);

}

void del_beg()
{
    struct node *temp;
    if(head==NULL)
    {
        printf("\nLinked list is already empty\n");
    }
    else if(head->next==NULL)
    {
        free(head);
        head=NULL;
        printf("\nFirst node deleted successfully\n");
    }
    else
    {
        temp = head;
        head = head->next;
        head -> prev = NULL;
        free(temp);
        printf("\nFirst node deleted successfully\n");
    }
}

void last_del()
{
    struct node *temp, *temp2;
    if(head==NULL)
    {
        printf("\nLinked list is already empty\n");
    }
    else if(head->next==NULL)
    {
        free(head);
        head=NULL;
        printf("\nLast node deleted successfully\n");
    }
    else
    {
        temp=head;
        while(temp->next!=NULL)
        {
            temp=temp->next;
        }
        temp2=temp->prev;
        temp2->next=NULL;
        free(temp);
        printf("\nLast node has been deleted successfully\n");

    }
}

void random_delete()
{
    struct node *temp, *temp2, *temp3;
    int pos, i=1, count=0;
    temp=head;
    temp3=temp;
    while(temp3!=NULL)
    {
        temp3=temp3->next;
        count++;
    }


    if(head==NULL)
    {
        printf("\nLInked list is already empty\n");
        return;
    }
    else
    {
        printf("\nEnter the position which you want to delete: ");
        scanf("%d", &pos);

        if(pos>count)
        {
            printf("\nSorry, there are only %d elements\n", count);
            return;
        }

        if(pos==1)
        {
            head=head->next;
            if(head!=NULL)
            {
                head->prev=NULL;
            }
            free(temp);
            printf("Node at position %d deleted successfully\n", pos);
            return;
        }
        while(i<pos-1)
        {
            temp=temp->next;
            i++;
        }
        temp2=temp->next;

        if(temp2->next!=NULL)
        {
            temp2->next->prev=temp;
        }

        temp->next=temp2->next;
        free(temp2);
        printf("Node at position %d deleted successfully\n",pos);
    }
}



void count()
{
    struct node *temp;
    int count=0;
    temp=head;
    while(temp!=NULL)
    {
        temp=temp->next;
        count++;
    }
    printf("\nTotal numbers of elements are %d\n", count);
}

void display()
{
    struct node *temp;
    if(head==NULL)
    {
        printf("\nLinked List is Empty! Nothing to print.\n");
    }
    else
    {
        temp=head;
        printf("\n--------Printing elements of the Linked Lists--------\n");
        while(temp!=NULL)
        {
            printf("%d ",temp->data);
            temp=temp->next;
        }
        printf("\n");
    }
}


void main()
{
    int choice;
    while(choice!=11)
    {
        printf("\nSelect the option which you want to perform from following menu.\n");
        printf("1. Insert at beginning\n2. Insert at last\n3. Insert at random position\n4. Delete 1st element\n5. Delete last element\n6. Delete specified elements\n7. Count the no. of nodes\n8. Prints all elements\n9. Exit\n\n");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:
                beg_insert();
                break;

            case 2:
                last_insert();
                break;

            case 3:
                random_insert();
                break;

            case 4:
                del_beg();
                break;

            case 5:
                last_del();
                break;

            case 6:
                random_delete();
                break;

            case 7:
                count();
                break;

            case 8:
                display();
                break;

            case 9:
                exit(0);
                break;

            default:
                printf("\nPlease enter a valid choice\n");
                break;



        }


    }
}
