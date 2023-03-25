#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

struct node *head;

void beg_insert()
{
    struct node *newnode;
    int item;
    newnode=malloc(sizeof(struct noe*));
    printf("Enter the element\n");
    scanf("%d",&item);

    newnode->data=item;
    newnode->next=head;
    head=newnode;

    printf("Node Inserted\n");
}

void last_insert()
{
    struct node *newnode, *temp;
    int item;
    newnode=malloc(sizeof(struct node*));

    printf("Enter the element \n");
    scanf("%d", &item);

    newnode->data = item;
    temp=head;

    if(temp==NULL)
    {
        newnode->next=NULL;
        head=newnode;
        printf("Node inserted\n");
    }
    else
    {
        while(temp->next!=NULL)
        {
            temp=temp->next;
        }
        temp->next=newnode;
        newnode->next=NULL;
        printf("Node Inserted\n");

    }
}

void random_insert()
{
    struct node *newnode, *temp;
    int pos, item;

    temp=head;

    newnode=malloc(sizeof(struct node*));
    printf("Enter the element\n");
    scanf("%d", &item);
    newnode->data=item;

    printf("Enter the location after which you want to insert the element\n");
    scanf("%d", &pos);

    while(pos!=1)
    {
        temp=temp->next;
        pos--;
    }
    if(temp==NULL)
    {
        printf("\nCan't be Insertd\n");
    }
    else
    {
        newnode->next=temp->next;
        temp->next=newnode;
    }

}

void beg_delete()
{
    if(head==NULL)
    {
        printf("\n Linked List is already empty \n");
    }
    else
    {
        struct node *temp;
        temp=head;
        head=head->next;
        free(temp);
        temp=NULL;
        printf("\n First node has been deleted successfully\n");
    }
}

void last_delete()
{
    if(head==NULL)
    {
        printf("\nList is already empty\n");
    }
    else if(head->next==NULL)
    {
        free(head);
        head=NULL;
    }
    else
    {
        struct node *temp1, *temp2;
        temp1=temp2=head;
        while(temp1->next!=NULL)
        {
            temp2=temp1;
            temp1=temp1->next;
        }
        temp2->next=NULL;
        free(temp1);
        temp1=NULL;
    }
}

void random_delete()
{
    struct node *temp1, *temp2;
    int i, pos;
    printf("\n Enter the position of the node after which you want to delete the node\n");
    scanf("%d",&pos);

    temp1=head;
    for(i=0;i<pos;i++)
    {
        temp2 = temp1;
        temp1 = temp1->next;

        if(temp1 == NULL)
        {
            printf("\nCan't delete");
            return;
        }
    }
    temp2 ->next = temp1 ->next;
    free(temp1);
    temp1=NULL;
    printf("\nDeleted node %d ",pos+1);
}

void del_list()
{
    struct node *temp = head;
    if(temp==NULL)
    {
        printf("\nLinked List is already empty\n");
    }
    else
    {
        while(temp!=NULL)
        {
            temp=temp->next;
            free(head);
            head=temp;
        }

        printf("\nComplete Linked List has been deleted successfully\n");
    }
}

void reverse()
{
    struct node *prev, *next;
    prev=next=NULL;
    while(head!=NULL)
    {
        next=head->next;
        head->next=prev;
        prev=head;
        head=next;
    }
    head=prev;
    printf("\nLinked list has been reversed successfully\nPress 7 to print reversed linked list\n");
}

void search()
{

    struct node *temp=head;
    int item, i=0, flag=0;
    if(temp==NULL)
    {
        printf("\nLinked List is Empty\n");
    }
    else
    {
        printf("\nEnter an element which you want to search: ");
        scanf("%d", &item);
        while(temp!=NULL)
        {
            if(temp->data==item)
            {
                printf("\nData found at the location %d\n", i+1);
                flag=1;
            }
            i++;
            temp=temp->next;
        }
        if(flag==0)
        {
            printf("\nItem not found in the linked list\n");
        }
    }

}

void display()
{
    struct node *temp;
    temp=head;
    if(temp==NULL)
    {
        printf("Linked List is Empty\n");
    }
    else
    {
        printf("\nPrinting data of the Linked List\n");
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

        printf("\nSelect an option from the table below which you want to perform\n");
        printf("\n1. Insert an element at beginning\n2. Insert an element at last\n3. Insert an element at random position\n4. Delete first element\n5. Delete Last element \n6. Delete at random position\n7. Display the elements\n8. Delete complete linked list\n9. Reverse the singly linked list\n10. Search an element from the linked list\n11. Exit \n\n");
        scanf("%d", &choice);

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
            beg_delete();
            break;

        case 5:
            last_delete();
            break;

        case 6:
            random_delete();
            break;

        case 7:
            display();
            break;

        case 8:
            del_list();
            break;

        case 9:
            reverse();
            break;

        case 10:
            search();
            break;

        case 11:
            printf("\n....Program End....\n");
            exit(0);
            break;

        default:
            printf("\nPlease enter a valid choice\n");
        }


    }

}
